#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

void E2proomData::Init_als104_E2proomData()
{
    als104_pingjun_min=E2POOM_ALG104_LASERIMAGEPOS_PINGJUN_MIN;
    als104_pingjun_use=E2POOM_ALG104_LASERIMAGEPOS_PINGJUN_USE;
    als104_pingjun_max=E2POOM_ALG104_LASERIMAGEPOS_PINGJUN_MAX;
    als104_exposure_time_min=E2POOM_ALG104_LASERIMAGEPOS_EXPOSURE_TIME_MIN;
    als104_exposure_time_max=E2POOM_ALG104_LASERIMAGEPOS_EXPOSURE_TIME_MAX;
    als104_exposure_time_use=E2POOM_ALG104_LASERIMAGEPOS_EXPOSURE_TIME_USE;
    als104_b_yanmofuzhu_min=E2POOM_ALG104_LASERIMAGEPOS_B_YANMOFUZHU_MIN;
    als104_b_yanmofuzhu_use=E2POOM_ALG104_LASERIMAGEPOS_B_YANMOFUZHU_USE;
    als104_b_yanmofuzhu_max=E2POOM_ALG104_LASERIMAGEPOS_B_YANMOFUZHU_MAX;
    als104_b_gudingquyu_min=E2POOM_ALG104_LASERIMAGEPOS_B_GUDINGQUYU_MIN;
    als104_b_gudingquyu_use=E2POOM_ALG104_LASERIMAGEPOS_B_GUDINGQUYU_USE;
    als104_b_gudingquyu_max=E2POOM_ALG104_LASERIMAGEPOS_B_GUDINGQUYU_MAX;
    als104_widthliantongdis_min=E2POOM_ALG104_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN;
    als104_widthliantongdis_use=E2POOM_ALG104_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE;
    als104_widthliantongdis_max=E2POOM_ALG104_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX;
    als104_highliantongdis_min=E2POOM_ALG104_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN;
    als104_highliantongdis_use=E2POOM_ALG104_LASERIMAGEPOS_HIGHLIANTONGDIS_USE;
    als104_highliantongdis_max=E2POOM_ALG104_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX;
    als104_gujiaerzhi_min=E2POOM_ALG104_LASERIMAGEPOS_GUJIAERZHI_MIN;
    als104_gujiaerzhi_use=E2POOM_ALG104_LASERIMAGEPOS_GUJIAERZHI_USE;
    als104_gujiaerzhi_max=E2POOM_ALG104_LASERIMAGEPOS_GUJIAERZHI_MAX;
    als104_jiguanghight_min=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGHIGHT_MIN;
    als104_jiguanghight_use=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGHIGHT_USE;
    als104_jiguanghight_max=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGHIGHT_MAX;
    als104_jiguanglong_min=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGLONG_MIN;
    als104_jiguanglong_use=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGLONG_USE;
    als104_jiguanglong_max=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGLONG_MAX;
    als104_jiguangkuandu_min=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGKUANDU_MIN;
    als104_jiguangkuandu_use=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGKUANDU_USE;
    als104_jiguangkuandu_max=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGKUANDU_MAX;
    als104_Updif_min=E2POOM_ALG104_LASERIMAGEPOS_UPDIF_MIN;
    als104_Updif_use=E2POOM_ALG104_LASERIMAGEPOS_UPDIF_USE;
    als104_Updif_max=E2POOM_ALG104_LASERIMAGEPOS_UPDIF_MAX;
    als104_Updifmin_min=E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN_MIN;
    als104_Updifmin_use=E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN_USE;
    als104_Updifmin_max=E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN_MAX;
    als104_Uplong_min=E2POOM_ALG104_LASERIMAGEPOS_UPLONG_MIN;
    als104_Uplong_use=E2POOM_ALG104_LASERIMAGEPOS_UPLONG_USE;
    als104_Uplong_max=E2POOM_ALG104_LASERIMAGEPOS_UPLONG_MAX;
    als104_Downdif_min=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIF_MIN;
    als104_Downdif_use=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIF_USE;
    als104_Downdif_max=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIF_MAX;
    als104_Downdifmin_min=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIFMIN_MIN;
    als104_Downdifmin_use=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIFMIN_USE;
    als104_Downdifmin_max=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIFMIN_MAX;
    als104_Downdlong_min=E2POOM_ALG104_LASERIMAGEPOS_DOWNDLONG_MIN;
    als104_Downdlong_use=E2POOM_ALG104_LASERIMAGEPOS_DOWNDLONG_USE;
    als104_Downdlong_max=E2POOM_ALG104_LASERIMAGEPOS_DOWNDLONG_MAX;
    als104_St_Down_min=E2POOM_ALG104_LASERIMAGEPOS_ST_DOWN_MIN;
    als104_St_Down_use=E2POOM_ALG104_LASERIMAGEPOS_ST_DOWN_USE;
    als104_St_Down_max=E2POOM_ALG104_LASERIMAGEPOS_ST_DOWN_MAX;
    als104_Ed_Down_min=E2POOM_ALG104_LASERIMAGEPOS_ED_DOWN_MIN;
    als104_Ed_Down_use=E2POOM_ALG104_LASERIMAGEPOS_ED_DOWN_USE;
    als104_Ed_Down_max=E2POOM_ALG104_LASERIMAGEPOS_ED_DOWN_MAX;
    als104_St_Up_min=E2POOM_ALG104_LASERIMAGEPOS_ST_UP_MIN;
    als104_St_Up_use=E2POOM_ALG104_LASERIMAGEPOS_ST_UP_USE;
    als104_St_Up_max=E2POOM_ALG104_LASERIMAGEPOS_ST_UP_MAX;
    als104_Ed_Up_min=E2POOM_ALG104_LASERIMAGEPOS_ED_UP_MIN;
    als104_Ed_Up_use=E2POOM_ALG104_LASERIMAGEPOS_ED_UP_USE;
    als104_Ed_Up_max=E2POOM_ALG104_LASERIMAGEPOS_ED_UP_MAX;
    als104_Updif2_min=E2POOM_ALG104_LASERIMAGEPOS_UPDIF2_MIN;
    als104_Updif2_use=E2POOM_ALG104_LASERIMAGEPOS_UPDIF2_USE;
    als104_Updif2_max=E2POOM_ALG104_LASERIMAGEPOS_UPDIF2_MAX;
    als104_Updifmin2_min=E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN2_MIN;
    als104_Updifmin2_use=E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN2_USE;
    als104_Updifmin2_max=E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN2_MAX;
    als104_dis_center_st_min=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST_MIN;
    als104_dis_center_st_use=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST_USE;
    als104_dis_center_st_max=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST_MAX;
    als104_dis_center_ed_min=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED_MIN;
    als104_dis_center_ed_use=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED_USE;
    als104_dis_center_ed_max=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED_MAX;
    als104_b_opengudingdimian_min=E2POOM_ALG104_LASERIMAGEPOS_B_OPENGUDINGDIMIAN_MIN;          
    als104_b_opengudingdimian_max=E2POOM_ALG104_LASERIMAGEPOS_B_OPENGUDINGDIMIAN_MAX;         
    als104_b_opengudingdimian_use=E2POOM_ALG104_LASERIMAGEPOS_B_OPENGUDINGDIMIAN_USE;          
    als104_dimianpangdingjuli_min=E2POOM_ALG104_LASERIMAGEPOS_DIMIANPANGDINGJULI_MIN;          
    als104_dimianpangdingjuli_max=E2POOM_ALG104_LASERIMAGEPOS_DIMIANPANGDINGJULI_MAX;          
    als104_dimianpangdingjuli_use=E2POOM_ALG104_LASERIMAGEPOS_DIMIANPANGDINGJULI_USE;          
    als104_dimianpingjunshunum_min=E2POOM_ALG104_LASERIMAGEPOS_DIMIANPINGJUNSHUNUM_MIN;         
    als104_dimianpingjunshunum_max=E2POOM_ALG104_LASERIMAGEPOS_DIMIANPINGJUNSHUNUM_MAX;         
    als104_dimianpingjunshunum_use=E2POOM_ALG104_LASERIMAGEPOS_DIMIANPINGJUNSHUNUM_USE;    
    als104_dis_center_st2_min=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST2_MIN;   
    als104_dis_center_st2_max=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST2_MAX;  
    als104_dis_center_st2_use=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST2_USE;
    als104_dis_center_ed2_min=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED2_MIN;   
    als104_dis_center_ed2_max=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED2_MAX;  
    als104_dis_center_ed2_use=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED2_USE;
    als104_dis_center_st3_min=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST3_MIN;   
    als104_dis_center_st3_max=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST3_MAX;  
    als104_dis_center_st3_use=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST3_USE;
    als104_dis_center_ed3_min=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED3_MIN;   
    als104_dis_center_ed3_max=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED3_MAX;  
    als104_dis_center_ed3_use=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED3_USE;
    als104_xuexijuli_min=E2POOM_ALG104_LASERIMAGEPOS_XUEXIJULI_MIN;
    als104_xuexijuli_max=E2POOM_ALG104_LASERIMAGEPOS_XUEXIJULI_MAX;
    als104_xuexijuli_use=E2POOM_ALG104_LASERIMAGEPOS_XUEXIJULI_USE;
    als104_b_pingpowending_min=E2POOM_ALG104_LASERIMAGEPOS_B_PINGPOWENGDING_MIN;
    als104_b_pingpowending_max=E2POOM_ALG104_LASERIMAGEPOS_B_PINGPOWENGDING_MAX;
    als104_b_pingpowending_use=E2POOM_ALG104_LASERIMAGEPOS_B_PINGPOWENGDING_USE;
    als104_pingpowending_dis_min=E2POOM_ALG104_LASERIMAGEPOS_PINGPOWENGDING_DIS_MIN;
    als104_pingpowending_dis_max=E2POOM_ALG104_LASERIMAGEPOS_PINGPOWENGDING_DIS_MAX;
    als104_pingpowending_dis_use=E2POOM_ALG104_LASERIMAGEPOS_PINGPOWENGDING_DIS_USE;
    als104_b_xielvopen_min=E2POOM_ALG104_LASERIMAGEPOS_B_XIELVOPEN_MIN;
    als104_b_xielvopen_max=E2POOM_ALG104_LASERIMAGEPOS_B_XIELVOPEN_MAX;
    als104_b_xielvopen_use=E2POOM_ALG104_LASERIMAGEPOS_B_XIELVOPEN_USE;
    als104_xielvfanwei_min=E2POOM_ALG104_LASERIMAGEPOS_XIELVFANWEI_MIN;
    als104_xielvfanwei_max=E2POOM_ALG104_LASERIMAGEPOS_XIELVFANWEI_MAX;
    als104_xielvfanwei_use=E2POOM_ALG104_LASERIMAGEPOS_XIELVFANWEI_USE;
    als104_Uplong2_min=E2POOM_ALG104_LASERIMAGEPOS_UPLONG2_MIN;
    als104_Uplong2_use=E2POOM_ALG104_LASERIMAGEPOS_UPLONG2_USE;
    als104_Uplong2_max=E2POOM_ALG104_LASERIMAGEPOS_UPLONG2_MAX;
    als104_cebankongdongdis_min=E2POOM_ALG104_LASERIMAGEPOS_CEBANKONGDONGDIS_MIN;
    als104_cebankongdongdis_use=E2POOM_ALG104_LASERIMAGEPOS_CEBANKONGDONGDIS_USE;
    als104_cebankongdongdis_max=E2POOM_ALG104_LASERIMAGEPOS_CEBANKONGDONGDIS_MAX;
    als104_qiatouquweijuli_min=E2POOM_ALG104_LASERIMAGEPOS_QIATOUQUWEI_MIN;
    als104_qiatouquweijuli_use=E2POOM_ALG104_LASERIMAGEPOS_QIATOUQUWEI_USE;
    als104_qiatouquweijuli_max=E2POOM_ALG104_LASERIMAGEPOS_QIATOUQUWEI_MAX;
}

