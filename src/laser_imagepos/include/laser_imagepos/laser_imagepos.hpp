#ifndef LASER_LINE_IMAGEPOS__LASER_LINE_IMAGEPOS_HPP_
#define LASER_LINE_IMAGEPOS__LASER_LINE_IMAGEPOS_HPP_

#include <deque>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "tutorial_interfaces/msg/if_algorhmitmsg.hpp"
#include "myhalcv2/myhalcv2.h"
#include "unistd.h"
#include <time.h>

//#define DEBUG_ALG       //输出算法步骤
#define QUICK_TRANSMIT    //快速传输

#define E2POOM_ALG102_LASERIMAGEPOS_DIMIANPINGJUNSHUNUM_MAX         500

namespace laser_imagepos
{

using sensor_msgs::msg::Image;
using sensor_msgs::msg::PointCloud2;
using tutorial_interfaces::msg::IfAlgorhmitmsg;

const std::vector<std::string> KEYS = {"task_num","show_step","start"};

const std::vector<std::string> KEYS_ALS100 = {"als100_exposure_time",
                                              "als100_pingjun",
                                              "als100_b_yanmofuzhu",
                                              "als100_b_gudingquyu",
                                              "als100_widthliantongdis",
                                              "als100_highliantongdis",
                                              "als100_gujiaerzhi",
                                              "als100_jiguanghight",
                                              "als100_jiguanglong",
                                              "als100_jiguangkuandu",
                                              "als100_Updif",
                                              "als100_Updifmin",
                                              "als100_Uplong",
                                              "als100_Downdif",
                                              "als100_Downdifmin",
                                              "als100_Downdlong",
                                              "als100_duanxianerzhi",
                                              "als100_erzhisize",
                                              "als100_erzhisize2",
                                              "als100_searchdectancemax",
                                              "als100_searchdectancemin",
                                              "als100_dis_center_st",
                                              "als100_dis_center_ed"};

const std::vector<std::string> KEYS_ALS101 = {"als101_exposure_time",
                                              "als101_pingjun",
                                              "als101_b_yanmofuzhu",
                                              "als101_b_gudingquyu",
                                              "als101_widthliantongdis",
                                              "als101_highliantongdis",
                                              "als101_gujiaerzhi",
                                              "als101_jiguanghight",
                                              "als101_jiguanglong",
                                              "als101_jiguangkuandu",
                                              "als101_Updif",
                                              "als101_Updifmin",
                                              "als101_Uplong",
                                              "als101_Downdif",
                                              "als101_Downdifmin",
                                              "als101_Downdlong",
                                              "als101_duanxianerzhi",
                                              "als101_erzhisize",
                                              "als101_erzhisize2",
                                              "als101_searchdectancemax",
                                              "als101_searchdectancemin",
                                              "als101_dis_center_st",
                                              "als101_dis_center_ed"};

const std::vector<std::string> KEYS_ALS102 = {"als102_exposure_time",
                                              "als102_pingjun",
                                              "als102_b_yanmofuzhu",
                                              "als102_b_gudingquyu",
                                              "als102_widthliantongdis",
                                              "als102_highliantongdis",
                                              "als102_gujiaerzhi",
                                              "als102_jiguanghight",
                                              "als102_jiguanglong",
                                              "als102_jiguangkuandu",
                                              "als102_Updif",
                                              "als102_Updifmin",
                                              "als102_Uplong",
                                              "als102_Downdif",
                                              "als102_Downdifmin",
                                              "als102_Downdlong",
                                              "als102_St_Down",
                                              "als102_Ed_Down",
                                              "als102_St_Up",
                                              "als102_Ed_Up",
                                              "als102_Updif2",
                                              "als102_Updifmin2",
                                              "als102_dis_center_st",
                                              "als102_dis_center_ed",
                                              "als102_b_opengudingdimian",
                                              "als102_dimianpangdingjuli",
                                              "als102_dimianpingjunshunum",
                                              "als102_dis_center_st2",
                                              "als102_dis_center_ed2",
                                              "als102_dis_center_st3",
                                              "als102_dis_center_ed3",
                                              "als102_xuexijuli",
                                              "als102_b_pingpowending",
                                              "als102_pingpowending_dis",
                                              "als102_b_xielvopen",
                                              "als102_xielvfanwei",
                                              "als102_Uplong2",
                                              "als102_cebankongdongdis",
                                              "als102_qiatouquweijuli"};

const std::vector<std::string> KEYS_ALS103 = {"als103_exposure_time",
                                              "als103_pingjun",
                                              "als103_gujiaerzhi",
                                              "als103_widthliantongdis",
                                              "als103_highliantongdis",
                                              "als103_jiguanglong",
                                              "als103_jiguangkuandu",
                                              "als103_jiguangduibidu"};

const std::vector<std::string> KEYS_ALS104 = {"als104_exposure_time",
                                              "als104_pingjun",
                                              "als104_b_yanmofuzhu",
                                              "als104_b_gudingquyu",
                                              "als104_widthliantongdis",
                                              "als104_highliantongdis",
                                              "als104_gujiaerzhi",
                                              "als104_jiguanghight",
                                              "als104_jiguanglong",
                                              "als104_jiguangkuandu",
                                              "als104_Updif",
                                              "als104_Updifmin",
                                              "als104_Uplong",
                                              "als104_Downdif",
                                              "als104_Downdifmin",
                                              "als104_Downdlong",
                                              "als104_St_Down",
                                              "als104_Ed_Down",
                                              "als104_St_Up",
                                              "als104_Ed_Up",
                                              "als104_Updif2",
                                              "als104_Updifmin2",
                                              "als104_dis_center_st",
                                              "als104_dis_center_ed",
                                              "als104_b_opengudingdimian",
                                              "als104_dimianpangdingjuli",
                                              "als104_dimianpingjunshunum",
                                              "als104_dis_center_st2",
                                              "als104_dis_center_ed2",
                                              "als104_dis_center_st3",
                                              "als104_dis_center_ed3",
                                              "als104_xuexijuli",
                                              "als104_b_pingpowending",
                                              "als104_pingpowending_dis",
                                              "als104_b_xielvopen",
                                              "als104_xielvfanwei",
                                              "als104_Uplong2",
                                              "als104_cebankongdongdis",
                                              "als104_qiatouquweijuli"};

/**
 * @brief To zip related parameters together.
 *
 */
struct Params
{
/********************************/
//算法100参数
  int als100_exposure_time = 10000;//曝光值
  int als100_pingjun = 15;  //二值阈值
  int als100_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als100_b_gudingquyu=0;//是否固定区域
  int als100_widthliantongdis=2;//激光宽度连通距离
  int als100_highliantongdis=15;//激光长度连通距离
  int als100_gujiaerzhi=160;//找骨架二值图
  int als100_jiguanghight=50;//整体激光最短长度
  int als100_jiguanglong=20;//单边激光最短长度
  int als100_jiguangkuandu=4;//激光粗细
  int als100_Updif=0;//上半段倾斜开始斜度10
  int als100_Updifmin=-5;//上半段倾斜终止斜度10
  int als100_Uplong=5;//上半段直线长度
  int als100_Downdif=0;//下半段倾斜开始斜度0
  int als100_Downdifmin=5;//下半段倾斜终止斜度0
  int als100_Downdlong=5;//下半段直线长度
  int als100_duanxianerzhi=180;//找断线的二值阈值
  int als100_erzhisize=150;//断线二值图的上下阈值尺寸
  int als100_erzhisize2=60;//断线二值图的左右阈值尺寸
  int als100_searchdectancemax=160;//搜寻焊缝端点距离中央凹槽最远的距离
  int als100_searchdectancemin=25;//搜寻焊缝端点距离中央凹槽最近的距离
  int als100_dis_center_st=0;//距离中心点此处后开始统计
  int als100_dis_center_ed=500;  //距离中心点此处后停止统计
/************************************/
//算法101参数
  int als101_exposure_time = 10000;//曝光值
  int als101_pingjun = 15;  //二值阈值
  int als101_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als101_b_gudingquyu=0;//是否固定区域
  int als101_widthliantongdis=2;//激光宽度连通距离
  int als101_highliantongdis=15;//激光长度连通距离
  int als101_gujiaerzhi=160;//找骨架二值图
  int als101_jiguanghight=50;//整体激光最短长度
  int als101_jiguanglong=20;//单边激光最短长度
  int als101_jiguangkuandu=4;//激光粗细
  int als101_Updif=0;//上半段倾斜开始斜度10
  int als101_Updifmin=-5;//上半段倾斜终止斜度10
  int als101_Uplong=5;//上半段直线长度
  int als101_Downdif=0;//下半段倾斜开始斜度0
  int als101_Downdifmin=5;//下半段倾斜终止斜度0
  int als101_Downdlong=5;//下半段直线长度
  int als101_duanxianerzhi=180;//找断线的二值阈值
  int als101_erzhisize=150;//断线二值图的上下阈值尺寸
  int als101_erzhisize2=60;//断线二值图的左右阈值尺寸
  int als101_searchdectancemax=160;//搜寻焊缝端点距离中央凹槽最远的距离
  int als101_searchdectancemin=25;//搜寻焊缝端点距离中央凹槽最近的距离
  int als101_dis_center_st=0;//距离中心点此处后开始统计
  int als101_dis_center_ed=500;  //距离中心点此处后停止统计
/************************************/
//算法102参数
  int als102_exposure_time = 10000;//曝光值
  int als102_pingjun = 15;  //二值阈值
  int als102_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als102_b_gudingquyu=0;//是否固定区域
  int als102_widthliantongdis=2;//激光宽度连通距离
  int als102_highliantongdis=15;//激光长度连通距离
  int als102_gujiaerzhi=160;//找骨架二值图
  int als102_jiguanghight=50;//整体激光最短长度
  int als102_jiguanglong=20;//单边激光最短长度
  int als102_jiguangkuandu=4;//激光粗细
  int als102_Updif=0;//上半段倾斜开始斜度10
  int als102_Updifmin=-5;//上半段倾斜终止斜度10
  int als102_Uplong=5;//上半段直线长度
  int als102_Downdif=0;//下半段倾斜开始斜度0
  int als102_Downdifmin=5;//下半段倾斜终止斜度0
  int als102_Downdlong=5;//下半段直线长度
  int als102_St_Down=5;//下半段拟合起点
  int als102_Ed_Down=50;//下半段拟合终点
  int als102_St_Up=5;//上半段拟合起点
  int als102_Ed_Up=50;//上半段拟合终点
  int als102_Updif2=-2;//上半段倾斜开始斜度10
  int als102_Updifmin2=-5;//上半段倾斜终止斜度10
  int als102_dis_center_st=0;//距离中心点此处后开始统计
  int als102_dis_center_ed=30;  //距离中心点此处后停止统计
  int als102_b_opengudingdimian=1;//是否固定底面
  int als102_dimianpangdingjuli=15;//底面判定距离
  int als102_dimianpingjunshunum=10;//底面平均数统计个数
  int als102_dis_center_st2=5;
  int als102_dis_center_ed2=15;
  int als102_dis_center_st3=5;
  int als102_dis_center_ed3=500;
  int als102_xuexijuli=30;
  int als102_b_pingpowending=1;
  int als102_pingpowending_dis=4;
  int als102_b_xielvopen=1;
  int als102_xielvfanwei=10;
  int als102_Uplong2=15;
  int als102_cebankongdongdis=100;
  int als102_qiatouquweijuli=15;
  
/************************************/
//算法103参数
  int als103_exposure_time=10000;//曝光值
  int als103_pingjun=15;
  int als103_gujiaerzhi=160;
  int als103_widthliantongdis=5;
  int als103_highliantongdis=5;
  int als103_jiguanglong=5;//激光长度
  int als103_jiguangkuandu=10;//激光宽度
  int als103_jiguangduibidu=5;//
/************************************/
//算法104参数
  int als104_exposure_time=10000;//曝光值
  int als104_pingjun=15;//二值阈值
  int als104_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als104_b_gudingquyu=0;//是否固定区域
  int als104_widthliantongdis=5;//激光宽度连通距离
  int als104_highliantongdis=15;//激光长度连通距离
  int als104_gujiaerzhi=160;//找骨架二值图
  int als104_jiguanghight=50;//整体激光最短长度
  int als104_jiguanglong=20;//单边激光最短长度
  int als104_jiguangkuandu=6;//激光粗细
  int als104_Updif=0;//上半段倾斜开始斜度10
  int als104_Updifmin=-5;//上半段倾斜终止斜度10
  int als104_Uplong=20;//上半段直线长度
  int als104_Downdif=0;//下半段倾斜开始斜度0
  int als104_Downdifmin=5;//下半段倾斜终止斜度0
  int als104_Downdlong=50;//下半段直线长度
  int als104_St_Down=5;//下半段拟合起点
  int als104_Ed_Down=200;//下半段拟合终点
  int als104_St_Up=5;//上半段拟合起点
  int als104_Ed_Up=200;//上半段拟合终点
  int als104_Updif2=-2;//上半段倾斜开始斜度10
  int als104_Updifmin2=-5;//上半段倾斜终止斜度10
  int als104_dis_center_st=0;     //距离中心点此处后开始统计
  int als104_dis_center_ed=120;  //距离中心点此处后停止统计
  int als104_b_opengudingdimian=1; //是否固定底面
  int als104_dimianpangdingjuli=30;//两直线平面距离
  int als104_dimianpingjunshunum=30;//底面平均数统计个数//10
  int als104_dis_center_st2=20;//5;//0;     //距离中心点此处后开始统计
  int als104_dis_center_ed2=120;//100;//30;  //距离中心点此处后停止统计
  int als104_dis_center_st3=20;//5;//0;     //距离中心点此处后开始统计
  int als104_dis_center_ed3=500;//500;//30;  //距离中心点此处后停止统计
  int als104_xuexijuli=30;//学习距离
  int als104_b_pingpowending=1;//平坡处稳定焊点
  int als104_pingpowending_dis=4;//平坡处稳定距离
  int als104_b_xielvopen=1;//斜率限制
  int als104_xielvfanwei=10;//斜率范围
  int als104_Uplong2=60;//在坡度时上半段直线检测长度
  int als104_cebankongdongdis=180;//侧板跨孔洞的激光最短距离
  int als104_qiatouquweijuli=0;//恰头去尾距离
/************************************/

