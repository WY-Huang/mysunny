#include "laser_imagepos/laser_imagepos.hpp"
#include <cstdio>

#include "opencv2/opencv.hpp"

namespace laser_imagepos
{

using rcl_interfaces::msg::SetParametersResult;

int workers(const rclcpp::NodeOptions & options)
{
  for (const auto & p : options.parameter_overrides()) {
    if (p.get_name() == "workers") {
      return p.as_int();
    }
  }
  return 1;
}

LaserImagePos::LaserImagePos(const rclcpp::NodeOptions & options)
: Node("laser_imagepos_node", options)
{
  _param_camera = std::make_shared<rclcpp::AsyncParametersClient>(this, "camera_tis_node");
  
  _declare_parameters();

  pm = _update_parameters();

  _pub = this->create_publisher<IfAlgorhmitmsg>(_pub_name, rclcpp::SensorDataQoS());


  //_workers = workers(options);
  _workers=1;
  
  for (int i = 0; i < _workers; ++i) {
    _threads.push_back(std::thread(&LaserImagePos::_worker, this));
  }
  _threads.push_back(std::thread(&LaserImagePos::_manager, this));

  _sub = this->create_subscription<Image>(
    _sub_name,
    rclcpp::SensorDataQoS(),
    [this](Image::UniquePtr ptr)
    {
      _push_back_image(std::move(ptr));
    }
  );

  _handle = this->add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & vp) {
      SetParametersResult result;
      int alg_return;
      result.successful = true;
      for (const auto & p : vp) {
        if (p.get_name() == "task_num") 
        {
          if (p.as_int() < 0) {
            result.successful = false;
            result.reason = "Failed to set task_num";
            return result;
          }
          else
          {
            pm.task_num=p.as_int();
            if(pm.task_num>=100&&pm.task_num<200)
            {
              switch(pm.task_num)
              {
                case 100:
                  _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als100_exposure_time)});
                break;
                case 101:
                  _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als101_exposure_time)});
                break;
                case 102:
                  _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als102_exposure_time)});
                break;
                case 103:
                  _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als103_exposure_time)});
                break;
                case 104:
                  _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als104_exposure_time)});
                break;
                defatult:
                break;
              }
            }
          }
        }
        else if(p.get_name() == "show_step")
        {
          if (p.as_int() < 0) {
            result.successful = false;
            result.reason = "Failed to set show_step";
            return result;
          }
          else
          {
            pm.show_step=p.as_int();
          }
        }
        else if(p.get_name() == "start")
        {
          if (p.as_int() < 0) {
            result.successful = false;
            result.reason = "Failed to set start";
            return result;
          }
          else if(p.as_int() > 0)
          {
            InitRunImage();
          }
        }
        else if(alg_return=alg100_getcallbackParameter(p)!=0)
        {
          if(alg_return<0)
          {
            result.successful = false;
            result.reason = "Failed to set alg100_Parameter";
            return result;
          }
        }
        else if(alg_return=alg101_getcallbackParameter(p)!=0)
        {
          if(alg_return<0)
          {
            result.successful = false;
            result.reason = "Failed to set alg101_Parameter";
            return result;
          }
        }
        else if(alg_return=alg102_getcallbackParameter(p)!=0)
        {
          if(alg_return<0)
          {
            result.successful = false;
            result.reason = "Failed to set alg102_Parameter";
            return result;
          }
        }
        else if(alg_return=alg103_getcallbackParameter(p)!=0)
        {
          if(alg_return<0)
          {
            result.successful = false;
            result.reason = "Failed to set alg103_Parameter";
            return result;
          }
        }
        else if(alg_return=alg104_getcallbackParameter(p)!=0)
        {
          if(alg_return<0)
          {
            result.successful = false;
            result.reason = "Failed to set alg104_Parameter";
            return result;
          }
        }
      }
      return result;
    }
  );

  RCLCPP_INFO(this->get_logger(), "Ininitialized successfully");
}

LaserImagePos::~LaserImagePos()
{
  try {
    _sub.reset();
    _handle.reset();
    _param_camera.reset();
    _images_con.notify_all();
    _futures_con.notify_one();
    for (auto & t : _threads) {
      t.join();
    }
    _pub.reset();

    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: unknown");
  }
}