void E2proomData::als104_check_para()
{
    if(als104_exposure_time<als104_exposure_time_min||als104_exposure_time>als104_exposure_time_max)
        als104_exposure_time=als104_exposure_time_use;
    if(als104_pingjun<als104_pingjun_min||als104_pingjun>als104_pingjun_max)
        als104_pingjun=als104_pingjun_use;
    if(als104_b_yanmofuzhu<als104_b_yanmofuzhu_min||als104_b_yanmofuzhu>als104_b_yanmofuzhu_max)
        als104_b_yanmofuzhu=als104_b_yanmofuzhu_use;
    if(als104_b_gudingquyu<als104_b_gudingquyu_min||als104_b_gudingquyu>als104_b_gudingquyu_max)
        als104_b_gudingquyu=als104_b_gudingquyu_use;
    if(als104_widthliantongdis<als104_widthliantongdis_min||als104_widthliantongdis>als104_widthliantongdis_max)
        als104_widthliantongdis=als104_widthliantongdis_use;
    if(als104_highliantongdis<als104_highliantongdis_min||als104_highliantongdis>als104_highliantongdis_max)
        als104_highliantongdis=als104_highliantongdis_use;
    if(als104_gujiaerzhi<als104_gujiaerzhi_min||als104_gujiaerzhi>als104_gujiaerzhi_max)
        als104_gujiaerzhi=als104_gujiaerzhi_use;
    if(als104_jiguanghight<als104_jiguanghight_min||als104_jiguanghight>als104_jiguanghight_max)
        als104_jiguanghight=als104_jiguanghight_use;
    if(als104_jiguanglong<als104_jiguanglong_min||als104_jiguanglong>als104_jiguanglong_max)
        als104_jiguanglong=als104_jiguanglong_use;
    if(als104_jiguangkuandu<als104_jiguangkuandu_min||als104_jiguangkuandu>als104_jiguangkuandu_max)
        als104_jiguangkuandu=als104_jiguangkuandu_use;
    if(als104_Updif<als104_Updif_min||als104_Updif>als104_Updif_max)
        als104_Updif=als104_Updif_use;
    if(als104_Updifmin<als104_Updifmin_min||als104_Updifmin>als104_Updifmin_max)
        als104_Updifmin=als104_Updifmin_use;
    if(als104_Uplong<als104_Uplong_min||als104_Uplong>als104_Uplong_max)
        als104_Uplong=als104_Uplong_use;
    if(als104_Downdif<als104_Downdif_min||als104_Downdif>als104_Downdif_max)
        als104_Downdif=als104_Downdif_use;
    if(als104_Downdifmin<als104_Downdifmin_min||als104_Downdifmin>als104_Downdifmin_max)
        als104_Downdifmin=als104_Downdifmin_use;
    if(als104_Downdlong<als104_Downdlong_min||als104_Downdlong>als104_Downdlong_max)
        als104_Downdlong=als104_Downdlong_use;    
    if(als104_St_Down<als104_St_Down_min||als104_St_Down>als104_St_Down_max)
        als104_St_Down=als104_St_Down_use;
    if(als104_Ed_Down<als104_Ed_Down_min||als104_Ed_Down>als104_Ed_Down_max)
        als104_Ed_Down=als104_Ed_Down_use;
    if(als104_St_Up<als104_St_Up_min||als104_St_Up>als104_St_Up_max)
        als104_St_Up=als104_St_Up_use;
    if(als104_Ed_Up<als104_Ed_Up_min||als104_Ed_Up>als104_Ed_Up_max)
        als104_Ed_Up=als104_Ed_Up_use;
    if(als104_Updif2<als104_Updif2_min||als104_Updif2>als104_Updif2_max)
        als104_Updif2=als104_Updif2_use;
    if(als104_Updifmin2<als104_Updifmin2_min||als104_Updifmin2>als104_Updifmin2_max)
        als104_Updifmin2=als104_Updifmin2_use;
    if(als104_dis_center_st<als104_dis_center_st_min||als104_dis_center_st>als104_dis_center_st_max)
        als104_dis_center_st=als104_dis_center_st_use;
    if(als104_dis_center_ed<als104_dis_center_ed_min||als104_dis_center_ed>als104_dis_center_ed_max)
        als104_dis_center_ed=als104_dis_center_ed_use;
    if(als104_b_opengudingdimian<als104_b_opengudingdimian_min||als104_b_opengudingdimian>als104_b_opengudingdimian_max)
        als104_b_opengudingdimian=als104_b_opengudingdimian_use;
    if(als104_dimianpangdingjuli<als104_dimianpangdingjuli_min||als104_dimianpangdingjuli>als104_dimianpangdingjuli_max)
        als104_dimianpangdingjuli=als104_dimianpangdingjuli_use;
    if(als104_dimianpingjunshunum<als104_dimianpingjunshunum_min||als104_dimianpingjunshunum>als104_dimianpingjunshunum_max)
        als104_dimianpingjunshunum=als104_dimianpingjunshunum_use;
    if(als104_dis_center_st2<als104_dis_center_st2_min||als104_dis_center_st2>als104_dis_center_st2_max)
        als104_dis_center_st2=als104_dis_center_st2_use;
    if(als104_dis_center_ed2<als104_dis_center_ed2_min||als104_dis_center_ed2>als104_dis_center_ed2_max)
        als104_dis_center_ed2=als104_dis_center_ed2_use;
    if(als104_dis_center_st3<als104_dis_center_st3_min||als104_dis_center_st3>als104_dis_center_st3_max)
        als104_dis_center_st3=als104_dis_center_st3_use;
    if(als104_dis_center_ed3<als104_dis_center_ed3_min||als104_dis_center_ed3>als104_dis_center_ed3_max)
        als104_dis_center_ed3=als104_dis_center_ed3_use;
    if(als104_xuexijuli<als104_xuexijuli_min||als104_xuexijuli>als104_xuexijuli_max)
        als104_xuexijuli=als104_xuexijuli_use;
    if(als104_b_pingpowending<als104_b_pingpowending_min||als104_b_pingpowending>als104_b_pingpowending_max)
        als104_b_pingpowending=als104_b_pingpowending_use;
    if(als104_pingpowending_dis<als104_pingpowending_dis_min||als104_pingpowending_dis>als104_pingpowending_dis_max)
        als104_pingpowending_dis=als104_pingpowending_dis_use;
    if(als104_b_xielvopen<als104_b_xielvopen_min||als104_b_xielvopen>als104_b_xielvopen_max)
        als104_b_xielvopen=als104_b_xielvopen_use;
    if(als104_xielvfanwei<als104_xielvfanwei_min||als104_xielvfanwei>als104_xielvfanwei_max)
        als104_xielvfanwei=als104_xielvfanwei_use;
    if(als104_Uplong2<als104_Uplong2_min||als104_Uplong2>als104_Uplong2_max)
        als104_Uplong2=als104_Uplong2_use;
    if(als104_cebankongdongdis<als104_cebankongdongdis_min||als104_cebankongdongdis>als104_cebankongdongdis_max)
        als104_cebankongdongdis=als104_cebankongdongdis_use;
    if(als104_qiatouquweijuli<als104_qiatouquweijuli_min||als104_qiatouquweijuli>als104_qiatouquweijuli_max)
        als104_qiatouquweijuli=als104_qiatouquweijuli_use;
}

