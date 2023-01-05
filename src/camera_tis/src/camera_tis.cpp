// Copyright 2019 Zhushi Tech, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "camera_tis/camera_tis.hpp"

#include <gst/gst.h>
#include <gst/video/video.h>
#include <tcamprop.h>

// #include <exception>
#include <memory>
#include <utility>
#include <vector>

namespace camera_tis
{

using rcl_interfaces::msg::ParameterDescriptor;
using rcl_interfaces::msg::SetParametersResult;

/**
 * @brief Gstreamer pipeline.
 *
 * Raw image format, resolution and fps are defined here.
 * Then with videoscale plugin, it is scaled down to a lower resolution to reduce overall CPU usage.
 * The pipeline use appsink plugin to pass image date asynchronously.
 */
constexpr char PIPELINE_STR[] =
  "tcambin name=source"
  " ! video/x-raw,format=GRAY8,width=3072,height=2048,framerate=30/1"
  " ! videoscale"
  " ! video/x-raw,width=1536,height=1024"
  " ! appsink name=sink emit-signals=true sync=false drop=true max-buffers=4";

/**
 * @brief Set the property object for string.
 *
 * @param property The name of the property to set.
 * @param value The value of the property to set.
 * @return gboolean true if success.
 */
gboolean set_property(_GstElement * pipeline, const char * property, const char * value)
{
  gboolean ret = FALSE;
  GstElement * bin = gst_bin_get_by_name(GST_BIN(pipeline), "source");
  GValue val = G_VALUE_INIT;
  g_value_init(&val, G_TYPE_STRING);
  g_value_set_string(&val, value);
  ret = tcam_prop_set_tcam_property(TCAM_PROP(bin), property, &val);
  g_value_unset(&val);
  gst_object_unref(bin);
  return ret;
}

/**
 * @brief Set the property object for integer.
 *
 * @param property The name of the property to set.
 * @param value The value of the property to set.
 * @return gboolean true if success.
 */
gboolean set_property(_GstElement * pipeline, const char * property, int value)
{
  gboolean ret = FALSE;
  GstElement * bin = gst_bin_get_by_name(GST_BIN(pipeline), "source");
  GValue type = {};
  tcam_prop_get_tcam_property(
    TCAM_PROP(bin),
    property,
    NULL,
    NULL, NULL, NULL, NULL,
    &type, NULL, NULL, NULL);
  const char * t = g_value_get_string(&type);
  if (strcmp(t, "boolean") == 0) {
    GValue val = G_VALUE_INIT;
    g_value_init(&val, G_TYPE_BOOLEAN);
    g_value_set_boolean(&val, value);
    ret = tcam_prop_set_tcam_property(TCAM_PROP(bin), property, &val);
    g_value_unset(&val);
  } else {
    GValue val = G_VALUE_INIT;
    g_value_init(&val, G_TYPE_INT);
    g_value_set_int(&val, value);
    ret = tcam_prop_set_tcam_property(TCAM_PROP(bin), property, &val);
    g_value_unset(&val);
  }
  g_value_unset(&type);
  gst_object_unref(bin);
  return ret;
}

CameraTis::CameraTis(const rclcpp::NodeOptions & options)
: Node("camera_tis_node", options)
{
  /**
   * @brief Const expression for image size infomation.
   *
   */
  WIDTH = camdata.camer_size_width;
  HEIGHT = camdata.camer_size_height;
  SIZE = WIDTH * HEIGHT;
  FPS = camdata.camer_fps;
  VIEW_WIDTH = camdata.camer_size_view_width;
  VIEW_HEIGHT = camdata.camer_size_view_height;

//_param_imagepos = std::make_shared<rclcpp::AsyncParametersClient>(this, "laser_imagepos_node");
  _pub = this->create_publisher<Image>(_pub_name, rclcpp::SensorDataQoS());
  _initialize_camera();

  RCLCPP_INFO(this->get_logger(), "Initialized successfully");
}

CameraTis::~CameraTis()
{
  try {
  #ifdef SHOW_OUTPUT_FPS
    _threadmodbus.join();
  #endif
    _handle.reset();
    gst_element_set_state(_pipeline, GST_STATE_NULL);
    _thread.join();
    gst_object_unref(_pipeline);
    _pub.reset();

    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: unknown");
  }
}

void CameraTis::_declare_parameters()
{
//ParameterDescriptor pd;
//pd.read_only = true;
  this->declare_parameter("exposure_time", 1000);
  this->declare_parameter("width", WIDTH);
  this->declare_parameter("height", HEIGHT);
  this->declare_parameter("fps", FPS);
  this->declare_parameter("view_width", VIEW_WIDTH);
  this->declare_parameter("view_height", VIEW_HEIGHT);
  this->declare_parameter("power", false, ParameterDescriptor(), true);
}

void CameraTis::_initialize_camera()
{
#ifdef SHOW_OUTPUT_FPS
  b_modbusconnect=false;

  _threadmodbus = std::thread(&CameraTis::_modbus, this, 1502);
#endif

  _declare_parameters();

  gst_debug_set_default_threshold(GST_LEVEL_WARNING);
  gst_init(NULL, NULL);

  char newPIPELINE_STR[500];
  sprintf(newPIPELINE_STR,"tcambin name=source"
  " ! video/x-raw,format=GRAY8,width=%d,height=%d,framerate=%d/1"
  " ! videoscale"
  " ! video/x-raw,width=%d,height=%d"
  " ! appsink name=sink emit-signals=true sync=false drop=true max-buffers=4",VIEW_WIDTH,VIEW_HEIGHT,FPS,WIDTH,HEIGHT);

  _pipeline = gst_parse_launch(newPIPELINE_STR, NULL);
  if (_pipeline == NULL) {
    throw std::runtime_error("TIS parse launch fail");
  }

  // Disable auto exposure and auto gain, set brightness to 0
  
  set_property(_pipeline, "Exposure Auto", false);
  set_property(_pipeline, "Gain Auto", false);
  set_property(_pipeline, "Brightness", 0);

  auto e = this->get_parameter("exposure_time").as_int();
  if (_set_exposure(e)) {
    throw std::runtime_error("TIS set exposure fail");
  }
//_param_imagepos->set_parameters({rclcpp::Parameter("rember_exposure_time", e)});

  // Set pipeline state to pause before spin.
  gst_element_set_state(_pipeline, GST_STATE_PAUSED);
  // Spin infinitely until rclcpp::ok() return false which means termination.
  
  _thread = std::thread(&CameraTis::_spin, this);

  // ROS parameter callback handle.
 
  _handle = this->add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & parameters) {
      SetParametersResult result;
      result.successful = true;
      for (const auto & p : parameters) {
        if (p.get_name() == "exposure_time") {
          auto ret = this->_set_exposure(p.as_int());
          if (ret) {
            result.successful = false;
            result.reason = "Failed to set exposure time";
            return result;
          }
        } 
        else if (p.get_name() == "power") {
          auto ret = this->_set_power(p.as_bool());
          if (ret) {
            result.successful = false;
            result.reason = "Failed to set power";
            return result;
          }
        }    
        else if (p.get_name() == "width") {
          auto ret = this->_set_width(p.as_int());
          if (ret) {
            result.successful = false;
            result.reason = "Failed to set width";
            return result;
          }
        }
        else if (p.get_name() == "height") {
          auto ret = this->_set_height(p.as_int());
          if (ret) {
            result.successful = false;
            result.reason = "Failed to set height";
            return result;
          }
        }
        else if (p.get_name() == "fps") {
          auto ret = this->_set_fps(p.as_int());
          if (ret) {
            result.successful = false;
            result.reason = "Failed to set fps";
            return result;
          }
        }
        else if (p.get_name() == "view_width") {
          auto ret = this->_set_view_width(p.as_int());
          if (ret) {
            result.successful = false;
            result.reason = "Failed to set view_width";
            return result;
          }
        }
        else if (p.get_name() == "view_height") {
          auto ret = this->_set_view_height(p.as_int());
          if (ret) {
            result.successful = false;
            result.reason = "Failed to set view_height";
            return result;
          }
        }
      }
      return result;
    }
  );
}

