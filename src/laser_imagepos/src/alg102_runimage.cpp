#include "laser_imagepos/laser_imagepos.hpp"

#include "opencv2/opencv.hpp"
namespace laser_imagepos
{

using rcl_interfaces::msg::SetParametersResult;

void LaserImagePos::alg102_declare_parameters()
{
    this->declare_parameter("als102_exposure_time", pm.als102_exposure_time);
    this->declare_parameter("als102_pingjun", pm.als102_pingjun);
    this->declare_parameter("als102_b_yanmofuzhu", pm.als102_b_yanmofuzhu);
    this->declare_parameter("als102_b_gudingquyu", pm.als102_b_gudingquyu);
    this->declare_parameter("als102_widthliantongdis", pm.als102_widthliantongdis);
    this->declare_parameter("als102_highliantongdis", pm.als102_highliantongdis);
    this->declare_parameter("als102_gujiaerzhi", pm.als102_gujiaerzhi);
    this->declare_parameter("als102_jiguanghight", pm.als102_jiguanghight);
    this->declare_parameter("als102_jiguanglong", pm.als102_jiguanglong);
    this->declare_parameter("als102_jiguangkuandu", pm.als102_jiguangkuandu);
    this->declare_parameter("als102_Updif", pm.als102_Updif);
    this->declare_parameter("als102_Updifmin", pm.als102_Updifmin);
    this->declare_parameter("als102_Uplong", pm.als102_Uplong);
    this->declare_parameter("als102_Downdif", pm.als102_Downdif);
    this->declare_parameter("als102_Downdifmin", pm.als102_Downdifmin);
    this->declare_parameter("als102_Downdlong", pm.als102_Downdlong);
    this->declare_parameter("als102_St_Down", pm.als102_St_Down);
    this->declare_parameter("als102_Ed_Down", pm.als102_Ed_Down);
    this->declare_parameter("als102_St_Up", pm.als102_St_Up);
    this->declare_parameter("als102_Ed_Up", pm.als102_Ed_Up);
    this->declare_parameter("als102_Updif2", pm.als102_Updif2);
    this->declare_parameter("als102_Updifmin2", pm.als102_Updifmin2);
    this->declare_parameter("als102_dis_center_st", pm.als102_dis_center_st);
    this->declare_parameter("als102_dis_center_ed", pm.als102_dis_center_ed);
    this->declare_parameter("als102_b_opengudingdimian", pm.als102_b_opengudingdimian);
    this->declare_parameter("als102_dimianpangdingjuli", pm.als102_dimianpangdingjuli);
    this->declare_parameter("als102_dimianpingjunshunum", pm.als102_dimianpingjunshunum);
    this->declare_parameter("als102_dis_center_st2", pm.als102_dis_center_st2);
    this->declare_parameter("als102_dis_center_ed2", pm.als102_dis_center_ed2);
    this->declare_parameter("als102_dis_center_st3", pm.als102_dis_center_st3);
    this->declare_parameter("als102_dis_center_ed3", pm.als102_dis_center_ed3);
    this->declare_parameter("als102_xuexijuli", pm.als102_xuexijuli);
    this->declare_parameter("als102_b_pingpowending", pm.als102_b_pingpowending);
    this->declare_parameter("als102_pingpowending_dis", pm.als102_pingpowending_dis);
    this->declare_parameter("als102_b_xielvopen", pm.als102_b_xielvopen);
    this->declare_parameter("als102_xielvfanwei", pm.als102_xielvfanwei);
    this->declare_parameter("als102_Uplong2", pm.als102_Uplong2);
    this->declare_parameter("als102_cebankongdongdis", pm.als102_cebankongdongdis);  
    this->declare_parameter("als102_qiatouquweijuli", pm.als102_qiatouquweijuli); 
    
}

void LaserImagePos::alg102_update_parameters()
{
  const auto & vp = this->get_parameters(KEYS_ALS102);
  for (const auto & p : vp) {
    if (p.get_name() == "als102_exposure_time") {
      pm.als102_exposure_time = p.as_int();
    } else if (p.get_name() == "als102_pingjun") {
      pm.als102_pingjun = p.as_int();
    }
    else if (p.get_name() == "als102_b_yanmofuzhu") {
      pm.als102_b_yanmofuzhu = p.as_int();
    }
    else if (p.get_name() == "als102_b_gudingquyu") {
      pm.als102_b_gudingquyu = p.as_int();
    }
    else if (p.get_name() == "als102_widthliantongdis") {
      pm.als102_widthliantongdis = p.as_int();
    }
    else if (p.get_name() == "als102_highliantongdis") {
      pm.als102_highliantongdis = p.as_int();
    }
    else if (p.get_name() == "als102_gujiaerzhi") {
      pm.als102_gujiaerzhi = p.as_int();
    }
    else if (p.get_name() == "als102_jiguanghight") {
      pm.als102_jiguanghight = p.as_int();
    }
    else if (p.get_name() == "als102_jiguanglong") {
      pm.als102_jiguanglong = p.as_int();
    }
    else if (p.get_name() == "als102_jiguangkuandu") {
      pm.als102_jiguangkuandu = p.as_int();
    }
    else if (p.get_name() == "als102_Updif") {
      pm.als102_Updif = p.as_int();
    }
    else if (p.get_name() == "als102_Updifmin") {
      pm.als102_Updifmin = p.as_int();
    }
    else if (p.get_name() == "als102_Uplong") {
      pm.als102_Uplong = p.as_int();
    }
    else if (p.get_name() == "als102_Downdif") {
      pm.als102_Downdif = p.as_int();
    }
    else if (p.get_name() == "als102_Downdifmin") {
      pm.als102_Downdifmin = p.as_int();
    }
    else if (p.get_name() == "als102_Downdlong") {
      pm.als102_Downdlong = p.as_int();
    }
    else if (p.get_name() == "als102_St_Down") {
      pm.als102_St_Down = p.as_int();
    }
    else if (p.get_name() == "als102_Ed_Down") {
      pm.als102_Ed_Down = p.as_int();
    }
    else if (p.get_name() == "als102_St_Up") {
      pm.als102_St_Up = p.as_int();
    }
    else if (p.get_name() == "als102_Ed_Up") {
      pm.als102_Ed_Up = p.as_int();
    }
    else if (p.get_name() == "als102_Updif2") {
      pm.als102_Updif2 = p.as_int();
    }
    else if (p.get_name() == "als102_Updifmin2") {
      pm.als102_Updifmin2 = p.as_int();
    }
    else if (p.get_name() == "als102_dis_center_st") {
      pm.als102_dis_center_st = p.as_int();
    }
    else if (p.get_name() == "als102_dis_center_ed") {
      pm.als102_dis_center_ed = p.as_int();
    }
    else if (p.get_name() == "als102_b_opengudingdimian") {
      pm.als102_b_opengudingdimian = p.as_int();
    }
    else if (p.get_name() == "als102_dimianpangdingjuli") {
      pm.als102_dimianpangdingjuli = p.as_int();
    }
    else if (p.get_name() == "als102_dimianpingjunshunum") {
      pm.als102_dimianpingjunshunum = p.as_int();
    }
    else if (p.get_name() == "als102_dis_center_st2") {
      pm.als102_dis_center_st2 = p.as_int();
    }
    else if (p.get_name() == "als102_dis_center_ed2") {
      pm.als102_dis_center_ed2 = p.as_int();
    }
    else if (p.get_name() == "als102_dis_center_st3") {
      pm.als102_dis_center_st3 = p.as_int();
    }
    else if (p.get_name() == "als102_dis_center_ed3") {
      pm.als102_dis_center_ed3 = p.as_int();
    }
    else if (p.get_name() == "als102_xuexijuli") {
      pm.als102_xuexijuli = p.as_int();
    }
    else if (p.get_name() == "als102_b_pingpowending") {
      pm.als102_b_pingpowending = p.as_int();
    }
    else if (p.get_name() == "als102_pingpowending_dis") {
      pm.als102_pingpowending_dis = p.as_int();
    }
    else if (p.get_name() == "als102_b_xielvopen") {
      pm.als102_b_xielvopen = p.as_int();
    }
    else if (p.get_name() == "als102_xielvfanwei") {
      pm.als102_xielvfanwei = p.as_int();
    }
    else if (p.get_name() == "als102_Uplong2") {
      pm.als102_Uplong2 = p.as_int();
    }
    else if (p.get_name() == "als102_cebankongdongdis") {
      pm.als102_cebankongdongdis = p.as_int();
    }
    else if (p.get_name() == "als102_qiatouquweijuli") {
      pm.als102_qiatouquweijuli = p.as_int();
    }
    
  }
}

int LaserImagePos::alg102_getcallbackParameter(const rclcpp::Parameter &p)
{
    if (p.get_name() == "als102_exposure_time") {
        auto k = p.as_int();
        if (k <20 || k>65535) {
            return -1;}
        else{pm.als102_exposure_time=k;
            if(pm.task_num==102){
                _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als102_exposure_time)});}
            return 1;}}
    else if(p.get_name() == "als102_pingjun") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als102_pingjun=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_b_yanmofuzhu") {
        auto k = p.as_int();
        if (k != 0 && k!=1) {
            return -1;}
        else{pm.als102_b_yanmofuzhu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_b_gudingquyu") {
        auto k = p.as_int();
        if (k != 0 && k!=1) {
            return -1;}
        else{pm.als102_b_gudingquyu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_widthliantongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_widthliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_highliantongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_highliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_gujiaerzhi") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als102_gujiaerzhi=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_jiguanghight") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_jiguanghight=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_jiguanglong") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_jiguanglong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_jiguangkuandu") {
        auto k = p.as_int();
        if (k < 0 || k > 20) {
            return -1;}
        else{pm.als102_jiguangkuandu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_Updif") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als102_Updif=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_Updifmin") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als102_Updifmin=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_Uplong") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als102_Uplong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_Downdif") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als102_Downdif=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_Downdifmin") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als102_Downdifmin=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_Downdlong") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als102_Downdlong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_St_Down") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_St_Down=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_Ed_Down") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_Ed_Down=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_St_Up") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_St_Up=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_Ed_Up") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_Ed_Up=p.as_int();
            return 1;}}   
    else if(p.get_name() == "als102_Updif2") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als102_Updif2=p.as_int();
            return 1;}}  
    else if(p.get_name() == "als102_Updifmin2") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als102_Updifmin2=p.as_int();
            return 1;}}  
    else if(p.get_name() == "als102_dis_center_st") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_dis_center_st=p.as_int();
            return 1;}}   
    else if(p.get_name() == "als102_dis_center_ed") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_dis_center_ed=p.as_int();
            return 1;}}     
    else if(p.get_name() == "als102_b_opengudingdimian") {
        auto k = p.as_int();
        if (k < 0 || k > 1) {
            return -1;}
        else{pm.als102_b_opengudingdimian=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_dimianpangdingjuli") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als102_dimianpangdingjuli=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_dimianpingjunshunum") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als102_dimianpingjunshunum=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_dis_center_st2") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_dis_center_st2=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_dis_center_ed2") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_dis_center_ed2=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als102_dis_center_st3") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_dis_center_st3=p.as_int();
            return 1;}}
    else if(p.get_name() == "als102_dis_center_ed3") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_dis_center_ed3=p.as_int();
            return 1;}}        
    else if(p.get_name() == "als102_xuexijuli") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als102_xuexijuli=p.as_int();
            return 1;}}   
    else if(p.get_name() == "als102_b_pingpowending") {
        auto k = p.as_int();
        if (k != 0 && k != 1) {
            return -1;}
        else{pm.als102_b_pingpowending=p.as_int();
            return 1;}}   
    else if(p.get_name() == "als102_pingpowending_dis") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als102_pingpowending_dis=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als102_b_xielvopen") {
        auto k = p.as_int();
        if (k != 0 && k != 1) {
            return -1;}
        else{pm.als102_b_xielvopen=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als102_xielvfanwei") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als102_xielvfanwei=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als102_Uplong2") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als102_Uplong2=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als102_cebankongdongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als102_cebankongdongdis=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als102_qiatouquweijuli") {
        auto k = p.as_int();
        if (k < 0 || k > 30) {
            return -1;}
        else{pm.als102_qiatouquweijuli=p.as_int();
            return 1;}}

    return 0;
}