void LaserImagePos::_declare_parameters()
{
  alg100_declare_parameters();
  alg101_declare_parameters();
  alg102_declare_parameters();
  alg103_declare_parameters();
  alg104_declare_parameters();
  this->declare_parameter("task_num", pm.task_num);
  this->declare_parameter("show_step", pm.show_step);
  this->declare_parameter("start", 0);
  RCLCPP_INFO(this->get_logger(), "pmtask=%d",pm.task_num);
}

Params LaserImagePos::_update_parameters()
{
  const auto & vp = this->get_parameters(KEYS);
  for (const auto & p : vp) {
    if (p.get_name() == "task_num") {
      pm.task_num = p.as_int();
    }
    else if(p.get_name() == "show_step") {
      pm.show_step = p.as_int();
    }
  }
  alg100_update_parameters();
  alg101_update_parameters();
  alg102_update_parameters();
  alg103_update_parameters();
  alg104_update_parameters();
  return pm;
}

void LaserImagePos::InitRunImage()
{
  firstsearch=0;
  firstsearch_stx=0,
  firstsearch_sty=0,
  firstsearch_edx=0,
  firstsearch_edy=0;
  jishuST_x=0;
  jishuST_y=0;
  jishuED_x=0;
  jishuED_y=0;
  jishuNum=0;
  firstdimian=0;
  fuzhuxielv=0;
  b_fuzhuxielv=0;
  jishuxielv=0;
}

int LaserImagePos::RunImage(cv::Mat &imageIn,                        //输入图像
                            std::vector <cv::Point2f> &pointcloud,   //输出激光轮廓
                            std::vector <cv::Point2f> &namepoint,
                            bool &solderjoints,//是否焊点
                            int step)    //输出结果点信息
{
  static int oldwidth=0,oldHeight=0;

  if(oldwidth!=imageIn.cols||oldHeight!=imageIn.rows)
  {
    if(oldwidth!=0||oldHeight!=0)
    {
      Myhalcv2::MyhalcvMemFree();
      delete [] cv8uc1_Imagebuff_image;
      delete [] cv8uc1_Imagebuff1;
      delete [] cv8uc1_Imagebuff2;
      delete [] cv8uc1_Imagebuff3;
      delete [] cv8uc1_Imagebuff4;
      delete [] cv8uc1_Imagebuff5;
      delete [] cv8uc1_Imagebuff6;
      delete [] cv8uc1_Imagebuff7;
      delete [] cv8uc1_Imagebuff8;
      delete [] X_line;
      delete [] X_lineMark;
      delete [] X_linedif32;
      delete [] niheX;
      delete [] niheY;
      delete [] f_line;
    }
    oldwidth=imageIn.cols;
    oldHeight=imageIn.rows;
    Myhalcv2::MyhalcvMemInit(oldHeight,oldwidth);

    cv8uc1_Imagebuff_image=new char [oldwidth*oldHeight*4];
    cv8uc1_Imagebuff1=new char [oldwidth*oldHeight];
    cv8uc1_Imagebuff2=new char [Myhalcv2::getHoughsize()];
    cv8uc1_Imagebuff3=new char [Myhalcv2::getConectsize()*oldwidth*oldHeight];
    cv8uc1_Imagebuff4=new char [oldwidth*oldHeight];
    cv8uc1_Imagebuff5=new char [oldwidth*oldHeight];
    cv8uc1_Imagebuff6=new char [oldwidth*oldHeight*2];
    cv8uc1_Imagebuff7=new char [oldwidth*oldHeight];
    cv8uc1_Imagebuff8=new char [oldwidth*oldHeight];

    Int32 bigsize;
    bigsize=oldwidth>oldHeight?oldwidth:oldHeight;
    X_line=new Int32 [bigsize];
    f_line=new float [bigsize];
    X_lineMark=new Uint8 [bigsize*4];
    X_linedif32=new Int32 [bigsize];
    niheX=new Int32 [bigsize];
    niheY=new Int32 [bigsize];
    RCLCPP_INFO(this->get_logger(), "Image size changed");
  }

  switch(pm.task_num)
  {
    case 100:   //内角1算法
      if(0!=alg100_runimage(imageIn,pointcloud,namepoint,solderjoints,step))
        return 1;
    break;
    case 101:   //外角2算法
      if(0!=alg101_runimage(imageIn,pointcloud,namepoint,solderjoints,step))
        return 1;
    break;
    case 102:   //小波纹板算法
      if(0!=alg102_runimage(imageIn,pointcloud,namepoint,solderjoints,step))
        return 1;
    break;
    case 103:   //轮廓算法
      if(0!=alg103_runimage(imageIn,pointcloud,namepoint,solderjoints,step))
        return 1;
    break;
    case 104:   //小波纹板算法测试
      if(0!=alg104_runimage(imageIn,pointcloud,namepoint,solderjoints,step))
        return 1;
    break;
    default:
      return 1;
  }

  return 0;
}