#ifdef SHOW_OUTPUT_FPS
void CameraTis::_modbus(int port)
{
  while (rclcpp::ok()) 
  {
    ctx = modbus_new_tcp(NULL, 1502);
    if (!ctx) {
      RCLCPP_ERROR(this->get_logger(), "Failed to create modbus camfps.");
      rclcpp::shutdown();
      return;
    }
    if (modbus_connect(ctx) == -1)
    {
      modbus_free(ctx);
      usleep(5);
      continue;
    }
    RCLCPP_INFO(this->get_logger(), "connect modbus camfps succeed.");
    b_modbusconnect=true;
    break;
  }
}
#endif

void CameraTis::_spin()
{
  GstElement * sink = gst_bin_get_by_name(GST_BIN(_pipeline), "sink");
  int frame = 0;
  while (rclcpp::ok()) {
    GstSample * sample = NULL;
    g_signal_emit_by_name(sink, "pull-sample", &sample, NULL);
    if (sample == NULL) {
      continue;
    }
    GstBuffer * buffer = gst_sample_get_buffer(sample);
    if (buffer == NULL) {
      gst_sample_unref(sample);
      continue;
    }

    // Construct a ROS image to publish.
    GstMapInfo info;
    if (gst_buffer_map(buffer, &info, GST_MAP_READ)) {
      auto ptr = std::make_unique<Image>();
      ptr->header.stamp = this->now();
      ptr->header.frame_id = std::to_string(frame++);
      ptr->height = HEIGHT;
      ptr->width = WIDTH;
      ptr->encoding = "mono8";
      ptr->is_bigendian = false;
      ptr->step = WIDTH;
      ptr->data.resize(SIZE);
      memcpy(ptr->data.data(), info.data, SIZE);

    #ifdef SHOW_OUTPUT_FPS
      if(b_modbusconnect==true)
      {
          static bool b_timest=0;
          static auto timest_fps=ptr->header.stamp;
          auto timeed_fps=ptr->header.stamp;
          if(b_timest==0)
          {
            b_timest=1;
            timest_fps=ptr->header.stamp;
          }
          else
          {
            timeed_fps=ptr->header.stamp;
            double timest=(double)timest_fps.sec+(double)timest_fps.nanosec/1000000000;
            double timeed=(double)timeed_fps.sec+(double)timeed_fps.nanosec/1000000000;
            double time=timeed-timest;
            int fps=(int)((double)1.0/time*100.0);
            u_int16_t tab_reg[1];
            tab_reg[0]=(u_int16_t)fps;
            int rc=modbus_write_registers(ctx,0x0c,1,tab_reg);
            if(rc!=1)
            {
              RCLCPP_INFO(this->get_logger(), "Failed to send modbus camfps.");
            }
            timest_fps=timeed_fps;
          }
      }
    #endif
      if(b_modbusconnect==true)
      {
          auto stamp = ptr->header.stamp;
          time_t t;
          u_int16_t msec = ptr->header.stamp.nanosec/1000000;
          struct tm *p;
          t=stamp.sec;
          p=gmtime(&t);  
          u_int16_t tab_reg[4];
          tab_reg[0]=(p->tm_hour+8)%24;
          tab_reg[1]=p->tm_min;
          tab_reg[2]=p->tm_sec;
          tab_reg[3]=msec;
          int rc=modbus_write_registers(ctx,0x0d,4,tab_reg);
      }
      _pub->publish(std::move(ptr));
      gst_buffer_unmap(buffer, &info);

    }
    gst_sample_unref(sample);
  }
  gst_object_unref(sink);
}