  int task_num = 0;
  int show_step = 0;      
};
/*
struct Params_exposure
{
  u_int16_t _0_99_exposure = 1000;
  u_int16_t _200_299_exposure = 0;
  u_int16_t _300_399_exposure = 0;
};
*/
class LaserImagePos : public rclcpp::Node
{
public:
  /**
   * @brief Construct a new Laser Line Center object.
   *
   * Initialize publisher.
   * Create an inner implementation.
   * Initialize subscription.
   * Print success if all done.
   * @param options Encapsulation of options for node initialization.
   */
  explicit LaserImagePos(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

  /**
   * @brief Destroy the Laser Line Center object.
   *
   * Release subscription.
   * Wake up all workers.
   * Wake up the manager.
   * Synchronize with all threads, wait for its return.
   * Release publisher.
   * Print success if all done.
   * Throw no exception.
   */
  virtual ~LaserImagePos();


private:

  /**
   * @brief Parameter client for camera.
   *
   */
  std::shared_ptr<rclcpp::AsyncParametersClient> _param_camera;

//  std::shared_ptr<rclcpp::SyncParametersClient> _param_camera_get;

  /**
   * @brief Publisher name.
   *
   */
  const char * _pub_name = "~/result";

  rclcpp::Publisher<IfAlgorhmitmsg>::SharedPtr _pub;


  /**
   * @brief Subscription name.
   *
   */
  const char * _sub_name = "~/image";

  /**
   * @brief Shared pointer to subscription.
   *
   */
  rclcpp::Subscription<Image>::SharedPtr _sub;

  /**
   * @brief Declare parameters with defaults before usage.
   *
   */
  void _declare_parameters();

  

//Params_exposure _get_nowexposure();

//Params_exposure ps;

  /**
   * @brief Update parameters from ROS.
   *
   * @return Params Zipped parameters
   */
  Params _update_parameters();

  void alg100_declare_parameters();
  void alg101_declare_parameters();
  void alg102_declare_parameters();
  void alg103_declare_parameters();
  void alg104_declare_parameters();

  void alg100_update_parameters();
  void alg101_update_parameters();
  void alg102_update_parameters();
  void alg103_update_parameters();
  void alg104_update_parameters();

  int alg100_getcallbackParameter(const rclcpp::Parameter &p);
  int alg101_getcallbackParameter(const rclcpp::Parameter &p);
  int alg102_getcallbackParameter(const rclcpp::Parameter &p);
  int alg103_getcallbackParameter(const rclcpp::Parameter &p);
  int alg104_getcallbackParameter(const rclcpp::Parameter &p);


  Params pm;

  int _workers;

  void _worker();

  void _manager();

  std::vector<std::thread> _threads;

  OnSetParametersCallbackHandle::SharedPtr _handle;

  std::mutex _images_mut;

  std::mutex _futures_mut;

  std::condition_variable _images_con;
  
  std::condition_variable _futures_con;

  void _push_back_image(Image::UniquePtr ptr);

  void _push_back_future(std::future<IfAlgorhmitmsg::UniquePtr> fut);

  std::deque<std::future<IfAlgorhmitmsg::UniquePtr>> _futures;

  std::deque<Image::UniquePtr> _images;

  int _0_99_exposure_time;

  IfAlgorhmitmsg::UniquePtr execute(Image::UniquePtr ptr, cv::Mat & buf, const Params & pm);

  std::string mat_type2encoding(int mat_type);

  void InitRunImage();//初始化算法
  //返回值1检测失败，0检测成功
  int RunImage(cv::Mat &imageIn,
               std::vector <cv::Point2f> &pointcloud,
               std::vector <cv::Point2f> &namepoint,
               bool &solderjoints,//是否焊点
               int step);   //输出结果点信息

  char *cv8uc1_Imagebuff_image;
  char *cv8uc1_Imagebuff1;
  char *cv8uc1_Imagebuff2;
  char *cv8uc1_Imagebuff3;
  char *cv8uc1_Imagebuff4;
  char *cv8uc1_Imagebuff5;
  char *cv8uc1_Imagebuff6;
  char *cv8uc1_Imagebuff7;
  char *cv8uc1_Imagebuff8;

  Int32 *X_line;
  float *f_line;
  Uint8 *X_lineMark;
  Int32 *X_linedif32,*niheX,*niheY;
  Myhalcv2::MyConect ImageConect,ImageConectlong,ImageConectlongPX,Imageheadline;
  Int32 firstsearch;
  Int32 firstsearch_stx,firstsearch_sty,firstsearch_edx,firstsearch_edy;
  Int32 jishuST_x,jishuST_y,jishuED_x,jishuED_y,jishuNum;
  Int32 firstdimian;
  Int32 fuzhuxielv,b_fuzhuxielv,jishuxielv;
  Myhalcv2::MyCountLine linegroup,linegroupout;

  Myhalcv2::L_Point32 fuzhufindST,fuzhufindED;//结果线2拟合区域,(上方)

  int alg100_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <cv::Point2f> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg101_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <cv::Point2f> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg102_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <cv::Point2f> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg103_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <cv::Point2f> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg104_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <cv::Point2f> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
};

}

#endif