void E2proomData::als104_read_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ALG104_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_ALG104_LASERIMAGEPOS_SYSPATH_MOTO,buff,E2POOM_ALG104_LASERIMAGEPOS_SAVEBUFF))
    {
        init_als104_para();
        if(buff!=NULL)
        {
          delete []buff;
          buff=NULL;
        }
    }
    else
    {
      Uint16 *ui16_p;
      Int16 *i16_p;

      ui16_p = (Uint16*)buff;
      als104_exposure_time=*ui16_p;
      ui16_p++;
      i16_p = (Int16*)ui16_p;
      als104_pingjun=*i16_p;
      i16_p++;
      als104_b_yanmofuzhu=*i16_p;
      i16_p++;
      als104_b_gudingquyu=*i16_p;
      i16_p++;
      als104_widthliantongdis=*i16_p;
      i16_p++;
      als104_highliantongdis=*i16_p;
      i16_p++;
      als104_gujiaerzhi=*i16_p;
      i16_p++;
      als104_jiguanghight=*i16_p;
      i16_p++;
      als104_jiguanglong=*i16_p;
      i16_p++;
      als104_jiguangkuandu=*i16_p;
      i16_p++;
      als104_Updif=*i16_p;
      i16_p++;
      als104_Updifmin=*i16_p;
      i16_p++;
      als104_Uplong=*i16_p;
      i16_p++;
      als104_Downdif=*i16_p;
      i16_p++;
      als104_Downdifmin=*i16_p;
      i16_p++;
      als104_Downdlong=*i16_p;
      i16_p++;
      als104_St_Down=*i16_p;
      i16_p++;
      als104_Ed_Down=*i16_p;
      i16_p++;
      als104_St_Up=*i16_p;
      i16_p++;
      als104_Ed_Up=*i16_p;
      i16_p++;
      als104_Updif2=*i16_p;
      i16_p++;
      als104_Updifmin2=*i16_p;
      i16_p++;
      als104_dis_center_st=*i16_p;
      i16_p++;
      als104_dis_center_ed=*i16_p;
      i16_p++;
      als104_b_opengudingdimian=*i16_p;
      i16_p++;
      als104_dimianpangdingjuli=*i16_p;
      i16_p++;
      als104_dimianpingjunshunum=*i16_p;
      i16_p++;
      als104_dis_center_st2=*i16_p;
      i16_p++;
      als104_dis_center_ed2=*i16_p;
      i16_p++;
      als104_dis_center_st3=*i16_p;
      i16_p++;
      als104_dis_center_ed3=*i16_p;
      i16_p++;
      als104_xuexijuli=*i16_p;
      i16_p++;
      als104_b_pingpowending=*i16_p;
      i16_p++;
      als104_pingpowending_dis=*i16_p;
      i16_p++;
      als104_b_xielvopen=*i16_p;
      i16_p++;
      als104_xielvfanwei=*i16_p;
      i16_p++;
      als104_Uplong2=*i16_p;
      i16_p++;
      als104_cebankongdongdis=*i16_p;
      i16_p++;
      als104_qiatouquweijuli=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

}

