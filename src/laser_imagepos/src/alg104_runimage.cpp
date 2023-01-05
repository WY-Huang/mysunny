#include "laser_imagepos/laser_imagepos.hpp"

#include "opencv2/opencv.hpp"
namespace laser_imagepos
{

using rcl_interfaces::msg::SetParametersResult;

void LaserImagePos::alg104_declare_parameters()
{
    this->declare_parameter("als104_exposure_time", pm.als104_exposure_time);
    this->declare_parameter("als104_pingjun", pm.als104_pingjun);
    this->declare_parameter("als104_b_yanmofuzhu", pm.als104_b_yanmofuzhu);
    this->declare_parameter("als104_b_gudingquyu", pm.als104_b_gudingquyu);
    this->declare_parameter("als104_widthliantongdis", pm.als104_widthliantongdis);
    this->declare_parameter("als104_highliantongdis", pm.als104_highliantongdis);
    this->declare_parameter("als104_gujiaerzhi", pm.als104_gujiaerzhi);
    this->declare_parameter("als104_jiguanghight", pm.als104_jiguanghight);
    this->declare_parameter("als104_jiguanglong", pm.als104_jiguanglong);
    this->declare_parameter("als104_jiguangkuandu", pm.als104_jiguangkuandu);
    this->declare_parameter("als104_Updif", pm.als104_Updif);
    this->declare_parameter("als104_Updifmin", pm.als104_Updifmin);
    this->declare_parameter("als104_Uplong", pm.als104_Uplong);
    this->declare_parameter("als104_Downdif", pm.als104_Downdif);
    this->declare_parameter("als104_Downdifmin", pm.als104_Downdifmin);
    this->declare_parameter("als104_Downdlong", pm.als104_Downdlong);
    this->declare_parameter("als104_St_Down", pm.als104_St_Down);
    this->declare_parameter("als104_Ed_Down", pm.als104_Ed_Down);
    this->declare_parameter("als104_St_Up", pm.als104_St_Up);
    this->declare_parameter("als104_Ed_Up", pm.als104_Ed_Up);
    this->declare_parameter("als104_Updif2", pm.als104_Updif2);
    this->declare_parameter("als104_Updifmin2", pm.als104_Updifmin2);
    this->declare_parameter("als104_dis_center_st", pm.als104_dis_center_st);
    this->declare_parameter("als104_dis_center_ed", pm.als104_dis_center_ed);
    this->declare_parameter("als104_b_opengudingdimian", pm.als104_b_opengudingdimian);
    this->declare_parameter("als104_dimianpangdingjuli", pm.als104_dimianpangdingjuli);
    this->declare_parameter("als104_dimianpingjunshunum", pm.als104_dimianpingjunshunum);
    this->declare_parameter("als104_dis_center_st2", pm.als104_dis_center_st2);
    this->declare_parameter("als104_dis_center_ed2", pm.als104_dis_center_ed2);
    this->declare_parameter("als104_dis_center_st3", pm.als104_dis_center_st3);
    this->declare_parameter("als104_dis_center_ed3", pm.als104_dis_center_ed3);
    this->declare_parameter("als104_xuexijuli", pm.als104_xuexijuli);
    this->declare_parameter("als104_b_pingpowending", pm.als104_b_pingpowending);
    this->declare_parameter("als104_pingpowending_dis", pm.als104_pingpowending_dis);
    this->declare_parameter("als104_b_xielvopen", pm.als104_b_xielvopen);
    this->declare_parameter("als104_xielvfanwei", pm.als104_xielvfanwei);
    this->declare_parameter("als104_Uplong2", pm.als104_Uplong2);
    this->declare_parameter("als104_cebankongdongdis", pm.als104_cebankongdongdis);
    this->declare_parameter("als104_qiatouquweijuli", pm.als104_qiatouquweijuli);  
}

void LaserImagePos::alg104_update_parameters()
{
  const auto & vp = this->get_parameters(KEYS_ALS104);
  for (const auto & p : vp) {
    if (p.get_name() == "als104_exposure_time") {
      pm.als104_exposure_time = p.as_int();
    } else if (p.get_name() == "als104_pingjun") {
      pm.als104_pingjun = p.as_int();
    }
    else if (p.get_name() == "als104_b_yanmofuzhu") {
      pm.als104_b_yanmofuzhu = p.as_int();
    }
    else if (p.get_name() == "als104_b_gudingquyu") {
      pm.als104_b_gudingquyu = p.as_int();
    }
    else if (p.get_name() == "als104_widthliantongdis") {
      pm.als104_widthliantongdis = p.as_int();
    }
    else if (p.get_name() == "als104_highliantongdis") {
      pm.als104_highliantongdis = p.as_int();
    }
    else if (p.get_name() == "als104_gujiaerzhi") {
      pm.als104_gujiaerzhi = p.as_int();
    }
    else if (p.get_name() == "als104_jiguanghight") {
      pm.als104_jiguanghight = p.as_int();
    }
    else if (p.get_name() == "als104_jiguanglong") {
      pm.als104_jiguanglong = p.as_int();
    }
    else if (p.get_name() == "als104_jiguangkuandu") {
      pm.als104_jiguangkuandu = p.as_int();
    }
    else if (p.get_name() == "als104_Updif") {
      pm.als104_Updif = p.as_int();
    }
    else if (p.get_name() == "als104_Updifmin") {
      pm.als104_Updifmin = p.as_int();
    }
    else if (p.get_name() == "als104_Uplong") {
      pm.als104_Uplong = p.as_int();
    }
    else if (p.get_name() == "als104_Downdif") {
      pm.als104_Downdif = p.as_int();
    }
    else if (p.get_name() == "als104_Downdifmin") {
      pm.als104_Downdifmin = p.as_int();
    }
    else if (p.get_name() == "als104_Downdlong") {
      pm.als104_Downdlong = p.as_int();
    }
    else if (p.get_name() == "als104_St_Down") {
      pm.als104_St_Down = p.as_int();
    }
    else if (p.get_name() == "als104_Ed_Down") {
      pm.als104_Ed_Down = p.as_int();
    }
    else if (p.get_name() == "als104_St_Up") {
      pm.als104_St_Up = p.as_int();
    }
    else if (p.get_name() == "als104_Ed_Up") {
      pm.als104_Ed_Up = p.as_int();
    }
    else if (p.get_name() == "als104_Updif2") {
      pm.als104_Updif2 = p.as_int();
    }
    else if (p.get_name() == "als104_Updifmin2") {
      pm.als104_Updifmin2 = p.as_int();
    }
    else if (p.get_name() == "als104_dis_center_st") {
      pm.als104_dis_center_st = p.as_int();
    }
    else if (p.get_name() == "als104_dis_center_ed") {
      pm.als104_dis_center_ed = p.as_int();
    }
    else if (p.get_name() == "als104_b_opengudingdimian") {
      pm.als104_b_opengudingdimian = p.as_int();
    }
    else if (p.get_name() == "als104_dimianpangdingjuli") {
      pm.als104_dimianpangdingjuli = p.as_int();
    }
    else if (p.get_name() == "als104_dimianpingjunshunum") {
      pm.als104_dimianpingjunshunum = p.as_int();
    }
    else if (p.get_name() == "als104_dis_center_st2") {
      pm.als104_dis_center_st2 = p.as_int();
    }
    else if (p.get_name() == "als104_dis_center_ed2") {
      pm.als104_dis_center_ed2 = p.as_int();
    }
    else if (p.get_name() == "als104_dis_center_st3") {
      pm.als104_dis_center_st3 = p.as_int();
    }
    else if (p.get_name() == "als104_dis_center_ed3") {
      pm.als104_dis_center_ed3 = p.as_int();
    }
    else if (p.get_name() == "als104_xuexijuli") {
      pm.als104_xuexijuli = p.as_int();
    }
    else if (p.get_name() == "als104_b_pingpowending") {
      pm.als104_b_pingpowending = p.as_int();
    }
    else if (p.get_name() == "als104_pingpowending_dis") {
      pm.als104_pingpowending_dis = p.as_int();
    }
    else if (p.get_name() == "als104_b_xielvopen") {
      pm.als104_b_xielvopen = p.as_int();
    }
    else if (p.get_name() == "als104_xielvfanwei") {
      pm.als104_xielvfanwei = p.as_int();
    }
    else if (p.get_name() == "als104_Uplong2") {
      pm.als104_Uplong2 = p.as_int();
    }
    else if (p.get_name() == "als104_cebankongdongdis") {
      pm.als104_cebankongdongdis = p.as_int();
    }
    else if (p.get_name() == "als104_qiatouquweijuli") {
      pm.als104_qiatouquweijuli = p.as_int();
    }
  }
}

int LaserImagePos::alg104_getcallbackParameter(const rclcpp::Parameter &p)
{
    if (p.get_name() == "als104_exposure_time") {
        auto k = p.as_int();
        if (k <20 || k>65535) {
            return -1;}
        else{pm.als104_exposure_time=k;
            if(pm.task_num==104){
                _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als104_exposure_time)});}
            return 1;}}
    else if(p.get_name() == "als104_pingjun") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als104_pingjun=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_b_yanmofuzhu") {
        auto k = p.as_int();
        if (k != 0 && k!=1) {
            return -1;}
        else{pm.als104_b_yanmofuzhu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_b_gudingquyu") {
        auto k = p.as_int();
        if (k != 0 && k!=1) {
            return -1;}
        else{pm.als104_b_gudingquyu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_widthliantongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_widthliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_highliantongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_highliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_gujiaerzhi") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als104_gujiaerzhi=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_jiguanghight") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_jiguanghight=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_jiguanglong") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_jiguanglong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_jiguangkuandu") {
        auto k = p.as_int();
        if (k < 0 || k > 20) {
            return -1;}
        else{pm.als104_jiguangkuandu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_Updif") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als104_Updif=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_Updifmin") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als104_Updifmin=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_Uplong") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als104_Uplong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_Downdif") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als104_Downdif=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_Downdifmin") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als104_Downdifmin=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_Downdlong") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als104_Downdlong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_St_Down") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_St_Down=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_Ed_Down") {
        auto k = p.as_int();
        if (k < 0 || k > 1500) {
            return -1;}
        else{pm.als104_Ed_Down=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_St_Up") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_St_Up=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_Ed_Up") {
        auto k = p.as_int();
        if (k < 0 || k > 1500) {
            return -1;}
        else{pm.als104_Ed_Up=p.as_int();
            return 1;}}   
    else if(p.get_name() == "als104_Updif2") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als104_Updif2=p.as_int();
            return 1;}}  
    else if(p.get_name() == "als104_Updifmin2") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als104_Updifmin2=p.as_int();
            return 1;}}  
    else if(p.get_name() == "als104_dis_center_st") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_dis_center_st=p.as_int();
            return 1;}}   
    else if(p.get_name() == "als104_dis_center_ed") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_dis_center_ed=p.as_int();
            return 1;}}     
    else if(p.get_name() == "als104_b_opengudingdimian") {
        auto k = p.as_int();
        if (k < 0 || k > 1) {
            return -1;}
        else{pm.als104_b_opengudingdimian=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_dimianpangdingjuli") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als104_dimianpangdingjuli=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_dimianpingjunshunum") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als104_dimianpingjunshunum=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_dis_center_st2") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_dis_center_st2=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_dis_center_ed2") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_dis_center_ed2=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als104_dis_center_st3") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_dis_center_st3=p.as_int();
            return 1;}}
    else if(p.get_name() == "als104_dis_center_ed3") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_dis_center_ed3=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als104_xuexijuli") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als104_xuexijuli=p.as_int();
            return 1;}}   
    else if(p.get_name() == "als104_b_pingpowending") {
        auto k = p.as_int();
        if (k != 0 && k != 1) {
            return -1;}
        else{pm.als104_b_pingpowending=p.as_int();
            return 1;}}   
    else if(p.get_name() == "als104_pingpowending_dis") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als104_pingpowending_dis=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als104_b_xielvopen") {
        auto k = p.as_int();
        if (k != 0 && k != 1) {
            return -1;}
        else{pm.als104_b_xielvopen=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als104_xielvfanwei") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als104_xielvfanwei=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als104_Uplong2") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als104_Uplong2=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als104_cebankongdongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als104_cebankongdongdis=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als104_qiatouquweijuli") {
        auto k = p.as_int();
        if (k < 0 || k > 120) {
            return -1;}
        else{pm.als104_qiatouquweijuli=p.as_int();
            return 1;}}                                          

    return 0;
}

