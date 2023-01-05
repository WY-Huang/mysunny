#include "camera_test/camera_test.hpp"

#include <cstdio>

namespace camera_test
{
using namespace std::chrono_literals;

using rcl_interfaces::msg::ParameterDescriptor;
using rcl_interfaces::msg::SetParametersResult;

void timer_callback()
{ 
  if(!pThis->cv_image.empty())
  {
    sensor_msgs::msg::Image::UniquePtr image_msg(new sensor_msgs::msg::Image());
    auto stamp = pThis->now();
    image_msg->header.stamp = stamp;
    image_msg->header.frame_id = "my_eyesId";
    image_msg->height = pThis->cv_image.rows;
    image_msg->width = pThis->cv_image.cols;
    image_msg->encoding = pThis->mat_type2encoding(pThis->cv_image.type());
    image_msg->is_bigendian = false;
    image_msg->step = static_cast<sensor_msgs::msg::Image::_step_type>(pThis->cv_image.step);
    image_msg->data.assign(pThis->cv_image.datastart, pThis->cv_image.dataend);

#ifdef SHOW_OUTPUT_FPS
    if(pThis->b_modbusconnect==true)
    {
        static bool b_timest=0;
        static auto timest_fps=image_msg->header.stamp;
        auto timeed_fps=image_msg->header.stamp;
        if(b_timest==0)
        {
          b_timest=1;
          timest_fps=image_msg->header.stamp;
        }
        else
        {
          timeed_fps=image_msg->header.stamp;
          double timest=(double)timest_fps.sec+(double)timest_fps.nanosec/1000000000;
          double timeed=(double)timeed_fps.sec+(double)timeed_fps.nanosec/1000000000;
          double time=timeed-timest;
          int fps=(int)((double)1.0/time*100.0);
          u_int16_t tab_reg[1];
          tab_reg[0]=(u_int16_t)fps;
          int rc=modbus_write_registers(pThis->ctx,0x0c,1,tab_reg);
          timest_fps=timeed_fps;
        }
    }
    /*
    static int32_t totel_fps=0;
    static int32_t output_num=0;
    static auto timest_fps=ptr->header.stamp;
    totel_fps++;
    auto timeed_fps=ptr->header.stamp;
    if(output_num==200)
    {
        output_num=0;
        double timest=(double)timest_fps.sec+timest_fps.nanosec/0.000000001;
        double timeed=(double)timeed_fps.sec+timeed_fps.nanosec/0.000000001;
        double time=timeed-timest;
        double fps=(double)totel_fps/time;
        printf("Cam_fps:%0.3lf",fps);
    }
    output_num++;
    */
  #endif

    if(pThis->b_modbusconnect==true)
    {
        auto stamp = image_msg->header.stamp;
        time_t t;
        u_int16_t msec = image_msg->header.stamp.nanosec/1000000;
        struct tm *p;
        t=stamp.sec;
        p=gmtime(&t);  
        u_int16_t tab_reg[4];
        tab_reg[0]=(p->tm_hour+8)%24;
        tab_reg[1]=p->tm_min;
        tab_reg[2]=p->tm_sec;
        tab_reg[3]=msec;
        int rc=modbus_write_registers(pThis->ctx,0x0d,4,tab_reg);
    }

    pThis->_pub->publish(std::move(image_msg));

  
  }
}

CameraTest::CameraTest(const rclcpp::NodeOptions & options)
: Node("camera_tis_node", options)
{
#ifdef SHOW_OUTPUT_FPS
  b_modbusconnect=false;

  _threadmodbus = std::thread(&CameraTest::_modbus, this, 1502);
#endif

  int WIDTH=1536,HEIGHT=1024,FPS=40,exposure_time=1000,VIEW_WIDTH=3072,VIEW_HEIGHT=2048;
  this->declare_parameter("width", WIDTH);
  this->declare_parameter("height", HEIGHT);
  this->declare_parameter("fps", FPS);
  this->declare_parameter("exposure_time", exposure_time);
  this->declare_parameter("view_width", VIEW_WIDTH);
  this->declare_parameter("view_height", VIEW_HEIGHT);

  pThis=this;
  _pub = this->create_publisher<Image>(_pub_name, rclcpp::SensorDataQoS());
  timer_ = this->create_wall_timer(25ms, std::bind(&camera_test::timer_callback));
  cv_image = cv::imread("/home/qubo/mysunny/src/camera_test/bmp/test.bmp");
//cv_image = cv::imread("/workspace/sunny/install/camera_test/share/camera_test/bmp/test.bmp");
  cv::cvtColor(cv_image, cv_image, cv::COLOR_BGR2GRAY);

  RCLCPP_INFO(this->get_logger(), "Initialized successfully");
}

CameraTest::~CameraTest()
{
  try {
  #ifdef SHOW_OUTPUT_FPS
    _threadmodbus.join();
  #endif
    _pub.reset();

    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: unknown");
  }
}

#ifdef SHOW_OUTPUT_FPS
void CameraTest::_modbus(int port)
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

std::string CameraTest::mat_type2encoding(int mat_type)
{
  switch (mat_type) {
    case CV_8UC1:
      return "mono8";
    case CV_8UC3:
      return "bgr8";
    case CV_16SC1:
      return "mono16";
    case CV_8UC4:
      return "rgba8";
    default:
      throw std::runtime_error("unsupported encoding type");
  }
}

}


#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(camera_test::CameraTest)