int LaserImagePos::alg102_runimage( cv::Mat &cvimgIn,
                                    std::vector <cv::Point2f> &pointcloud,
                                    std::vector <cv::Point2f> &namepoint,
                                    bool &solderjoints,
                                    int step)    //输出结果点信息
{
    Int32 i,j;
    Myhalcv2::Mat imageIn,imageGasu,imageGasupain,imageBry,m_tempmatIn,m_matMask;
    Myhalcv2::Mat m16_filterIma,m_filter,m_brygujia;
    Int32 nWidth=cvimgIn.cols;	//输入图像宽
    Int32 nHeight=cvimgIn.rows;	//输入图像高
    Uint8 bryvalue;
    Int32 i32_bryvalue;
    Uint8 filterdata[25]={0,0,0,0,0,
                          0,0,0,0,0,
                          1,1,1,1,1,
                          0,0,0,0,0,
                          0,0,0,0,0};
    Int16 filterdata2[10]={1,1,1,1,1,-1,-1,-1,-1,-1};

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
    
    Int32 minj,mini;
    Int32 latsj;
    Int32 linedistance1,linedistance2,linedistance3;
    Int32 nihenum=0;
    Int32 nstarti,nendi,nstartj,nendj;
    Myhalcv2::L_Point32 linepoint32ST,linepoint32ED;
    Myhalcv2::L_line tileline;	//结果线2以及原图的线,(短的)
    Myhalcv2::L_line headline,headline_min;	//结果线1以及原图的线,(短的)
    Myhalcv2::L_line endline;	//结果线1以及原图的线,(短的)
    Myhalcv2::L_line32 tileline32;
    Myhalcv2::L_line32 headline32;
    Myhalcv2::L_Point32 resultfocal1,resultfocal2,resultfocal,resultfocal3;//交点
    Int32 t;
    Int32 jiguangTop,jiguangDeep,jiguangLeft,jiguangRight;
    Int32 leijiwrite;
    Int32 centerj,centeri;
    Int32 tempi;
    Uint8 handianEn;
    Myhalcv2::L_Point32 temp_resultfocal1,temp_resultfocal2;
    Myhalcv2::houghlineinfo headlinehough,tilelinehough,endlinehough;
    cv::Point cv_point_st,cv_point_ed;
    cv::Point2f cv_point;
    Int32 checkmid=0;
    Int32 canlearn=0;
    Int32 canleranfield=0;
    Int32 nocheck=0;
    Int32 b_duanxianmoshi=0;//断线模式：1,下方线“压”上方线。0,上方线“压”下方
    Int32 pingmianjuli;

    /*********************/
    //算法参数
    Int32 pingjun=pm.als102_pingjun;//15;//二值阈值
    Int32 b_yanmofuzhu=pm.als102_b_yanmofuzhu;//1;//是否使用掩摸辅助
    Int32 b_gudingquyu=pm.als102_b_gudingquyu;//0;//是否固定区域
    Int32 widthliantongdis=pm.als102_widthliantongdis;//2;//激光宽度连通距离
    Int32 highliantongdis=pm.als102_highliantongdis;//15;//激光长度连通距离
    Int32 gujiaerzhi=pm.als102_gujiaerzhi;//160;//找骨架二值图
    Int32 jiguanghight=pm.als102_jiguanghight;//50;//整体激光最短长度
    Int32 jiguanglong=pm.als102_jiguanglong;//20;//单边激光最短长度
    Int32 jiguangkuandu=pm.als102_jiguangkuandu;//4;//激光粗细
    Int32 Updif=pm.als102_Updif;//0;//上半段倾斜开始斜度10
    Int32 Updifmin=pm.als102_Updifmin;//-5;//上半段倾斜终止斜度10
    Int32 Uplong=pm.als102_Uplong;//5;//上半段直线长度
    Int32 Downdif=pm.als102_Downdif;//0;//下半段倾斜开始斜度0
    Int32 Downdifmin=pm.als102_Downdifmin;//5;//下半段倾斜终止斜度0
    Int32 Downdlong=pm.als102_Downdlong;//5;//下半段直线长度
    Int32 St_Down=pm.als102_St_Down;//5;//下半段拟合起点
    Int32 Ed_Down=pm.als102_Ed_Down;//50;//下半段拟合终点
    Int32 St_Up=pm.als102_St_Up;//5;//上半段拟合起点
    Int32 Ed_Up=pm.als102_Ed_Up;//50;//上半段拟合终点
    Int32 Updif2=pm.als102_Updif2;//-2;//上半段倾斜开始斜度10
    Int32 Updifmin2=pm.als102_Updifmin2;//-5;//上半段倾斜终止斜度10
    Int32 dis_center_st=pm.als102_dis_center_st;//0;     //距离中心点此处后开始统计
    Int32 dis_center_ed=pm.als102_dis_center_ed;//30;  //距离中心点此处后停止统计
    Int32 b_opengudingdimian=pm.als102_b_opengudingdimian;//1;//是否固定底面
    Int32 dimianpangdingjuli=pm.als102_dimianpangdingjuli;//15;//底面判定距离
    Int32 dimianpingjunshunum=pm.als102_dimianpingjunshunum;//10;//底面平均数统计个数
    Int32 dis_center_st2=pm.als102_dis_center_st2;//5;//0;     //距离中心点此处后开始统计
    Int32 dis_center_ed2=pm.als102_dis_center_ed2;//100;//30;  //距离中心点此处后停止统计
    Int32 dis_center_st3=pm.als102_dis_center_st3;//5;//0;     //距离中心点此处后开始统计
    Int32 dis_center_ed3=pm.als102_dis_center_ed3;//500;//30;  //距离中心点此处后停止统计
    Int32 xuexijuli=pm.als102_xuexijuli;//15//学习距离
    Int32 b_pingpowending=pm.als102_b_pingpowending;//1;//平坡处稳定焊点
    Int32 pingpowending_dis=pm.als102_pingpowending_dis;//4;//平坡处稳定距离
    Int32 b_xielvopen=pm.als102_b_xielvopen;//1//斜率限制
    Int32 xielvfanwei=pm.als102_xielvfanwei;//10//斜率范围
    Int32 Uplong2=pm.als102_Uplong2;//在坡度时上半段直线检测长度
    Int32 cebankongdongdis=pm.als102_cebankongdongdis;//侧板跨孔洞的激光最短距离
    Int32 qiatouquweijuli=pm.als102_qiatouquweijuli;//恰头去尾距离
    
#ifdef DEBUG_ALG
    struct timespec timest = {0, 0};
    struct timespec timeed = {0, 0};
    long timeuse;
    RCLCPP_INFO(this->get_logger(), "start alg102");
    clock_gettime(CLOCK_REALTIME, &timest);
#endif
    if(step==2)
    {
      return 0;
    }
    imageIn=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff_image);
    Myhalcv2::CvMatToMat(cvimgIn,&imageIn,cv8uc1_Imagebuff_image);
    imageGasu=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff5);
    Myhalcv2::Mygausspyramid_2levl(imageIn,&imageGasu);
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=1,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif    
    if(step!=0)
    {
      imageGasupain=MatCreatClone(imageGasu,cv8uc1_Imagebuff8);
    }
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=2,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(step==3)
    {
      Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
      return 0;
    }
    imageBry=Myhalcv2::MatCreat(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    Myhalcv2::Mynormalize(imageGasu,&imageBry);
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=3,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(step==4)
    {
      Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
      return 0;
    }
    Myhalcv2::Mybinaryval(imageBry,&bryvalue,Myhalcv2::MHC_BARINYVAL_MEAN);
    i32_bryvalue=(Int32)bryvalue+pingjun;//求平均值二值化阈值
    Myhalcv2::Mybinary(imageBry,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=4,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
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
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=5,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(step==6)
    {
      Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
      return 0;
    }
    i32_bryvalue=gujiaerzhi;
    Myhalcv2::Mybinary(m_brygujia,&m_brygujia,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=6,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(step==7)
    {
      Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
      return 0;
    }

    Myhalcv2::Myintersection(imageBry,m_brygujia,&imageBry);
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=7,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
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
    Myhalcv2::MyCutRoi(imageGasu,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,jiguangLeft,jiguangTop,jiguangRight-jiguangLeft+1,jiguangDeep-jiguangTop+1);
    Myhalcv2::Mynormalize_lineXY(m_tempmatIn,&imageBry,1);
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=8,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(step==9)
    {
      Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
      return 0;
    }
    i32_bryvalue=gujiaerzhi;//求平均值二值化阈值
    Myhalcv2::Mybinary(imageBry,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=9,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(step==10)
    {
      Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
      return 0;
    }
    Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanglong,MAX(ImageConect.nHeight,ImageConect.nWidth));//在ImageConect中筛选出高度大于50的联通域
    if(ImageConectlong.AllMarkPointCount==0)
    {
        return 0;
    }
    Myhalcv2::MyGetthinNoHough(&ImageConectlong,Myhalcv2::THIN_X,jiguangkuandu,&imageBry);
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=10,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(step==11)
    {
      Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
      return 0;
    }
    Myhalcv2::Mydeleteconnection(imageBry,&imageBry,jiguanghight,highliantongdis,Myhalcv2::MHC_8LT);
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=11,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(step==12)
    {
      Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
      return 0;
    }
    if(qiatouquweijuli>0)
    {
        m_matMask=Myhalcv2::MatCreatClone(imageBry,cv8uc1_Imagebuff1);
    }

    /***********************/
    //以下的图像几乎都是完美图像,需要检测出结果
    //以下对高斯图做卷积
    m16_filterIma=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_16UC1,cv8uc1_Imagebuff6);
    m_filter=Myhalcv2::MatCreat(5,5,Myhalcv2::CCV_8UC1,filterdata);
    Myhalcv2::Myfilter(imageGasu,m_filter,&m16_filterIma,Myhalcv2::CCV_16UC1,0,f_center);
    memset(X_line,0,sizeof(Int32)*nHeight/4);
    memset(X_lineMark,0,nHeight/4);
    X_Linestarty=0;
    X_Lineendy=0;
    //以下取出二值图结果中每行卷积最大值
    m_brygujia=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    for(j=m16_filterIma.starty;j<m16_filterIma.starty+m16_filterIma.height;j++)
    {
        Uint16 max=0;
        Uint16 maxX=m16_filterIma.startx;
        Uint16 maxXn=0;
        for(i=m16_filterIma.startx;i<m16_filterIma.startx+m16_filterIma.width;i++)
        {
            if(imageBry.ptr_uchar[j*imageBry.nWidth+i]!=0)
            {
                if(max<m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    max=m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i];
                    maxXn=1;
                    maxX=i;
                }
                else if(max==m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    maxXn++;
                    maxX=i+maxX;
                }
            }
        }
        if(maxXn!=0)
        {
            X_line[j]=(maxX<<1)/maxXn;
            if(X_Linestarty==0)
            {
                X_Linestarty=j;//骨架起点
            }
            X_Lineendy=j;//骨架终点
            m_brygujia.data[j*imageGasu.nWidth+(X_line[j]>>1)]=255;
        }
        if(step==12)
        {
          if(X_line[j]!=0&&maxX!=imageBry.startx)
          {
              imageGasupain.data[j*imageGasu.nWidth+(X_line[j]>>1)]=0;
          }
        }
    }
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=12,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(step==13)
    {
      Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
      return 0;
    }
    if(X_Lineendy==0)//没找到骨架
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
//  Myhalcv2::Myconnection(m_brygujia,&ImageConect,5,1,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//先去掉离散点
//  Myhalcv2::Myregion_to_bin(&ImageConect,&m_brygujia,255);
    Myhalcv2::Mydeleteconnection(m_brygujia,&m_brygujia,5,1,Myhalcv2::MHC_8LT);
    Myhalcv2::Myconnection(m_brygujia,&ImageConect,15,1,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//求联通大于102的区域,联通距离10
    if(ImageConect.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    for(j=0;j<ImageConect.AllMarkPointCount;j++)
    {
        for(i=0;i<ImageConect.AllMarkPoint[j].PointArea;i++)
        {
            Int32 y=ImageConect.AllMarkPoint[j].point[i].y;
            X_lineMark[y]=1;
        }
    }
    Myhalcv2::Myfixdata(X_line,X_lineMark,nHeight/4);//修复空的线
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=13,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(step==14)
    {
      for(j=X_Linestarty;j<=X_Lineendy;j++)
      {
          imageGasupain.data[j*imageGasupain.nWidth+(X_line[j]>>1)]=30;
      }
      Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
      return 0;
    }
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=14,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(St_Down+Ed_Down+St_Up+Ed_Up>X_Lineendy-X_Linestarty-5)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }

    i32_mXline=Myhalcv2::MatCreat(1,nHeight/4,Myhalcv2::CCV_32SC1,X_line);//把线横摆
    m_filter2=Myhalcv2::MatCreat(1,10,Myhalcv2::CCV_16SC1,filterdata2);
    m32_filterIma=Myhalcv2::MatCreatzero(1,nHeight/4,Myhalcv2::CCV_32SC1,X_linedif32);
    Myhalcv2::Myfilter(i32_mXline,m_filter2,&m32_filterIma,Myhalcv2::CCV_32SC1,0,f_center);//卷积得到
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=15,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    //找下半段
    midfindED.y=X_Lineendy-St_Up;
    midfindST.y=X_Lineendy-St_Up-Ed_Up;
    midfindED.x=(X_line[midfindED.y]>>1);
    midfindST.x=(X_line[midfindST.y]>>1);

    zhengshunum=0;
    stepfind=0;
    for(j=X_Lineendy-6;j>=X_Linestarty+6;j--)
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
                midfindED2.x=(X_line[j]>>1);	//直线起点
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
                midfindST2.x=(X_line[st]>>1);	//直线终点
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
            midfindST2.x=(X_line[j]>>1);
        }
    }
    midfindED.y=MIN(midfindED.y,midfindED2.y);
    midfindED.x=(X_line[midfindED.y]>>1);
    midfindST.y=MAX(midfindST.y,midfindST2.y);
    midfindST.x=(X_line[midfindST.y]>>1);
    if(midfindED.y-midfindST.y<5)
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
            niheX[nihenum]=(X_line[j]>>1);
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
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,imageGasu.nWidth,imageGasu.nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&tileline,&tilelinehough);

    if(step==15)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);
        Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
        Myhalcv2::MyCircle(&imageGasupain,midfindST,5,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyCircle(&imageGasupain,midfindED,5,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,1);
    }
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=16,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 

    endfindST.y=X_Linestarty+St_Down;
    endfindED.y=X_Linestarty+Ed_Down+St_Down;
    endfindED.x=(X_line[endfindED.y]>>1);
    endfindST.x=(X_line[endfindST.y]>>1);

    zhengshunum=0;
    stepfind=0;
    for(j=X_Linestarty+6;j<=X_Lineendy-6;j++)
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
                endfindST2.x=(X_line[j]>>1);	//直线起点
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
                endfindED2.x=(X_line[st]>>1);	//直线终点
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
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        #endif
            return 1;
        }
        else
        {
            endfindED2.y=j;
            endfindED2.x=(X_line[j]>>1);
        }
    }
    endfindST.y=MAX(endfindST.y,endfindST.y);
    endfindST.x=(X_line[endfindST.y]>>1);
    endfindED.y=MIN(endfindED.y,endfindED2.y);
    endfindED.x=(X_line[endfindED.y]>>1);
    if(endfindED.y-endfindST.y<Downdlong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }

    nihenum=0;
    for(j=endfindST.y;j<=endfindED.y;j++)
    {
        if(X_lineMark[j]==1)
        {
            niheX[nihenum]=(X_line[j]>>1);
            niheY[nihenum++]=j;
        }
    }
    if(nihenum<5)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,imageGasu.nWidth,imageGasu.nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&endline,&endlinehough);

    if(step==15)
    {
        Myhalcv2::MyPoint16to32(endline.st,&linepoint32ST);
        Myhalcv2::MyPoint16to32(endline.ed,&linepoint32ED);
        Myhalcv2::MyCircle(&imageGasupain,endfindST,5,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyCircle(&imageGasupain,endfindED,5,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,1);
    }
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=17,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    //判断两直线距离
    if(endfindED.y>midfindST.y)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    minj=(midfindST.y+endfindED.y)/2;
    MyGetLineXpos(tileline,minj,&j);
    MyGetLineXpos(endline,minj,&i);
    if(step==15)
    {
        linepoint32ST.x=imageGasupain.startx;
        linepoint32ST.y=minj;
        linepoint32ED.x=imageGasupain.startx+imageGasupain.width;
        linepoint32ED.y=minj;
        Myhalcv2::MyDottedLine(&imageGasupain,linepoint32ST,linepoint32ED,255,10,Myhalcv2::CV_DOTTEDLINE_LINE,Myhalcv2::CV_LINE_8LT,1);
    }
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
                    stepfindED.x=(X_line[j]>>1);	//直线起点
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
                    stepfindST.x=(X_line[end]>>1);	//直线终点
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
                stepfindST.x=(X_line[j]>>1);
                stepfindST.y=j;
            }
        }
        minj=stepfindED.y;
        mini=X_line[minj];
        if(step==15)
        {
            linepoint32ST.x=imageGasupain.startx;
            linepoint32ST.y=minj;
            linepoint32ED.x=imageGasupain.startx+imageGasupain.width;
            linepoint32ED.y=minj;
            Myhalcv2::MyDottedLine(&imageGasupain,linepoint32ST,linepoint32ED,255,10,Myhalcv2::CV_DOTTEDLINE_POINT,Myhalcv2::CV_LINE_8LT,1);
        }
        /************************************/
        //人工辅助限制
        stepfindED.y=MIN(stepfindED.y,minj-dis_center_st2);
        if(stepfindED.y<(Int32)X_Linestarty+6)
            stepfindED.y=X_Linestarty+6;
        stepfindED.x=X_line[stepfindED.y]>>1;
        stepfindST.y=MAX(stepfindST.y,minj-dis_center_ed2);
        stepfindST.x=X_line[stepfindST.y]>>1;
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
                niheX[nihenum]=(X_line[j]>>1);
                niheY[nihenum++]=j;
            }
        }
        if(nihenum==0)
        {
            canleranfield=1;
            goto con;
        }
        Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,imageGasu.nWidth,imageGasu.nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&headline,&headlinehough);
    }