int LaserImagePos::alg104_runimage( cv::Mat &cvimgIn,
                                    std::vector <cv::Point2f> &pointcloud,
                                    std::vector <cv::Point2f> &namepoint,
                                    bool &solderjoints,
                                    int step)    //输出结果点信息
{
    Int32 i,j,n;
    Int32 filenum=0,asfilenum=0;
    Myhalcv2::Mat imageIn,imageGasu,imageGasupain,imageBry,m_tempmatIn,m_matMask;
    Myhalcv2::Mat m_brygujia;
    Int32 nWidth=cvimgIn.cols;	//输入图像宽
    Int32 nHeight=cvimgIn.rows;	//输入图像高
    Uint8 bryvalue;
    Int32 i32_bryvalue;
    Int16 filterdata2[40];

    Myhalcv2::L_Point32 f_center={-1,-1};
    Int32 X_Linestarty=0;
    Int32 X_Lineendy=0;
    Myhalcv2::Mat i32_mXline,m_filter2,m32_filterIma;
    Int32 zhengshunum=0;
    Int32 stepfind=0;
    Myhalcv2::L_Point32 stepfindST,stepfindED;//结果线1拟合区域,(下方)
    Myhalcv2::L_Point32 midfindST,midfindED;//结果线2拟合区域,(上方)
    Myhalcv2::L_Point32 midfindST2,midfindED2;//结果线2拟合区域,(上方)
    Myhalcv2::L_Point32 endfindST,endfindED;//结果线2拟合区域,(上方)
    Myhalcv2::L_Point32 endfindST2,endfindED2;//结果线2拟合区域,(上方)

    Int32 minj;
    Int32 latsj;
    Int32 linedistance1;
    Int32 nihenum=0;
    Myhalcv2::L_Point32 linepoint32ST,linepoint32ED;
    Myhalcv2::L_line tileline;	//结果线2以及原图的线,(短的)
    Myhalcv2::L_line headline;	//结果线1以及原图的线,(短的)
    Myhalcv2::L_line endline;	//结果线1以及原图的线,(短的)
    Myhalcv2::L_line32 tileline32;
    Myhalcv2::L_line32 headline32;
    Myhalcv2::L_Point32 resultfocal1,resultfocal2,resultfocal,resultfocal3;//交点
    Int32 jiguangTop,jiguangDeep,jiguangLeft,jiguangRight;
    Myhalcv2::MyConect ImageConect,ImageConectlong,ImageConectlongPX;
    Myhalcv2::houghlineinfo headlinehough,tilelinehough,endlinehough;
    cv::Point cv_point_st,cv_point_ed;
    cv::Point2f cv_point;
    Int32 checkmid=0;
    Int32 canlearn=0;
    Int32 nocheck=0;
    Int32 canleranfield=0;
    Int32 pingmianjuli;

    /*********************/
    //算法参数
    Int32 pingjun=pm.als104_pingjun;//二值阈值
    Int32 b_yanmofuzhu=pm.als104_b_yanmofuzhu;//是否使用掩摸辅助
    Int32 b_gudingquyu=pm.als104_b_gudingquyu;//是否固定区域
    Int32 widthliantongdis=pm.als104_widthliantongdis;//激光宽度连通距离
    Int32 highliantongdis=pm.als104_highliantongdis;//激光长度连通距离
    Int32 gujiaerzhi=pm.als104_gujiaerzhi;//找骨架二值图
    Int32 jiguanghight=pm.als104_jiguanghight;//整体激光最短长度
    Int32 jiguanglong=pm.als104_jiguanglong;//单边激光最短长度
    Int32 jiguangkuandu=pm.als104_jiguangkuandu;//激光粗细

    Int32 Updif=pm.als104_Updif;//上半段倾斜开始斜度10
    Int32 Updifmin=pm.als104_Updifmin;//上半段倾斜终止斜度10
    Int32 Uplong=pm.als104_Uplong;//上半段直线长度
    Int32 Downdif=pm.als104_Downdif;//下半段倾斜开始斜度0
    Int32 Downdifmin=pm.als104_Downdifmin;//下半段倾斜终止斜度0
    Int32 Downdlong=pm.als104_Downdlong;//下半段直线长度
    Int32 St_Down=pm.als104_St_Down;//下半段拟合起点
    Int32 Ed_Down=pm.als104_Ed_Down;//下半段拟合终点
    Int32 St_Up=pm.als104_St_Up;//上半段拟合起点
    Int32 Ed_Up=pm.als104_Ed_Up;//上半段拟合终点
    Int32 Updif2=pm.als104_Updif2;//上半段倾斜开始斜度10
    Int32 Updifmin2=pm.als104_Updifmin2;//上半段倾斜终止斜度10
    Int32 dis_center_st=pm.als104_dis_center_st;     //距离中心点此处后开始统计
    Int32 dis_center_ed=pm.als104_dis_center_ed;  //距离中心点此处后停止统计
    Int32 b_opengudingdimian=pm.als104_b_opengudingdimian; //是否固定底面
    Int32 dimianpangdingjuli=pm.als104_dimianpangdingjuli;//两直线平面距离
    Int32 dimianpingjunshunum=pm.als104_dimianpingjunshunum;//底面平均数统计个数//10
    Int32 dis_center_st2=pm.als104_dis_center_st2;//5;//0;     //距离中心点此处后开始统计
    Int32 dis_center_ed2=pm.als104_dis_center_ed2;//100;//30;  //距离中心点此处后停止统计
    Int32 dis_center_st3=pm.als104_dis_center_st3;//5;//0;     //距离中心点此处后开始统计
    Int32 dis_center_ed3=pm.als104_dis_center_ed3;//500;//30;  //距离中心点此处后停止统计
    Int32 xuexijuli=pm.als104_xuexijuli;//学习距离
    Int32 b_pingpowending=pm.als104_b_pingpowending;//平坡处稳定焊点
    Int32 pingpowending_dis=pm.als104_pingpowending_dis;//平坡处稳定距离
    Int32 b_xielvopen=pm.als104_b_xielvopen;//斜率限制
    Int32 xielvfanwei=pm.als104_xielvfanwei;//斜率范围

    Int32 Uplong2=pm.als104_Uplong2;//在坡度时上半段直线检测长度
    Int32 cebankongdongdis=pm.als104_cebankongdongdis;//侧板跨孔洞的激光最短距离
    Int32 qiatouquweijuli=pm.als104_qiatouquweijuli;//恰头去尾距离
    
    if(step==2)
    {
        return 0;
    }
    imageIn=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff_image);
    Myhalcv2::CvMatToMat(cvimgIn,&imageIn,cv8uc1_Imagebuff_image);
    imageGasu=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff5);
    Myhalcv2::Mygausspyramid_2levl(imageIn,&imageGasu);  
    if(step!=0)
    {
        imageGasupain=Myhalcv2::MatCreat(nHeight,nWidth,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff8);
    }
    if(step==3)
    {
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        return 0;
    }
    imageBry=Myhalcv2::MatCreat(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    Myhalcv2::Mynormalize(imageGasu,&imageBry);
    if(step==4)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    Myhalcv2::Mybinaryval(imageBry,&bryvalue,Myhalcv2::MHC_BARINYVAL_MEAN);
    i32_bryvalue=(Int32)bryvalue+pingjun;//求平均值二值化阈值
    Myhalcv2::Mybinary(imageBry,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
    if(step==5)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    if(b_yanmofuzhu==1)
    {
        m_matMask=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff1);
        Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
        Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanghight,MAX(ImageConect.nHeight,ImageConect.nWidth));
        Myhalcv2::Myregion_to_bin(&ImageConectlong,&m_matMask,255);
        Myhalcv2::Mydilation_circle2(m_matMask,&m_matMask,10,0,Myhalcv2::MHC_MORPH_RECT);
    }
    m_brygujia=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    if(b_gudingquyu==1)
    {
        if(firstsearch==1)
        {
            Myhalcv2::MyCutselfRoi(&imageGasu,firstsearch_stx,firstsearch_sty,firstsearch_edx-firstsearch_stx+1,firstsearch_edy-firstsearch_sty+1);
        }
    }
    if(b_yanmofuzhu==1)
    {
        Myhalcv2::Mynormalize_lineXY_mask(imageGasu,&m_brygujia,m_matMask,5);
    }
    else
    {
        Myhalcv2::Mynormalize_lineXY(imageGasu,&m_brygujia,5);
    }
    if(step==6)
    {
        Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
        return 0;
    }
    i32_bryvalue=gujiaerzhi;
    Myhalcv2::Mybinary(m_brygujia,&m_brygujia,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
    if(step==7)
    {
        Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
        return 0;
    }
    Myhalcv2::Myintersection(imageBry,m_brygujia,&imageBry);

    if(step==8)
    {
        Myhalcv2::Mymat_to_binself(&imageBry,255);
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }

    Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConect,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanghight,MAX(ImageConect.nHeight,ImageConect.nWidth));
    Myhalcv2::Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_TOPTOBOTTOM_PAIXU);//在ImageConect中筛选出高度大于50的联通域
    if(ImageConectlong.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::Myselect_obj(&ImageConectlong,&ImageConectlongPX,ImageConectlong.AllMarkPointCount-1);
    Myhalcv2::Mysmallest_rectangle(&ImageConectlongPX,&jiguangLeft,&jiguangRight,&jiguangTop,&jiguangDeep);
    if(b_gudingquyu==1)
    {
        if(firstsearch==0)
        {
            firstsearch_stx=jiguangLeft-30;
            firstsearch_edx=jiguangRight+30;
            firstsearch_sty=jiguangTop-30;
            firstsearch_edy=jiguangDeep+50;
            if(firstsearch_stx<(Int32)imageGasu.startx)
            {
                firstsearch_stx=imageGasu.startx;
            }
            if(firstsearch_edx>(Int32)imageGasu.startx+imageGasu.width-1)
            {
                firstsearch_edx=imageGasu.startx+imageGasu.width-1;
            }
            if(firstsearch_sty<(Int32)imageGasu.starty)
            {
                firstsearch_sty=imageGasu.starty;
            }
            if(firstsearch_edy>(Int32)imageGasu.starty+imageGasu.height-1)
            {
                firstsearch_edy=imageGasu.starty+imageGasu.height-1;
            }
        }
        else
        {
            Int32 realstx,realsty,realedx,realedy;
            realstx=firstsearch_stx;
            realsty=firstsearch_sty;
            realedx=firstsearch_edx;
            realedy=firstsearch_edy;
            if(jiguangLeft>firstsearch_stx&&jiguangLeft<firstsearch_edx)
            {
                realstx=jiguangLeft;
            }
            if(jiguangRight>firstsearch_stx&&jiguangRight<firstsearch_edx)
            {
                realedx=jiguangRight;
            }
            if(jiguangTop>firstsearch_sty&&jiguangTop<firstsearch_edy)
            {
                realsty=jiguangTop;
            }
            if(jiguangDeep>firstsearch_sty&&jiguangDeep<firstsearch_edy)
            {
                realedy=jiguangDeep;
            }
            jiguangLeft=realstx;
            jiguangRight=realedx;
            jiguangTop=realsty;
            jiguangDeep=realedy;
        }
    }
    else
    {
        firstsearch_stx=jiguangLeft-30;
        firstsearch_edx=jiguangRight+30;
        if(firstsearch_stx<(Int32)imageGasu.startx)
        {
            firstsearch_stx=imageGasu.startx;
        }
        if(firstsearch_edx>(Int32)imageGasu.startx+imageGasu.width-1)
        {
            firstsearch_edx=imageGasu.startx+imageGasu.width-1;
        }
        jiguangLeft=firstsearch_stx;
        jiguangRight=firstsearch_edx;
    }

    Myhalcv2::MyCutRoi(imageGasu,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,jiguangLeft,jiguangTop,jiguangRight-jiguangLeft+1,jiguangDeep-jiguangTop+1);
    Myhalcv2::Mynormalize_lineXY(m_tempmatIn,&imageBry,1);
    if(step==9)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    i32_bryvalue=gujiaerzhi;//求平均值二值化阈值
    Myhalcv2::Mybinary(imageBry,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);

    if(step==10)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }

    Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanglong,MAX(ImageConect.nHeight,ImageConect.nWidth));//在ImageConect中筛选出高度大于50的联通域
    if(ImageConectlong.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::MyGetthinNoHough(&ImageConectlong,Myhalcv2::THIN_X,jiguangkuandu,&imageBry);

    if(0!=Myhalcv2::Mydeleteconnection(imageBry,&imageBry,jiguanghight,highliantongdis,Myhalcv2::MHC_8LT))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    if(step==11)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }

    if(qiatouquweijuli>0)
    {
        Myhalcv2::Myconnection(imageBry,&ImageConect,1,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
        Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_TOP_TOPTOBOTTOM_PAIXU);
        if(ImageConectlong.AllMarkPointCount==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        #endif
            return 1;
        }
        for(j=0;j<ImageConectlong.AllMarkPointCount;j++)
        {
            if(j==0)
            {
                int topj=ImageConectlong.AllMarkPoint[j].top;
                int deepj=ImageConectlong.AllMarkPoint[j].bottom;
                if(deepj!=jiguangDeep)
                {
                    for(i=0;i<ImageConectlong.AllMarkPoint[j].PointArea;i++)
                    {
                        int x=ImageConectlong.AllMarkPoint[j].point[i].x;
                        int y=ImageConectlong.AllMarkPoint[j].point[i].y;
                        if(y>deepj-qiatouquweijuli)
                        {
                            imageBry.data[y*imageBry.nWidth+x]=0;
                        }
                    }
                }
            }
            else if(j>0)
            {
                int topj=ImageConectlong.AllMarkPoint[j].top;
                int deepj=ImageConectlong.AllMarkPoint[j].bottom;
                if(deepj!=jiguangDeep)
                {
                    for(i=0;i<ImageConectlong.AllMarkPoint[j].PointArea;i++)
                    {
                        int x=ImageConectlong.AllMarkPoint[j].point[i].x;
                        int y=ImageConectlong.AllMarkPoint[j].point[i].y;
                        if(y<topj+qiatouquweijuli||y>deepj-qiatouquweijuli)
                        {
                            imageBry.data[y*imageBry.nWidth+x]=0;
                        }
                    }
                }
                else
                {
                    for(i=0;i<ImageConectlong.AllMarkPoint[j].PointArea;i++)
                    {
                        int x=ImageConectlong.AllMarkPoint[j].point[i].x;
                        int y=ImageConectlong.AllMarkPoint[j].point[i].y;
                        if(y<topj+qiatouquweijuli)
                        {
                            imageBry.data[y*imageBry.nWidth+x]=0;
                        }
                    }
                }
            }
        }
    }
    if(step==12)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    //以下的图像几乎都是完美图像,需要检测出结果
    //以下求灰度质心
    memset(X_line,0,sizeof(Int32)*nHeight);
    memset(X_lineMark,0,nHeight);

    X_Linestarty=0;
    X_Lineendy=0;
    //以下取出二值图结果中每行卷积最大值

    if(step==13)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
    }
    //膨胀做
    Myhalcv2::Mydilation_circle2(imageBry,&imageBry,2,0,Myhalcv2::MHC_MORPH_RECT);

    Myhalcv2::MyCutRoi(imageIn,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,jiguangLeft*4,jiguangTop*4,jiguangRight*4-jiguangLeft*4+1,jiguangDeep*4-jiguangTop*4+1);

    for(j=m_tempmatIn.starty;j<m_tempmatIn.starty+m_tempmatIn.height;j++)
    {
        Int32 sum_valuecoor=0;
        Int32 sum_value=0;

        for(i=m_tempmatIn.startx;i<m_tempmatIn.startx+m_tempmatIn.width;i++)
        {
            Int32 di=i>>2;
            Int32 dj=j>>2;
            if(imageBry.data[dj*imageBry.nWidth+di]!=0)
            {
                sum_valuecoor=sum_valuecoor+(Int32)m_tempmatIn.data[j*m_tempmatIn.nWidth+i]*i;
                sum_value=sum_value+m_tempmatIn.data[j*m_tempmatIn.nWidth+i];
            }
        }
        if(sum_value!=0)
        {
            float p=(float)sum_valuecoor/sum_value;
            X_line[j]=p+0.5;
            if(X_Linestarty==0)
            {
                X_Linestarty=j;//骨架起点
            }
            X_Lineendy=j;//骨架终点
            X_lineMark[j]=1;

            cv::Point2f point(p,j);
            pointcloud.push_back(point);
        }
        if(step==13)
        {
            if(sum_value!=0)
            {
                imageGasupain.data[j*imageGasupain.nWidth+X_line[j]]=128;
            }
        }
    }
    if(step==13)
    {     
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    Myhalcv2::Myfixdata(X_line,X_lineMark,nHeight);//修复空的线

    if(step==14)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        for(j=m_tempmatIn.starty;j<m_tempmatIn.starty+m_tempmatIn.height;j++)
        {
            imageGasupain.data[j*imageGasupain.nWidth+(Int32)X_line[j]]=128;
        }
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    i32_mXline=Myhalcv2::MatCreat(1,nHeight,Myhalcv2::CCV_32SC1,X_line);//把线横摆
    for(i=0;i<20;i++)
    {
        filterdata2[i]=1;
    }
    for(i=20;i<40;i++)
    {
        filterdata2[i]=-1;
    }
    m_filter2=Myhalcv2::MatCreat(1,40,Myhalcv2::CCV_16SC1,filterdata2);
    m32_filterIma=Myhalcv2::MatCreatzero(1,nHeight,Myhalcv2::CCV_32SC1,X_linedif32);
    Myhalcv2::Myfilter(i32_mXline,m_filter2,&m32_filterIma,Myhalcv2::CCV_32SC1,0,f_center);//卷积得到

    if(St_Down+Ed_Down+St_Up+Ed_Up>X_Lineendy-X_Linestarty+1)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    //找下半段
    midfindED.y=X_Lineendy-St_Up;
    midfindST.y=X_Lineendy-St_Up-Ed_Up;
    midfindED.x=X_line[midfindED.y];
    midfindST.x=X_line[midfindST.y];


    zhengshunum=0;
    stepfind=0;
    zhengshunum=0;
    stepfind=0;
    for(j=X_Lineendy-24;j>=X_Linestarty+24;j--)
    {
        //如果找到连续3个负数,可以确定起点
        if(stepfind==0)
        {
            if(m32_filterIma.ptr_int[j]<=Downdif)
            {
                zhengshunum++;
            }
            else if(m32_filterIma.ptr_int[j]>Downdif)
            {
                zhengshunum=0;
            }
            if(zhengshunum==3)
            {
                stepfind=1;
                midfindED2.x=X_line[j];	//直线起点
                midfindED2.y=j;
                latsj=j;
            }
        }
        if(stepfind==1)
        {
            if(m32_filterIma.ptr_int[j]<Downdif)//定位到最后个大于0的地方
            {
                latsj=j;
            }
            if(m32_filterIma.ptr_int[j]>Downdifmin&&(midfindED2.y-j)>cebankongdongdis)
            {
                int st=latsj;
                stepfind=2;
                midfindST2.x=X_line[st];	//直线终点
                midfindST2.y=st;
            }
        }
        if(stepfind==2)
        {
            //再判断下长度
            if(midfindED2.y-midfindST2.y<Downdlong)
            {
                stepfind=0;
                zhengshunum=0;
            }
            else
            {
                break;
            }
        }
    }
    if(stepfind!=2)
    {
        if(stepfind==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        #endif
            return 1;
        }
        else
        {
            midfindST2.y=j;
            midfindST2.x=X_line[j];
        }
    }
    midfindED.y=MIN(midfindED.y,midfindED2.y);
    midfindED.x=X_line[midfindED.y];
    midfindST.y=MAX(midfindST.y,midfindST2.y);
    midfindST.x=X_line[midfindST.y];
    if(midfindED.y-midfindST.y<20)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }

    nihenum=0;
    for(j=midfindST.y;j<=midfindED.y;j++)
    {
        if(X_lineMark[j]==1)
        {
            niheX[nihenum]=X_line[j];
            niheY[nihenum++]=j;
        }
    }
    if(nihenum<Downdlong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,nWidth,nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&tileline,&tilelinehough);

    if(step==15)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);
        Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
        Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,128,Myhalcv2::CV_LINE_8LT,1);
        Myhalcv2::MyCircle(&imageGasupain,midfindST,15,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyCircle(&imageGasupain,midfindED,15,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    endfindST.y=X_Linestarty+St_Down;
    endfindED.y=X_Linestarty+Ed_Down+St_Down;
    endfindED.x=X_line[endfindED.y];
    endfindST.x=X_line[endfindST.y];

    zhengshunum=0;
    stepfind=0;
    for(j=X_Linestarty+24;j<=X_Lineendy-24;j++)
    {
        //如果找到连续3个负数,可以确定起点
        if(stepfind==0)
        {
            if(m32_filterIma.ptr_int[j]<=Downdif)
            {
                zhengshunum++;
            }
            else if(m32_filterIma.ptr_int[j]>Downdif)
            {
                zhengshunum=0;
            }
            if(zhengshunum==3)
            {
                stepfind=1;
                endfindST2.x=X_line[j];	//直线起点
                endfindST2.y=j;
                latsj=j;
            }
        }
        if(stepfind==1)
        {
            if(m32_filterIma.ptr_int[j]<Downdif)//定位到最后个大于0的地方
            {
                latsj=j;
            }
            if(m32_filterIma.ptr_int[j]>Downdifmin)
            {
                int st=latsj;
                stepfind=2;
                endfindED2.x=X_line[st];	//直线终点
                endfindED2.y=st;
            }
        }
        if(stepfind==2)
        {
            //再判断下长度
            if(endfindED2.y-endfindST2.y<Downdlong)
            {
                stepfind=0;
                zhengshunum=0;
            }
            else
            {
                break;
            }
        }
    }
    if(stepfind!=2)
    {
        if(stepfind==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        #endif
            return 1;
        }
        else
        {
            endfindED2.y=j;
            endfindED2.x=X_line[j];
        }
    }
    endfindST.y=MAX(endfindST.y,endfindST.y);
    endfindST.x=X_line[endfindST.y];
    endfindED.y=MIN(endfindED.y,endfindED2.y);
    endfindED.x=X_line[endfindED.y];
    if(endfindED.y-endfindST.y<Downdlong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    nihenum=0;
    for(j=endfindST.y;j<=endfindED.y;j++)
    {
        if(X_lineMark[j]==1)
        {
            niheX[nihenum]=X_line[j];
            niheY[nihenum++]=j;
        }
    }
    if(nihenum<5)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,nWidth,nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&endline,&endlinehough);
    //判断两直线距离
    if(endfindED.y>midfindST.y)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    if(step==16)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        Myhalcv2::MyPoint16to32(endline.st,&linepoint32ST);
        Myhalcv2::MyPoint16to32(endline.ed,&linepoint32ED);
        Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,128,Myhalcv2::CV_LINE_8LT,1);
        Myhalcv2::MyCircle(&imageGasupain,endfindST,15,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyCircle(&imageGasupain,endfindED,15,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    if(endfindED.y>midfindST.y)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    minj=(midfindST.y+endfindED.y)/2;
    MyGetLineXpos(tileline,minj,&j);
    MyGetLineXpos(endline,minj,&i);
    pingmianjuli=i-j;
    canlearn=0;
    if(pingmianjuli>dimianpangdingjuli)
    {
        //两平面距离远
        canlearn=1;
    }
    if(canlearn==1)
    {
        zhengshunum=0;
        stepfind=0;
        for(j=midfindED.y;j>=endfindED.y;j--)
        {
            //如果找到连续3个正数,可以确定起点
            if(stepfind==0)
            {
                if(m32_filterIma.ptr_int[j]>=Updif)
                {
                    zhengshunum++;
                }
                else if(m32_filterIma.ptr_int[j]<Updif)
                {
                    zhengshunum=0;
                }
                if(zhengshunum>=3&&j<midfindED.y-cebankongdongdis)
                {
                    stepfind=1;
                    stepfindED.x=X_line[j];	//直线起点
                    stepfindED.y=j;
                    latsj=j;
                }
            }
            if(stepfind==1)
            {
                if(m32_filterIma.ptr_int[j]>Updif)//定位到最后个大于0的地方
                {
                    latsj=j;
                }
                if(m32_filterIma.ptr_int[j]<Updifmin)
                {
                    int end=latsj;
                    stepfind=2;
                    stepfindST.x=X_line[end];	//直线终点
                    stepfindST.y=end;
                }
            }
            if(stepfind==2)
            {
                //再判断下长度
                if(stepfindED.y-stepfindST.y<Uplong2)
                {
                    stepfind=0;
                    zhengshunum=0;
                }
                else
                {
                    break;
                }
            }
        }
        if(stepfind!=2)
        {
            if(stepfind!=1)
            {
                canleranfield=1;
                goto con;
            }
            else
            {
                stepfindST.x=X_line[j];
                stepfindST.y=j;
            }
        }
        minj=stepfindED.y;
        /************************************/
        //人工辅助限制
        stepfindED.y=MIN(stepfindED.y,minj-dis_center_st2);
        if(stepfindED.y<(Int32)X_Linestarty+24)
            stepfindED.y=X_Linestarty+24;
        stepfindED.x=X_line[stepfindED.y];
        stepfindST.y=MIN(stepfindST.y+50,minj-dis_center_ed2);
        stepfindST.x=X_line[stepfindST.y];
        if(stepfindED.y-stepfindST.y<Uplong2)
        {
            canleranfield=1;
            goto con;
        }
        /**************************************/
        linedistance1=sqrt((double)(stepfindED.x-stepfindST.x)*(stepfindED.x-stepfindST.x)+(stepfindED.y-stepfindST.y)*(stepfindED.y-stepfindST.y));
        if(linedistance1<Uplong2)//线太短寻找失败了
        {
            canleranfield=1;
            goto con;
        }
        nihenum=0;
        for(j=stepfindST.y;j<=stepfindED.y;j++)
        {
            if(X_lineMark[j]==1)
            {
                niheX[nihenum]=X_line[j];
                niheY[nihenum++]=j;
            }
        }
        if(nihenum==0)
        {
            canleranfield=1;
            goto con;
        }
        Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,nWidth,nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&headline,&headlinehough);
        if(step==17)
        {
            Myhalcv2::MatClone(imageIn,&imageGasupain);
            Myhalcv2::MyPoint16to32(headline.st,&linepoint32ST);
            Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ED);
            Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,128,Myhalcv2::CV_LINE_8LT,1);
            Myhalcv2::MyCircle(&imageGasupain,stepfindST,15,128,Myhalcv2::CV_CLRCLE_FILL);
            Myhalcv2::MyCircle(&imageGasupain,stepfindED,15,128,Myhalcv2::CV_CLRCLE_FILL);
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            return 0;
        }
    }