bool CameraTis::_power()
{
  return this->get_parameter("power").as_bool();
}

int CameraTis::_power_on()
{
  if (_power() == false) {
    if (gst_element_set_state(_pipeline, GST_STATE_PLAYING) == GST_STATE_CHANGE_FAILURE) {
      return 1;
    }
  }

  return 0;
}

int CameraTis::_power_off()
{
  if (_power()) {
    if (gst_element_set_state(_pipeline, GST_STATE_PAUSED) == GST_STATE_CHANGE_FAILURE) {
      return 1;
    }
  }

  return 0;
}

int CameraTis::_set_power(bool p)
{
  return p ? _power_on() : _power_off();
}

int CameraTis::_set_exposure(int e)
{
  return set_property(_pipeline, "Exposure Time (us)", e) ? 0 : 1;
}

int CameraTis::_set_width(int width)
{
  if(width<(int)camdata.camer_size_width_min||width>(int)camdata.camer_size_width_max)
  { 
    return 1;
  }
  else
  {
    camdata.camer_size_width=width;
    camdata.write_camer_para();
  }
  return 0;
}

int CameraTis::_set_height(int height)
{
  if(height<(int)camdata.camer_size_height_min||height>(int)camdata.camer_size_height_max)
  { 
    return 1;
  }
  else
  {
    camdata.camer_size_height=height;
    camdata.write_camer_para();
  }
  return 0;
}

int CameraTis::_set_view_width(int width)
{
  if(width<(int)camdata.camer_size_view_width_min||width>(int)camdata.camer_size_view_width_max)
  { 
    return 1;
  }
  else
  {
    camdata.camer_size_view_width=width;
    camdata.write_camer_para();
  }
  return 0;
}

int CameraTis::_set_view_height(int height)
{
  if(height<(int)camdata.camer_size_view_height_min||height>(int)camdata.camer_size_view_height_max)
  { 
    return 1;
  }
  else
  {
    camdata.camer_size_view_height=height;
    camdata.write_camer_para();
  }
  return 0;
}

int CameraTis::_set_fps(int fps)
{
  if(fps<(int)camdata.camer_fps_min||fps>(int)camdata.camer_fps_max)
  { 
    return 1;
  }
  else
  {
    camdata.camer_fps=fps;
    camdata.write_camer_para();
  }
  return 0;
}

}  // namespace camera_tis

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(camera_tis::CameraTis)