void E2proomData::write_als104_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG104_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *ui16_p;
    Int16 *i16_p;

    ui16_p = (Uint16*)buff;
    *ui16_p=als104_exposure_time;
    ui16_p++;
    i16_p = (Int16*)ui16_p;
    *i16_p=als104_pingjun;
    i16_p++;
    *i16_p=als104_b_yanmofuzhu;
    i16_p++;
    *i16_p=als104_b_gudingquyu;
    i16_p++;
    *i16_p=als104_widthliantongdis;
    i16_p++;
    *i16_p=als104_highliantongdis;
    i16_p++;
    *i16_p=als104_gujiaerzhi;
    i16_p++;
    *i16_p=als104_jiguanghight;
    i16_p++;
    *i16_p=als104_jiguanglong;
    i16_p++;
    *i16_p=als104_jiguangkuandu;
    i16_p++;
    *i16_p=als104_Updif;
    i16_p++;
    *i16_p=als104_Updifmin;
    i16_p++;
    *i16_p=als104_Uplong;
    i16_p++;
    *i16_p=als104_Downdif;
    i16_p++;
    *i16_p=als104_Downdifmin;
    i16_p++;
    *i16_p=als104_Downdlong;
    i16_p++;
    *i16_p=als104_St_Down;
    i16_p++;
    *i16_p=als104_Ed_Down;
    i16_p++;
    *i16_p=als104_St_Up;
    i16_p++;
    *i16_p=als104_Ed_Up;
    i16_p++;
    *i16_p=als104_Updif2;
    i16_p++;
    *i16_p=als104_Updifmin2;
    i16_p++;
    *i16_p=als104_dis_center_st;
    i16_p++;
    *i16_p=als104_dis_center_ed;
    i16_p++;
    *i16_p=als104_b_opengudingdimian;
    i16_p++;
    *i16_p=als104_dimianpangdingjuli;
    i16_p++;
    *i16_p=als104_dimianpingjunshunum;
    i16_p++;
    *i16_p=als104_dis_center_st2;
    i16_p++;
    *i16_p=als104_dis_center_ed2;
    i16_p++;
    *i16_p=als104_dis_center_st3;
    i16_p++;
    *i16_p=als104_dis_center_ed3;
    i16_p++;
    *i16_p=als104_xuexijuli;
    i16_p++;
    *i16_p=als104_b_pingpowending;
    i16_p++;
    *i16_p=als104_pingpowending_dis;
    i16_p++;
    *i16_p=als104_b_xielvopen;
    i16_p++;
    *i16_p=als104_xielvfanwei;
    i16_p++;
    *i16_p=als104_Uplong2;
    i16_p++;
    *i16_p=als104_cebankongdongdis;
    i16_p++;
    *i16_p=als104_qiatouquweijuli;
    i16_p++;
    

    fo.WriteFile(E2POOM_ALG104_LASERIMAGEPOS_SYSPATH_MOTO,buff,E2POOM_ALG104_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als104_para()
{
    als104_exposure_time=als104_exposure_time_use;
    als104_pingjun=als104_pingjun_use;
    als104_b_yanmofuzhu=als104_b_yanmofuzhu_use;
    als104_b_gudingquyu=als104_b_gudingquyu_use;
    als104_widthliantongdis=als104_widthliantongdis_use;
    als104_highliantongdis=als104_highliantongdis_use;
    als104_gujiaerzhi=als104_gujiaerzhi_use;
    als104_jiguanghight=als104_jiguanghight_use;
    als104_jiguanglong=als104_jiguanglong_use;
    als104_jiguangkuandu=als104_jiguangkuandu_use;
    als104_Updif=als104_Updif_use;
    als104_Updifmin=als104_Updifmin_use;
    als104_Uplong=als104_Uplong_use;
    als104_Downdif=als104_Downdif_use;
    als104_Downdifmin=als104_Downdifmin_use;
    als104_Downdlong=als104_Downdlong_use;
    als104_St_Down=als104_St_Down_use;
    als104_Ed_Down=als104_Ed_Down_use;
    als104_St_Up=als104_St_Up_use;
    als104_Ed_Up=als104_Ed_Up_use;
    als104_Updif2=als104_Updif2_use;
    als104_Updifmin2=als104_Updifmin2_use;
    als104_dis_center_st=als104_dis_center_st_use;
    als104_dis_center_ed=als104_dis_center_ed_use;
    als104_b_opengudingdimian=als104_b_opengudingdimian_use;
    als104_dimianpangdingjuli=als104_dimianpangdingjuli_use;
    als104_dimianpingjunshunum=als104_dimianpingjunshunum_use;
    als104_dis_center_st2=als104_dis_center_st2_use;
    als104_dis_center_ed2=als104_dis_center_ed2_use;
    als104_dis_center_st3=als104_dis_center_st3_use;
    als104_dis_center_ed3=als104_dis_center_ed3_use;
    als104_xuexijuli=als104_xuexijuli_use;
    als104_b_pingpowending=als104_b_pingpowending_use;
    als104_pingpowending_dis=als104_pingpowending_dis_use;
    als104_b_xielvopen=als104_b_xielvopen_use;
    als104_xielvfanwei=als104_xielvfanwei_use;
    als104_Uplong2=als104_Uplong2_use;
    als104_cebankongdongdis=als104_cebankongdongdis_use;
    als104_qiatouquweijuli=als104_qiatouquweijuli_use;
}