std::string LaserImagePos::mat_type2encoding(int mat_type)
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

IfAlgorhmitmsg::UniquePtr LaserImagePos::execute(Image::UniquePtr ptr, cv::Mat & buf, const Params & pm)
{
  if (ptr->header.frame_id == "-1" || ptr->data.empty()) {
    auto result = std::make_unique<IfAlgorhmitmsg>();
    result->imageout.header = ptr->header;
    result->result=false;
    return result;
  }
  auto result = std::make_unique<IfAlgorhmitmsg>();
  cv::Mat img(ptr->height, ptr->width, CV_8UC1, ptr->data.data());
  std::vector <cv::Point2f> pointcloud,resultpoint;
  bool solderjoints;
  if(0!=RunImage(img,pointcloud,resultpoint,solderjoints,pm.show_step))
  {
    result->result=false;
  }
  else
  {
    result->result=true;
  }

  result->imageout.header = ptr->header;
  result->imageout.height = img.rows;
  result->imageout.width = img.cols;
  result->imageout.encoding = mat_type2encoding(img.type());
  result->imageout.is_bigendian = false;
  result->imageout.step = static_cast<sensor_msgs::msg::Image::_step_type>(img.step);
  result->imageout.data.assign(img.datastart, img.dataend);
  for(int n=0;n<pointcloud.size();n++)
  {
    tutorial_interfaces::msg::IfAlgorhmitpoint2f Ifpointcloud;
    Ifpointcloud.x=pointcloud[n].x;
    Ifpointcloud.y=pointcloud[n].y;
    result->lasertrackout.push_back(Ifpointcloud);
  }
  for(int n=0;n<resultpoint.size();n++)
  {
    tutorial_interfaces::msg::IfAlgorhmittargetpoint2f pointtarget;
    char str[20];
    sprintf(str,"point_%d",n);
    pointtarget.name=str;
    pointtarget.x=resultpoint[n].x;
    pointtarget.y=resultpoint[n].y;
    result->targetpointout.push_back(pointtarget);
  }
  result->solderjoints=solderjoints;
  
  return result;
}

void LaserImagePos::_worker()
{
  cv::Mat buf;
  while (rclcpp::ok()) 
  {
    if(pm.task_num>=100&&pm.task_num<200)
    {
      std::unique_lock<std::mutex> lk(_images_mut);
      if (_images.empty() == false) 
      {
          auto ptr = std::move(_images.front());
          _images.pop_front();
          std::promise<IfAlgorhmitmsg::UniquePtr> prom;
          _push_back_future(prom.get_future());
          lk.unlock();
          auto line = execute(std::move(ptr), buf, pm);
          prom.set_value(std::move(line));
      } 
      else 
      {
        _images_con.wait(lk);
      }
    }
    sleep(0);
  }
}


void LaserImagePos::_manager()
{
  while (rclcpp::ok()) 
  {
    if(pm.task_num>=100&&pm.task_num<200)
    {
      std::unique_lock<std::mutex> lk(_futures_mut);
      if (_futures.empty() == false) 
      {
        auto f = std::move(_futures.front());
        _futures.pop_front();
        lk.unlock();
        
        auto ptr = f.get();
        _pub->publish(std::move(ptr));
      } 
      else 
      {
        _futures_con.wait(lk);
      }
    }
    sleep(0);
  }
}

void LaserImagePos::_push_back_image(Image::UniquePtr ptr)
{
  std::unique_lock<std::mutex> lk(_images_mut);
  _images.emplace_back(std::move(ptr));
  auto s = static_cast<int>(_images.size());
  if (s > _workers + 1) {
    _images.pop_front();
  }
  lk.unlock();
  _images_con.notify_all();
}

void LaserImagePos::_push_back_future(std::future<IfAlgorhmitmsg::UniquePtr> fut)
{
  std::unique_lock<std::mutex> lk(_futures_mut);
  _futures.emplace_back(std::move(fut));
  lk.unlock();
  _futures_con.notify_one();
}

}


#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(laser_imagepos::LaserImagePos)