con:
    if(canlearn==0)
    {
        jishuNum=0;
        jishuST_x=0;
        jishuST_y=0;
        jishuED_x=0;
        jishuED_y=0;

        fuzhuxielv=0;
        jishuxielv=0;
        b_fuzhuxielv=0;
    }
    if(canleranfield==1||canlearn==0)
    {
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
                        stepfindED.x=(X_line[j]>>1);	//直线起点
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
                        stepfindST.x=(X_line[end]>>1);	//直线终点
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
                Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            #endif
                return 1;
            }
            minj=stepfindED.y;
            mini=X_line[minj];
            /************************************/
                //人工辅助限制
            stepfindED.y=MIN(stepfindED.y,minj-dis_center_st);
            if(stepfindED.y<(Int32)X_Linestarty+6)
                stepfindED.y=X_Linestarty+6;
            stepfindED.x=X_line[stepfindED.y]>>1;
            stepfindST.y=MAX(stepfindST.y,minj-dis_center_ed);
            stepfindST.x=X_line[stepfindST.y]>>1;
            if(stepfindED.y-stepfindST.y<Uplong)
            {
            #ifdef QUICK_TRANSMIT
                Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            #endif
                return 1;
            }
            /**************************************/

            linedistance1=sqrt((double)(stepfindED.x-stepfindST.x)*(stepfindED.x-stepfindST.x)+(stepfindED.y-stepfindST.y)*(stepfindED.y-stepfindST.y));
            if(linedistance1<Uplong)//线太短寻找失败了
            {
            #ifdef QUICK_TRANSMIT
                Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            #endif
                return 1;
            }

            nihenum=0;
            for(j=stepfindST.y;j<=stepfindED.y;j++)
            {
                if(X_lineMark[j]==1)
                {
                    niheX[nihenum]=(X_line[j]>>1);
                    niheY[nihenum++]=j;
                }
            }
            if(nihenum==0)
            {
            #ifdef QUICK_TRANSMIT
                Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            #endif
                return 1;
            }
            Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,imageGasu.nWidth,imageGasu.nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&headline,&headlinehough);

        }
    }

    if(step==15)
    {
        if(nocheck==0)
        {
            Myhalcv2::MyPoint16to32(headline.st,&linepoint32ST);
            Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ED);
            Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,1);
            Myhalcv2::MyCircle(&imageGasupain,stepfindST,5,128,Myhalcv2::CV_CLRCLE_FILL);
            Myhalcv2::MyCircle(&imageGasupain,stepfindED,5,128,Myhalcv2::CV_CLRCLE_FILL);
        }
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=18,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 

    /***********************/
    
    if(step!=0)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
    }

    //在大图上拟合
    imageGasu=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff5);
    for(j=X_Linestarty;j<=X_Lineendy;j++)
    {
        imageGasu.data[j*imageGasu.nWidth+(X_line[j]>>1)]=255;
    }

    if(nocheck==0)
    {
        headline.ed.x=headline.ed.x*4;
        headline.ed.y=headline.ed.y*4;
        headline.st.x=headline.st.x*4;
        headline.st.y=headline.st.y*4;
        stepfindST.x=stepfindST.x*4;
        stepfindST.y=stepfindST.y*4;
        stepfindED.x=stepfindED.x*4;
        stepfindED.y=stepfindED.y*4;

        nstartj=MIN(stepfindST.y,stepfindED.y);
        nendj=MAX(stepfindST.y,stepfindED.y);
        nstarti=MIN(stepfindST.x,stepfindED.x)-30;
        nendi=MAX(stepfindST.x,stepfindED.x)+30;
        if(nstarti<0)
        {
            nstarti=0;
        }
        if(nendi>nWidth-1)
        {
            nendi=nWidth-1;
        }
        if(nstartj<0)
        {
            nstartj=0;
        }
        if(nendj>nHeight-1)
        {
            nendj=nHeight-1;
        }
        Myhalcv2::MyCutRoi(imageIn,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,nstarti,nstartj,nendi-nstarti+1,nendj-nstartj+1);
        Myhalcv2::Myfilter(m_tempmatIn,m_filter,&m16_filterIma,Myhalcv2::CCV_16UC1,0,f_center);

        MyPoint16to32(headline.ed,&linepoint32ED);
        MyPoint16to32(headline.st,&linepoint32ST);

        linepoint32ST.x=((linepoint32ST.x)>>2);
        linepoint32ST.y=((linepoint32ST.y)>>2);
        linepoint32ED.x=((linepoint32ED.x)>>2);
        linepoint32ED.y=((linepoint32ED.y)>>2);

        imageBry=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
        Myhalcv2::MyLine(&imageBry,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,7);

        m_brygujia=Myhalcv2::MatCreatzero(nHeight,nWidth,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
        for(j=nstartj;j<=nendj;j++)
        {
            Uint16 max=0;
            Uint16 maxX=nstarti;
            Uint16 maxXn=0;
            for(i=nstarti;i<=nendi;i++)
            {
                Int32 dj=(j>>2);
                Int32 di=(i>>2);
                if(imageBry.ptr_uchar[dj*imageBry.nWidth+di]!=0&&imageGasu.data[dj*imageGasu.nWidth+di]!=0)
                {
                    if(max<m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                    {
                        max=m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i];
                        maxXn=1;
                        maxX=i;
                    }
                    else if(max==m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                    {
                        maxXn++;
                        maxX=i+maxX;
                    }
                }
            }
            if(maxXn!=0&&max!=0)
            {
                m_brygujia.ptr_uchar[j*m_brygujia.nWidth+(((maxX<<1)/maxXn)>>1)]=255;
            }
            else if(maxXn!=0&&max==0)
            {
                m_brygujia.ptr_uchar[j*m_brygujia.nWidth+(X_line[j>>2]<<1)]=255;
            }
        }
    #ifdef DEBUG_ALG;
        clock_gettime(CLOCK_REALTIME, &timeed);
        timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
        RCLCPP_INFO(this->get_logger(), "start alg102=19,time=%d",timeuse);
        clock_gettime(CLOCK_REALTIME, &timest);
    #endif 

        Myhalcv2::MyCutminRoi(m_brygujia,&m_brygujia,Myhalcv2::MHC_CUTMIN_32,nstarti,nstartj,nendi-nstarti+1,nendj-nstartj+1);
        Myhalcv2::Myconnection2(m_brygujia,&ImageConect,10,2,3,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
        if(ImageConect.AllMarkPointCount==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        #endif
            return 1;
        }
        Myhalcv2::Myhom_conect2d_translate(&ImageConect,&ImageConectlong,nstarti,nstartj,Myhalcv2::MHC_TRANS_OUTIMAGE);
        ImageConectlong.nHeight=imageIn.nHeight;
        ImageConectlong.nWidth=imageIn.nWidth;
        ImageConectlong.startx=imageIn.startx;
        ImageConectlong.starty=imageIn.starty;
        ImageConectlong.height=imageIn.height;
        ImageConectlong.width=imageIn.width;

        for(j=0;j<ImageConectlong.AllMarkPointCount;j++)
        {
            for(i=0;i<ImageConectlong.AllMarkPoint[j].PointArea;i++)
            {
                cv::Point2f point(ImageConectlong.AllMarkPoint[j].point[i].x,ImageConectlong.AllMarkPoint[j].point[i].y);
                pointcloud.push_back(point);
            }
        }

        if(0!=Myhalcv2::MyConect_sqare_line(&ImageConectlong,Myhalcv2::MHC_MIXDIS_SQARE,&headline,&headlinehough))
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        #endif
            return 1;
        }
        if(step==16)
        {
            Myhalcv2::MatClone(imageIn,&m_brygujia);
            Myhalcv2::Myregion_to_add(&ImageConectlong,&m_brygujia,0);
            Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ED);
            Myhalcv2::MyPoint16to32(headline.st,&linepoint32ST);
            Myhalcv2::MyLine(&m_brygujia,linepoint32ST,linepoint32ED,128,Myhalcv2::CV_LINE_8LT,3);
            Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
            return 0;
        }
        if(b_opengudingdimian==1)   //学习底面
        {
            if(canlearn==1&&pingmianjuli>xuexijuli) //两直线距离远
            {
                /*
                static Int32 olddimianpingjunshunum=0;
                if(olddimianpingjunshunum!=dimianpingjunshunum)
                {
                    olddimianpingjunshunum=dimianpingjunshunum;
                    jishuNum=0;
                }
                if(jishuNum>=dimianpingjunshunum)
                {
                    int count;
                    linegroup.linenum=dimianpingjunshunum;
                    linegroup.nHeight=imageIn.nHeight;
                    linegroup.nWidth=imageIn.nWidth;
                    linegroup.startx=imageIn.startx;
                    linegroup.starty=imageIn.starty;
                    linegroup.width=imageIn.width;
                    linegroup.height=imageIn.height;
                    Myhalcv2::Mysort_line(&linegroup,&linegroupout,Myhalcv2::MHC_K_LINEPAIXU);

                    firstdimian=1;
                    fuzhufindST.x=linegroupout.line[dimianpingjunshunum/2].st.x;
                    fuzhufindST.y=linegroupout.line[dimianpingjunshunum/2].st.y;
                    fuzhufindED.x=linegroupout.line[dimianpingjunshunum/2].ed.x;
                    fuzhufindED.y=linegroupout.line[dimianpingjunshunum/2].ed.y;

                    count=jishuNum%dimianpingjunshunum;
                    linegroup.houghinfo[count]=headlinehough;
                    linegroup.line[count]=headline;
                    jishuNum++;
                }
                else
                {
                    linegroup.houghinfo[jishuNum]=headlinehough;
                    linegroup.line[jishuNum]=headline;
                    jishuNum++;
                }
                */
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
                        #ifdef DEBUG_ALG;
                            RCLCPP_INFO(this->get_logger(), "start_dimian_tongji,jishuNum=%d,jishuST_x=%d,jishuST_y=%d,jishuED_x=%d,jishuED_y=%d",
                                                            jishuNum,jishuST_x,jishuST_y,jishuED_x,jishuED_y);
                        #endif 
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
                            #ifdef DEBUG_ALG;
                                RCLCPP_INFO(this->get_logger(), "start_dimian_tongji,jishuNum=%d,jishuST_x=%d,jishuST_y=%d,jishuED_x=%d,jishuED_y=%d",
                                                                jishuNum,jishuST_x,jishuST_y,jishuED_x,jishuED_y);
                            #endif 
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
                    #ifdef DEBUG_ALG;
                        RCLCPP_INFO(this->get_logger(), "start_dimian_tongji,jishuNum=%d,jishuST_x=%d,jishuST_y=%d,jishuED_x=%d,jishuED_y=%d",
                                                        jishuNum,jishuST_x,jishuST_y,jishuED_x,jishuED_y);
                    #endif 
                    }
                }
            }
        } 
    #ifdef DEBUG_ALG;
        clock_gettime(CLOCK_REALTIME, &timeed);
        timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
        RCLCPP_INFO(this->get_logger(), "start alg102=20,time=%d",timeuse);
        clock_gettime(CLOCK_REALTIME, &timest);
    #endif 
    }
    else
    {
        headline.st.x=fuzhufindST.x;
        headline.st.y=fuzhufindST.y;
        headline.ed.x=fuzhufindED.x;
        headline.ed.y=fuzhufindED.y;
        if(step==16)
        {
            Myhalcv2::MatClone(imageIn,&m_brygujia);
            Myhalcv2::Myregion_to_add(&ImageConectlong,&m_brygujia,0);
            Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ED);
            Myhalcv2::MyPoint16to32(headline.st,&linepoint32ST);
            Myhalcv2::MyLine(&m_brygujia,linepoint32ST,linepoint32ED,128,Myhalcv2::CV_LINE_8LT,3);
            Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
            return 0;
        }
    #ifdef DEBUG_ALG;
        RCLCPP_INFO(this->get_logger(), "fuzhufindST.x=%d,fuzhufindST.y=%d,fuzhufindED.x=%d,fuzhufindED.y=%d",
                                            fuzhufindST.x,fuzhufindST.y,fuzhufindED.x,fuzhufindED.y
                                            );
    #endif 
    #ifdef DEBUG_ALG;
        clock_gettime(CLOCK_REALTIME, &timeed);
        timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
        RCLCPP_INFO(this->get_logger(), "start alg102=21,time=%d",timeuse);
        clock_gettime(CLOCK_REALTIME, &timest);
    #endif 
    }


    headline_min.st.x=headline.st.x/4;
    headline_min.st.y=headline.st.y/4;
    headline_min.ed.x=headline.ed.x/4;
    headline_min.ed.y=headline.ed.y/4;

    //求得两直线交点
    if(0!=Myhalcv2::MyGetLinefocal(headline_min,tileline,&resultfocal3))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    minj=resultfocal3.y;
    if(minj+6>X_Lineendy-6||minj+6<=X_Linestarty)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    zhengshunum=0;
    stepfind=0;
    for(j=X_Lineendy-6;j>=minj+6;j--)
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
                midfindED.x=(X_line[j]>>1);	//直线起点
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
                midfindST.x=(X_line[st]>>1);	//直线终点
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
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        #endif
            return 1;
        }
        else
        {
            midfindST.y=j;
            midfindST.x=(X_line[j]>>1);
        }
    }

    /************************************/
    //人工辅助限制
    midfindST.y=MAX(midfindST.y,minj+dis_center_st3);
    if(midfindST.y>(Int32)(X_Lineendy-6))
        midfindST.y=X_Lineendy-6;
    midfindST.x=X_line[midfindST.y]>>1;
    midfindED.y=MIN(midfindED.y,minj+dis_center_ed3);
    midfindED.x=X_line[midfindED.y]>>1;
    if(midfindED.y-midfindST.y<Downdlong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    /**************************************/
    nihenum=0;
    for(j=midfindST.y;j<=midfindED.y;j++)
    {
        if(X_lineMark[j]==1)
        {
            niheX[nihenum]=(X_line[j]>>1);
            niheY[nihenum++]=j;
        }
    }
    if(nihenum<Downdlong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,imageGasu.nWidth,imageGasu.nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&tileline,&tilelinehough);

#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=22,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 

    
    tileline.ed.x=tileline.ed.x*4;
    tileline.ed.y=tileline.ed.y*4;
    tileline.st.x=tileline.st.x*4;
    tileline.st.y=tileline.st.y*4;
    midfindST.x=midfindST.x*4;
    midfindST.y=midfindST.y*4;
    midfindED.x=midfindED.x*4;
    midfindED.y=midfindED.y*4;
    nstartj=MIN(midfindST.y,midfindED.y);
    nendj=MAX(midfindST.y,midfindED.y);
    nstarti=MIN(midfindST.x,midfindED.x)-30;
    nendi=MAX(midfindST.x,midfindED.x)+30;
    if(nstarti<0)
    {
        nstarti=0;
    }
    if(nendi>nWidth-1)
    {
        nendi=nWidth-1;
    }
    if(nstartj<0)
    {
        nstartj=0;
    }
    if(nendj>nHeight-1)
    {
        nendj=nHeight-1;
    }

    Myhalcv2::MyCutRoi(imageIn,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,nstarti,nstartj,nendi-nstarti+1,nendj-nstartj+1);
    Myhalcv2::Myfilter(m_tempmatIn,m_filter,&m16_filterIma,Myhalcv2::CCV_16UC1,0,f_center);
    Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
    Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);

    linepoint32ST.x=(linepoint32ST.x>>2);
    linepoint32ST.y=(linepoint32ST.y>>2);
    linepoint32ED.x=(linepoint32ED.x>>2);
    linepoint32ED.y=(linepoint32ED.y>>2);
    imageBry=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    MyLine(&imageBry,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,7);
    m_brygujia=Myhalcv2::MatCreatzero(nHeight,nWidth,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    /***********/
    //掐头去尾
    if(qiatouquweijuli>0)
    {
        Myhalcv2::Myintersection(imageBry,m_matMask,&imageBry);
        Myhalcv2::Myconnection(imageBry,&ImageConect,1,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
        Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_TOP_TOPTOBOTTOM_PAIXU);
        for(j=0;j<ImageConectlong.AllMarkPointCount;j++)
        {
            if(j==0)
            {
                int topj=ImageConectlong.AllMarkPoint[j].top;
                int deepj=ImageConectlong.AllMarkPoint[j].bottom;
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
            else if(j>0)
            {
                int topj=ImageConectlong.AllMarkPoint[j].top;
                int deepj=ImageConectlong.AllMarkPoint[j].bottom;
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
        }
    }
    /***********/
    for(j=nstartj;j<=nendj;j++)
    {
        Uint16 max=0;
        Uint16 maxX=nstarti;
        Uint16 maxXn=0;
        for(i=nstarti;i<=nendi;i++)
        {
            Int32 dj=(j>>2);
            Int32 di=(i>>2);
            if(imageBry.ptr_uchar[dj*imageBry.nWidth+di]!=0&&imageGasu.data[dj*imageGasu.nWidth+di]!=0)
            {
                if(max<m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    max=m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i];
                    maxXn=1;
                    maxX=i;
                }
                else if(max==m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    maxXn++;
                    maxX=i+maxX;
                }
            }
        }
        if(maxXn!=0&&max!=0)
        {
            m_brygujia.ptr_uchar[j*m_brygujia.nWidth+(((maxX<<1)/maxXn)>>1)]=255;
        }
    }
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=23,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    Myhalcv2::MyCutminRoi(m_brygujia,&m_brygujia,Myhalcv2::MHC_CUTMIN_32,nstarti,nstartj,nendi-nstarti+1,nendj-nstartj+1);
    Myhalcv2::Myconnection2(m_brygujia,&ImageConect,15,2,3,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    if(ImageConect.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;   
    }
    Myhalcv2::Myhom_conect2d_translate(&ImageConect,&ImageConectlong,nstarti,nstartj,Myhalcv2::MHC_TRANS_OUTIMAGE);
    ImageConectlong.nHeight=imageIn.nHeight;
    ImageConectlong.nWidth=imageIn.nWidth;
    ImageConectlong.startx=imageIn.startx;
    ImageConectlong.starty=imageIn.starty;
    ImageConectlong.height=imageIn.height;
    ImageConectlong.width=imageIn.width;
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=24,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    for(j=0;j<ImageConectlong.AllMarkPointCount;j++)
    {
      for(i=0;i<ImageConectlong.AllMarkPoint[j].PointArea;i++)
      {
          cv::Point2f point(ImageConectlong.AllMarkPoint[j].point[i].x,ImageConectlong.AllMarkPoint[j].point[i].y);
          pointcloud.push_back(point);
      }
    }

    if(0!=Myhalcv2::MyConect_sqare_line(&ImageConectlong,Myhalcv2::MHC_MIXDIS_SQARE,&tileline,&tilelinehough))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    //求得两直线交点
    if(0!=Myhalcv2::MyGetLinefocal(headline,tileline,&resultfocal))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
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
            return 1;
        if((checkpoint.y-resultfocal.y)*(checkpoint.y-resultfocal.y)+(checkpoint.x-resultfocal.x)*(checkpoint.x-resultfocal.x)>pingpowending_dis*pingpowending_dis)
        {
            headline.st.x=fuzhufindST.x;
            headline.st.y=fuzhufindST.y;
            headline.ed.x=fuzhufindED.x;
            headline.ed.y=fuzhufindED.y;
            //求得两直线交点
            if(0!=Myhalcv2::MyGetLinefocal(headline,tileline,&resultfocal))
                return 1;
        }
    }

    resultfocal1=resultfocal;
    resultfocal2=resultfocal;
    Myline16to32(tileline,&tileline32);
    Myline16to32(headline,&headline32);
#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "start alg102=25,time=%d",timeuse);
    clock_gettime(CLOCK_REALTIME, &timest);
#endif 
    if(step==1)
    {
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
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
/*
    cv_point.x=resultfocal1.x;
    cv_point.y=resultfocal1.y;
    namepoint.push_back(cv_point);
    cv_point.x=resultfocal2.x;
    cv_point.y=resultfocal2.y;
    namepoint.push_back(cv_point);
*/

#ifdef DEBUG_ALG;
    clock_gettime(CLOCK_REALTIME, &timeed);
    timeuse=(timeed.tv_sec - timest.tv_sec)*1000000000 + (timeed.tv_nsec - timest.tv_nsec);
    RCLCPP_INFO(this->get_logger(), "finish alg102,time=%d",timeuse);
#endif 
    
    return 0;
}

}