con:
    if(canleranfield==1||canlearn==0)
    {
        jishuNum=0;
        jishuST_x=0;
        jishuST_y=0;
        jishuED_x=0;
        jishuED_y=0;

        if(b_opengudingdimian==1)   //固定底面
        {
            if(firstdimian==0)
            {
                checkmid=1;
                //要检测
            }
            else//已经有现成底面
            {
                //不用检测
                nocheck=1;
            }
        }
        else
        {
            checkmid=1;
            //要检测
        }
        if(checkmid==1)
        {
            //找上半段
            zhengshunum=0;
            stepfind=0;
            for(j=midfindED.y;j>=endfindED.y;j--)
            {
                //如果找到连续3个正数,可以确定起点
                if(stepfind==0)
                {
                    if(m32_filterIma.ptr_int[j]>=Updif2)
                    {
                        zhengshunum++;
                    }
                    else if(m32_filterIma.ptr_int[j]<Updif2)
                    {
                        zhengshunum=0;
                    }
                    if(zhengshunum>=3&&j<midfindED.y-cebankongdongdis)
                    {
                        stepfind=1;
                        stepfindED.x=X_line[j];	//直线起点
                        stepfindED.y=j;
                        latsj=j;
                    }
                }
                if(stepfind==1)
                {
                    if(m32_filterIma.ptr_int[j]>Updif2)//定位到最后个大于0的地方
                    {
                        latsj=j;
                    }
                    if(m32_filterIma.ptr_int[j]<Updifmin2)
                    {
                        int end=latsj;
                        stepfind=2;
                        stepfindST.x=X_line[end];	//直线终点
                        stepfindST.y=end;
                    }
                }
                if(stepfind==2)
                {
                    //再判断下长度
                    if(stepfindED.y-stepfindST.y<Uplong)
                    {
                        stepfind=0;
                        zhengshunum=0;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(stepfind!=2)
            {
            #ifdef QUICK_TRANSMIT
                Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            #endif
                return 1;
            }
            minj=stepfindED.y;
            /************************************/
                //人工辅助限制
            stepfindED.y=MIN(stepfindED.y,minj-dis_center_st);
            if(stepfindED.y<(Int32)X_Linestarty+24)
                stepfindED.y=X_Linestarty+24;
            stepfindED.x=X_line[stepfindED.y];
            stepfindST.y=MIN(stepfindST.y+50,minj-dis_center_ed);
            stepfindST.x=X_line[stepfindST.y];
            if(stepfindED.y-stepfindST.y<Uplong)
            {
            #ifdef QUICK_TRANSMIT
                Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            #endif
                return 1;
            }
            /**************************************/

            linedistance1=sqrt((double)(stepfindED.x-stepfindST.x)*(stepfindED.x-stepfindST.x)+(stepfindED.y-stepfindST.y)*(stepfindED.y-stepfindST.y));
            if(linedistance1<Uplong)//线太短寻找失败了
            {
            #ifdef QUICK_TRANSMIT
                Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            #endif
                return 1;
            }

            nihenum=0;
            for(j=stepfindST.y;j<=stepfindED.y;j++)
            {
                if(X_lineMark[j]==1)
                {
                    niheX[nihenum]=X_line[j];
                    niheY[nihenum++]=j;
                }
            }
            if(nihenum==0)
            {
            #ifdef QUICK_TRANSMIT
                Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            #endif
                return 1;
            }
            Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,nWidth,nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&headline,&headlinehough);
            if(step==18)
            {
                Myhalcv2::MatClone(imageIn,&imageGasupain);
                Myhalcv2::MyPoint16to32(headline.st,&linepoint32ST);
                Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ED);
                Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,128,Myhalcv2::CV_LINE_8LT,1);
                Myhalcv2::MyCircle(&imageGasupain,stepfindST,15,128,Myhalcv2::CV_CLRCLE_FILL);
                Myhalcv2::MyCircle(&imageGasupain,stepfindED,15,128,Myhalcv2::CV_CLRCLE_FILL);
                Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
                return 0;
            }
        }
    }
    if(nocheck==0)
    {
        if(b_opengudingdimian==1)   //学习底面
        {
            if(canlearn==1&&pingmianjuli>xuexijuli) //两直线距离远
            {
                if(b_xielvopen==1)
                {
                    if(b_fuzhuxielv==0)
                    {
                        jishuNum++;
                        jishuST_x=jishuST_x+headline.st.x;
                        jishuST_y=jishuST_y+headline.st.y;
                        jishuED_x=jishuED_x+headline.ed.x;
                        jishuED_y=jishuED_y+headline.ed.y;
                        if(jishuNum>dimianpingjunshunum)
                        {
                            firstdimian=1;
                            fuzhufindST.x=jishuST_x/jishuNum;
                            fuzhufindST.y=jishuST_y/jishuNum;
                            fuzhufindED.x=jishuED_x/jishuNum;
                            fuzhufindED.y=jishuED_y/jishuNum;
                        }

                        jishuxielv=jishuxielv+headlinehough.theta;
                        if(jishuNum>dimianpingjunshunum)
                        {
                            b_fuzhuxielv=1;
                            fuzhuxielv=jishuxielv/jishuNum;
                        }
                    }
                    else
                    {
                        if((int)headlinehough.theta<fuzhuxielv+xielvfanwei||
                            (int)headlinehough.theta>fuzhuxielv-xielvfanwei)
                        {
                            jishuNum++;
                            jishuST_x=jishuST_x+headline.st.x;
                            jishuST_y=jishuST_y+headline.st.y;
                            jishuED_x=jishuED_x+headline.ed.x;
                            jishuED_y=jishuED_y+headline.ed.y;
                            if(jishuNum>dimianpingjunshunum)
                            {
                                firstdimian=1;
                                fuzhufindST.x=jishuST_x/jishuNum;
                                fuzhufindST.y=jishuST_y/jishuNum;
                                fuzhufindED.x=jishuED_x/jishuNum;
                                fuzhufindED.y=jishuED_y/jishuNum;
                            }
                        }
                    }
                }
                else
                {
                    jishuNum++;
                    jishuST_x=jishuST_x+headline.st.x;
                    jishuST_y=jishuST_y+headline.st.y;
                    jishuED_x=jishuED_x+headline.ed.x;
                    jishuED_y=jishuED_y+headline.ed.y;
                    if(jishuNum>dimianpingjunshunum)
                    {
                        firstdimian=1;
                        fuzhufindST.x=jishuST_x/jishuNum;
                        fuzhufindST.y=jishuST_y/jishuNum;
                        fuzhufindED.x=jishuED_x/jishuNum;
                        fuzhufindED.y=jishuED_y/jishuNum;

                    }
                }
            }
        }
    }
    else
    {
        headline.st.x=fuzhufindST.x;
        headline.st.y=fuzhufindST.y;
        headline.ed.x=fuzhufindED.x;
        headline.ed.y=fuzhufindED.y;
        if(step==19)
        {
            Myhalcv2::MatClone(imageIn,&m_brygujia);
            Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ED);
            Myhalcv2::MyPoint16to32(headline.st,&linepoint32ST);

            Myhalcv2::MyLine(&m_brygujia,linepoint32ST,linepoint32ED,128,Myhalcv2::CV_LINE_8LT,3);
            Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
            return 0;
        }
    }
    //求得两直线交点
    if(0!=Myhalcv2::MyGetLinefocal(headline,tileline,&resultfocal3))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    minj=resultfocal3.y;
    if(minj+24>X_Lineendy||minj-24<=X_Linestarty)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    zhengshunum=0;
    stepfind=0;

    for(j=X_Lineendy-24;j>=minj+24;j--)
    {
        //如果找到连续3个负数,可以确定起点
        if(stepfind==0)
        {
            if(m32_filterIma.ptr_int[j]<=Downdif)
            {
                zhengshunum++;
            }
            else if(m32_filterIma.ptr_int[j]>Downdif)
            {
                zhengshunum=0;
            }
            if(zhengshunum==3)
            {
                stepfind=1;
                midfindED.x=X_line[j];	//直线起点
                midfindED.y=j;
                latsj=j;
            }
        }
        if(stepfind==1)
        {
            if(m32_filterIma.ptr_int[j]<Downdif)//定位到最后个大于0的地方
            {
                latsj=j;
            }
            if(m32_filterIma.ptr_int[j]>Downdifmin&&(midfindED.y-j)>cebankongdongdis)
            {
                int st=latsj;
                stepfind=2;
                midfindST.x=X_line[st];	//直线终点
                midfindST.y=st;
            }
        }
        if(stepfind==2)
        {
            //再判断下长度
            if(midfindED.y-midfindST.y<Downdlong)
            {
                stepfind=0;
                zhengshunum=0;
            }
            else
            {
                break;
            }
        }
    }
    if(stepfind!=2)
    {
        if(stepfind==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        #endif
            return 1;
        }
        else
        {
            midfindST.y=j;
            midfindST.x=X_line[j];
        }
    }
    /************************************/
    //人工辅助限制
    midfindST.y=MAX(midfindST.y,minj+dis_center_st3);
    if(midfindST.y>(Int32)(X_Lineendy-24))
        midfindST.y=X_Lineendy-24;
    midfindST.x=X_line[midfindST.y];
    midfindED.y=MIN(midfindED.y,minj+dis_center_ed3);
    midfindED.x=X_line[midfindED.y];
    if(midfindED.y-midfindST.y<Downdlong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    /**************************************/
    nihenum=0;
    for(j=midfindST.y;j<=midfindED.y;j++)
    {
        if(X_lineMark[j]==1)
        {
            niheX[nihenum]=X_line[j];
            niheY[nihenum++]=j;
        }
    }
    if(nihenum<Downdlong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,nWidth,nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&tileline,&tilelinehough);
    if(step==20)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
        Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);
        Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,200,Myhalcv2::CV_LINE_8LT,3);
        Myhalcv2::MyCircle(&imageGasupain,midfindST,15,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyCircle(&imageGasupain,midfindED,15,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    //求得两直线交点
    if(0!=Myhalcv2::MyGetLinefocal(headline,tileline,&resultfocal))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }

    //验证稳定性
    if(firstdimian==1&&b_pingpowending==1)
    {
        //求得两直线交点
        Myhalcv2::L_line checkline;	//结果线2以及原图的线,(短的)
        Myhalcv2::L_Point32 checkpoint;
        Myhalcv2::MyPoint32to16(fuzhufindST,&checkline.st);
        Myhalcv2::MyPoint32to16(fuzhufindED,&checkline.ed);
        if(0!=Myhalcv2::MyGetLinefocal(tileline,checkline,&checkpoint))
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        #endif
            return 1;
        }
        if((checkpoint.y-resultfocal.y)*(checkpoint.y-resultfocal.y)+(checkpoint.x-resultfocal.x)*(checkpoint.x-resultfocal.x)>pingpowending_dis*pingpowending_dis)
        {
            headline.st.x=fuzhufindST.x;
            headline.st.y=fuzhufindST.y;
            headline.ed.x=fuzhufindED.x;
            headline.ed.y=fuzhufindED.y;
            //求得两直线交点
            if(0!=Myhalcv2::MyGetLinefocal(headline,tileline,&resultfocal))
            {
            #ifdef QUICK_TRANSMIT
                Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            #endif
                return 1;
            }
        }
    }

    resultfocal1=resultfocal;
    resultfocal2=resultfocal;
    Myline16to32(tileline,&tileline32);
    Myline16to32(headline,&headline32);
    if(step==1)
    {
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(cvimgIn.type()==CV_8UC1)
            cv::cvtColor(cvimgIn,cvimgIn,cv::COLOR_GRAY2BGR);
        cv_point_st.x=(headline32.st.x>>2);
        cv_point_st.y=(headline32.st.y>>2);
        cv_point_ed.x=(headline32.ed.x>>2);
        cv_point_ed.y=(headline32.ed.y>>2);
        cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(255,0,0),1);
        cv_point_st.x=(tileline32.st.x>>2);
        cv_point_st.y=(tileline32.st.y>>2);
        cv_point_ed.x=(tileline32.ed.x>>2);
        cv_point_ed.y=(tileline32.ed.y>>2);
        cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(0,255,0),1);
        cv_point_st.x=(resultfocal.x>>2);
        cv_point_st.y=(resultfocal.y>>2);
        cv::circle(cvimgIn,cv_point_st,5,cv::Scalar(0,0,255),1);
        cv_point_st.x=(resultfocal1.x>>2);
        cv_point_st.y=(resultfocal1.y>>2);
        cv::circle(cvimgIn,cv_point_st,5,cv::Scalar(0,255,255),1);
        cv_point_st.x=(resultfocal2.x>>2);
        cv_point_st.y=(resultfocal2.y>>2);
        cv::circle(cvimgIn,cv_point_st,5,cv::Scalar(255,0,255),1);
    }
    solderjoints=false;
    cv_point.x=resultfocal.x;
    cv_point.y=resultfocal.y;
    namepoint.push_back(cv_point);   
    
    return 0;
}

}