#include "laser_imagepos/laser_imagepos.hpp"

#include "opencv2/opencv.hpp"
namespace laser_imagepos
{

using rcl_interfaces::msg::SetParametersResult;

void LaserImagePos::alg103_declare_parameters()
{
    this->declare_parameter("als103_exposure_time", pm.als103_exposure_time);
    this->declare_parameter("als103_pingjun", pm.als103_pingjun);
    this->declare_parameter("als103_gujiaerzhi", pm.als103_gujiaerzhi);
    this->declare_parameter("als103_widthliantongdis", pm.als103_widthliantongdis);
    this->declare_parameter("als103_highliantongdis", pm.als103_highliantongdis);
    this->declare_parameter("als103_jiguanglong", pm.als103_jiguanglong);
    this->declare_parameter("als103_jiguangkuandu", pm.als103_jiguangkuandu);
    this->declare_parameter("als103_jiguangduibidu", pm.als103_jiguangduibidu);
}

void LaserImagePos::alg103_update_parameters()
{
  const auto & vp = this->get_parameters(KEYS_ALS103);
  for (const auto & p : vp) {
    if (p.get_name() == "als103_exposure_time") {
      pm.als103_exposure_time = p.as_int();
    } 
    else if (p.get_name() == "als103_pingjun") {
      pm.als103_pingjun = p.as_int();
    }
    else if (p.get_name() == "als103_gujiaerzhi") {
      pm.als103_gujiaerzhi = p.as_int();
    }
    else if (p.get_name() == "als103_widthliantongdis") {
      pm.als103_widthliantongdis = p.as_int();
    }
    else if (p.get_name() == "als103_highliantongdis") {
      pm.als103_highliantongdis = p.as_int();
    }
    else if (p.get_name() == "als103_jiguanglong") {
      pm.als103_jiguanglong = p.as_int();
    }
    else if (p.get_name() == "als103_jiguangkuandu") {
      pm.als103_jiguangkuandu = p.as_int();
    }
    else if (p.get_name() == "als103_jiguangduibidu") {
      pm.als103_jiguangduibidu = p.as_int();
    }
  }
}

int LaserImagePos::alg103_getcallbackParameter(const rclcpp::Parameter &p)
{
    if (p.get_name() == "als103_exposure_time") {
        auto k = p.as_int();
        if (k <20 || k>65535) {
            return -1;}
        else{pm.als103_exposure_time=k;
            if(pm.task_num==103){
                _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als103_exposure_time)});}
            return 1;}}
    else if(p.get_name() == "als103_pingjun") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als103_pingjun=p.as_int();
            return 1;}}
    else if(p.get_name() == "als103_gujiaerzhi") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als103_gujiaerzhi=p.as_int();
            return 1;}}
    else if(p.get_name() == "als103_widthliantongdis") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als103_widthliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als103_highliantongdis") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als103_highliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als103_jiguanglong") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als103_jiguanglong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als103_jiguangkuandu") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als103_jiguangkuandu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als103_jiguangduibidu") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als103_jiguangduibidu=p.as_int();
            return 1;}}

    return 0;
}

int LaserImagePos::alg103_runimage( cv::Mat &cvimgIn,
                                    std::vector <cv::Point2f> &pointcloud,
                                    std::vector <cv::Point2f> &namepoint,
                                    bool &solderjoints,
                                    int step)    //输出结果点信息
{
    Uint8 bryvalue;
    Int32 i32_bryvalue;
    Int32 i,j,n,t;
    Myhalcv2::Mat imageIn;
    Myhalcv2::Mat imageGasu;
    Myhalcv2::Mat imageBry;
    Myhalcv2::Mat m16_filterIma;
    Myhalcv2::Mat m_brygujia;
    Myhalcv2::Mat m_filter;
    Myhalcv2::Mat imageGasupain;
    Myhalcv2::MyConect ImageConect,ImageConectlong;
    Int32 nWidth=cvimgIn.cols;	//输入图像宽
    Int32 nHeight=cvimgIn.rows;	//输入图像高
    Uint8 filterdata[25]={0,0,0,0,0,
                          0,0,0,0,0,
                          1,1,1,1,1,
                          0,0,0,0,0,
                          0,0,0,0,0};

    Myhalcv2::L_Point32 f_center={-1,-1};
    Int32 X_Linestarty=0;
    Int32 X_Lineendy=0;
    cv::Point2f cv_point;

/*********************/
    //算法参数
    Int32 pingjun=pm.als103_pingjun;//15;
    Int32 gujiaerzhi=pm.als103_gujiaerzhi;//160;
    Int32 widthliantongdis=pm.als103_widthliantongdis;//5;
    Int32 highliantongdis=pm.als103_highliantongdis;//5;
    Int32 jiguanglong=pm.als103_jiguanglong;//5;//激光长度
    Int32 jiguangkuandu=pm.als103_jiguangkuandu;//10;//激光宽度
    Int32 jiguangduibidu=pm.als103_jiguangduibidu;//5;

    if(step==2)
    {
      return 0;
    }
    imageIn=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff_image);
    Myhalcv2::CvMatToMat(cvimgIn,&imageIn,cv8uc1_Imagebuff_image);
    imageGasu=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff5);
    imageBry=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    m_brygujia=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    m16_filterIma=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff6);
    
    Myhalcv2::Mygausspyramid_2levl(imageIn,&imageGasu);

    if(step==3)
    {
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        return 0;
    }

    if(step!=0)
    {
        imageGasupain=Myhalcv2::MatCreatClone(imageGasu,cv8uc1_Imagebuff8);
    }

    Myhalcv2::Mybinaryval(imageGasu,&bryvalue,Myhalcv2::MHC_BARINYVAL_MEAN);

    i32_bryvalue=(Int32)bryvalue+pingjun;//求平均值二值化阈值
    Myhalcv2::Mybinary(imageGasu,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
    if(step==4)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    m_brygujia=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    Myhalcv2::Mynormalize_lineXY(imageGasu,&m_brygujia,jiguangduibidu);

    if(step==5)
    {
        Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
        return 0;
    }

    i32_bryvalue=gujiaerzhi;
    Myhalcv2::Mybinary(m_brygujia,&m_brygujia,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);

    if(step==6)
    {
        Myhalcv2::Mymat_to_binself(&m_brygujia,255);
        Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
        return 0;
    }

    Myhalcv2::Myconnection2(m_brygujia,&ImageConect,jiguanglong,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanglong,MAX(ImageConect.nWidth,ImageConect.nHeight));//在ImageConect中筛选出高度大于50的联通域
    if(ImageConectlong.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::MyGetthinNoHough(&ImageConectlong,Myhalcv2::THIN_X,jiguangkuandu,&m_brygujia);
    if(step==7)
    {
        Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
        return 0;
    }

    Myhalcv2::Mydilation_circle2(m_brygujia,&imageBry,2,0,Myhalcv2::MHC_MORPH_RECT);

    for(j=imageIn.starty;j<imageIn.starty+imageIn.height;j++)
    {
        Int32 sum_valuecoor=0;
        Int32 sum_value=0;

        for(i=imageIn.startx;i<imageIn.startx+imageIn.width;i++)
        {
            Int32 di=i>>2;
            Int32 dj=j>>2;
            if(imageBry.data[dj*imageBry.nWidth+di]!=0)
            {
                sum_valuecoor=sum_valuecoor+(Int32)imageIn.data[j*imageIn.nWidth+i]*i;
                sum_value=sum_value+imageIn.data[j*imageIn.nWidth+i];
            }
        }
        if(sum_value!=0)
        {
            f_line[j]=(float)sum_valuecoor/sum_value;
            if(X_Linestarty==0)
            {
                X_Linestarty=j;//骨架起点
            }
            X_Lineendy=j;//骨架终点
            X_lineMark[j]=1;
        }
        if(step==8)
        {
            if(sum_value!=0)
            {
                imageGasupain.data[j*imageGasupain.nWidth+X_line[j]]=128;
            }
        }
    }
    if(step==8)
    {
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    /***********************/

    /*
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

        if(step==8)
        {
            if(X_line[j]!=0&&maxX!=imageBry.startx)
            {
                imageGasupain.data[j*imageGasu.nWidth+(X_line[j]>>1)]=0;
            }
        }
    }
    if(step==8)
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
    Myhalcv2::Myconnection(m_brygujia,&ImageConect,jiguanglong,1,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//先去掉离散点
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
    m_brygujia=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    for(j=X_Linestarty;j<=X_Lineendy;j++)
    {
        m_brygujia.data[j*m_brygujia.nWidth+(X_line[j]>>1)]=255;
    }
    if(step==9)
    {
        Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
        return 0;
    }
    */
/***************************************/
//  Myhalcv2::Myresizefix2bitdata_4fSize(X_line,X_lineMark,f_line,nHeight/4);
    for(i=0;i<nHeight;i++)
    {
        Int32 y=(Int32)(((float)i/4)+0.5);
        Int32 x=(Int32)(f_line[i]/4+0.5);
        if(x>=0&&x<imageBry.nWidth&&y>=0&&y<imageBry.nHeight)
        {
            if(imageBry.data[y*imageBry.nWidth+x]==0)
            {
                f_line[i]=-1;
            }
        }
        cv::Point2f point(f_line[i],i);
        pointcloud.push_back(point);
    }
    if(step==1)
    {
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(cvimgIn.type()==CV_8UC1)
            cv::cvtColor(cvimgIn,cvimgIn,cv::COLOR_GRAY2BGR);
        for(j=0;j<nHeight;j++)
        {
            if(f_line[j]>=0)
            {
                Int32 di=(f_line[j]/4+0.5);
                Int32 dj=j/4;
                if(di>=0&&di<imageGasu.nWidth)
                {
                    cvimgIn.data[dj*imageGasu.nWidth*3+di*3]=255;
                    cvimgIn.data[dj*imageGasu.nWidth*3+di*3+1]=0;
                    cvimgIn.data[dj*imageGasu.nWidth*3+di*3+2]=0;
                }
            }
        }
    }
    solderjoints=false;
    cv_point.x=pointcloud[0].x;
    cv_point.y=pointcloud[0].y;
    namepoint.push_back(cv_point);   
    cv_point.x=pointcloud[pointcloud.size()-1].x;
    cv_point.y=pointcloud[pointcloud.size()-1].y;
    namepoint.push_back(cv_point);  

    return 0;
}

}