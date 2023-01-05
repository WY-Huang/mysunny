#include <cstdio>
#include <modbus/modbus.hpp>
#include <modbus.h>
#include <unistd.h>
#include <fileout/FileOut.h>
#include <fileout/E2proomData.h>
#include <memory>
#include <set>

namespace modbus
{

int Modbus::als104_task_parameter(int ddr,u_int16_t num)
{
    switch(ddr)
    {
        case ALS104_EXPOSURE_TIME_REG_ADD:
            e2proomdata.als104_exposure_time=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_exposure_time", num)});
            return 1;
        break;
        case ALS104_PINGJUN_REG_ADD:
            e2proomdata.als104_pingjun=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_pingjun", num)});
            return 1;
        break;
        case ALS104_B_YANMOFUZHU_REG_ADD:
            e2proomdata.als104_b_yanmofuzhu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_b_yanmofuzhu", num)});
            return 1;
        break;
        case ALS104_B_GUDINGQUYU_REG_ADD:
            e2proomdata.als104_b_gudingquyu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_b_gudingquyu", num)});
            return 1;
        break;
        case ALS104_WIDTHLIANTONGDIS_REG_ADD:
            e2proomdata.als104_widthliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_widthliantongdis", num)});
            return 1;
        break;
        case ALS104_HIGHLIANTONGDIS_REG_ADD:
            e2proomdata.als104_highliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_highliantongdis", num)});
            return 1;
        break;
        case ALS104_GUJIAERZHI_REG_ADD:
            e2proomdata.als104_gujiaerzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_gujiaerzhi", num)});
            return 1;
        break;
        case ALS104_JIGUANGHIGHT_REG_ADD:
            e2proomdata.als104_jiguanghight=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_jiguanghight", num)});
            return 1;
        break;
        case ALS104_JIGUANGLONG_REG_ADD:
            e2proomdata.als104_jiguanglong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_jiguanglong", num)});
            return 1;
        break;
        case ALS104_JIGUANGKUANDU_REG_ADD:
            e2proomdata.als104_jiguangkuandu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_jiguangkuandu", num)});
            return 1;
        break;
        case ALS104_UPDIF_REG_ADD:
            e2proomdata.als104_Updif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Updif", num)});
            return 1;
        break;
        case ALS104_UPDIFMIN_REG_ADD:
            e2proomdata.als104_Updifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Updifmin", num)});
            return 1;
        break;
        case ALS104_UPLONG_REG_ADD:
            e2proomdata.als104_Uplong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Uplong", num)});
            return 1;
        break;
        case ALS104_DOWNDIF_REG_ADD:
            e2proomdata.als104_Downdif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Downdif", num)});
            return 1;
        break;
        case ALS104_DOWNDIFMIN_REG_ADD:
            e2proomdata.als104_Downdifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Downdifmin", num)});
            return 1;
        break;
        case ALS104_DOWNDLONG_REG_ADD:
            e2proomdata.als104_Downdlong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Downdlong", num)});
            return 1;
        break;
        case ALS104_ST_DOWN_REG_ADD:
            e2proomdata.als104_St_Down=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_St_Down", num)});
            return 1;
        break;
        case ALS104_ED_DOWN_REG_ADD:
            e2proomdata.als104_Ed_Down=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Ed_Down", num)});
            return 1;
        break;
        case ALS104_ST_UP_REG_ADD:
            e2proomdata.als104_St_Up=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_St_Up", num)});
            return 1;
        break;
        case ALS104_ED_UP_REG_ADD:
            e2proomdata.als104_Ed_Up=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Ed_Up", num)});
            return 1;
        break;
        case ALS104_UPDIF2_REG_ADD:
            e2proomdata.als104_Updif2=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Updif2", num)});
            return 1;
        break;
        case ALS104_UPDIFMIN2_REG_ADD:
            e2proomdata.als104_Updifmin2=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Updifmin2", num)});
            return 1;
        break;
        case ALS104_DIS_CENTER_ST_REG_ADD:
            e2proomdata.als104_dis_center_st=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_dis_center_st", num)});
            return 1;
        break;
        case ALS104_DIS_CENTER_ED_REG_ADD:
            e2proomdata.als104_dis_center_ed=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_dis_center_ed", num)});
            return 1;
        break;
        case ALS104_B_OPENGUDINGDIMIAN_REG_ADD:
            e2proomdata.als104_b_opengudingdimian=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_b_opengudingdimian", num)});
            return 1;
        break;
        case ALS104_DIMIANPANGDINGJULI_REG_ADD:
            e2proomdata.als104_dimianpangdingjuli=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_dimianpangdingjuli", num)});
            return 1;
        break;
        case ALS104_DIMIANPINGJUNSHUNUM_REG_ADD:
            e2proomdata.als104_dimianpingjunshunum=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_dimianpingjunshunum", num)});
            return 1;
        break;
        case ALS104_DIS_CENTER_ST2_REG_ADD:
            e2proomdata.als104_dis_center_st2=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_dis_center_st2", num)});
            return 1;
        break;
        case ALS104_DIS_CENTER_ED2_REG_ADD:
            e2proomdata.als104_dis_center_ed2=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_dis_center_ed2", num)});
            return 1;
        break;
        case ALS104_DIS_CENTER_ST3_REG_ADD:
            e2proomdata.als104_dis_center_st3=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_dis_center_st3", num)});
            return 1;
        break;
        case ALS104_DIS_CENTER_ED3_REG_ADD:
            e2proomdata.als104_dis_center_ed3=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_dis_center_ed3", num)});
            return 1;
        break;
        case ALS104_XUEXIJULI_REG_ADD:
            e2proomdata.als104_xuexijuli=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_xuexijuli", num)});
            return 1;
        break;
        case ALS104_B_PINGPOWENGDING_REG_ADD:
            e2proomdata.als104_b_pingpowending=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_b_pingpowending", num)});
            return 1;
        break;
        case ALS104_PINGPOWENGDING_DIS_REG_ADD:
            e2proomdata.als104_pingpowending_dis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_pingpowending_dis", num)});
            return 1;
        break;
        case ALS104_B_XIELVOPEN_REG_ADD:
            e2proomdata.als104_b_xielvopen=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_b_xielvopen", num)});
            return 1;
        break;
        case ALS104_XIELVFANWEI_REG_ADD:
            e2proomdata.als104_xielvfanwei=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_xielvfanwei", num)});
            return 1;
        break;
        case ALS104_UPLONG2_REG_ADD:
            e2proomdata.als104_Uplong2=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Uplong2", num)});
            return 1;
        break;
        case ALS104_CEBANKONGDONGDIS_REG_ADD:
            e2proomdata.als104_cebankongdongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_cebankongdongdis", num)});
            return 1;
        break;
        case ALS104_QIATOUQUWEI_REG_ADD:
            e2proomdata.als104_qiatouquweijuli=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_qiatouquweijuli", num)});
            return 1;
        break;

        case ALS104_INIT_REG_ADD:
            if(num==1)
            {
                e2proomdata.init_als104_para();
                init_als104_parameter();
                parameterport_mapping->tab_registers[ALS104_INIT_REG_ADD]=0;
            }
            return 1;
  
        default:
        break;
    }
    return 0;
}

void Modbus::init_als104_parameter()
{
    parameterport_mapping->tab_registers[ALS104_EXPOSURE_TIME_REG_ADD]=e2proomdata.als104_exposure_time;
    parameterport_mapping->tab_registers[ALS104_PINGJUN_REG_ADD]=e2proomdata.als104_pingjun;
    parameterport_mapping->tab_registers[ALS104_B_YANMOFUZHU_REG_ADD]=e2proomdata.als104_b_yanmofuzhu;
    parameterport_mapping->tab_registers[ALS104_B_GUDINGQUYU_REG_ADD]=e2proomdata.als104_b_gudingquyu;
    parameterport_mapping->tab_registers[ALS104_WIDTHLIANTONGDIS_REG_ADD]=e2proomdata.als104_widthliantongdis;
    parameterport_mapping->tab_registers[ALS104_HIGHLIANTONGDIS_REG_ADD]=e2proomdata.als104_highliantongdis;
    parameterport_mapping->tab_registers[ALS104_GUJIAERZHI_REG_ADD]=e2proomdata.als104_gujiaerzhi;
    parameterport_mapping->tab_registers[ALS104_JIGUANGHIGHT_REG_ADD]=e2proomdata.als104_jiguanghight;
    parameterport_mapping->tab_registers[ALS104_JIGUANGLONG_REG_ADD]=e2proomdata.als104_jiguanglong;
    parameterport_mapping->tab_registers[ALS104_JIGUANGKUANDU_REG_ADD]=e2proomdata.als104_jiguangkuandu;
    parameterport_mapping->tab_registers[ALS104_UPDIF_REG_ADD]=e2proomdata.als104_Updif;
    parameterport_mapping->tab_registers[ALS104_UPDIFMIN_REG_ADD]=e2proomdata.als104_Updifmin;
    parameterport_mapping->tab_registers[ALS104_UPLONG_REG_ADD]=e2proomdata.als104_Uplong;
    parameterport_mapping->tab_registers[ALS104_DOWNDIF_REG_ADD]=e2proomdata.als104_Downdif;
    parameterport_mapping->tab_registers[ALS104_DOWNDIFMIN_REG_ADD]=e2proomdata.als104_Downdifmin;
    parameterport_mapping->tab_registers[ALS104_DOWNDLONG_REG_ADD]=e2proomdata.als104_Downdlong;
    parameterport_mapping->tab_registers[ALS104_ST_DOWN_REG_ADD]=e2proomdata.als104_St_Down;
    parameterport_mapping->tab_registers[ALS104_ED_DOWN_REG_ADD]=e2proomdata.als104_Ed_Down;
    parameterport_mapping->tab_registers[ALS104_ST_UP_REG_ADD]=e2proomdata.als104_St_Up;
    parameterport_mapping->tab_registers[ALS104_ED_UP_REG_ADD]=e2proomdata.als104_Ed_Up;
    parameterport_mapping->tab_registers[ALS104_UPDIF2_REG_ADD]=e2proomdata.als104_Updif2;
    parameterport_mapping->tab_registers[ALS104_UPDIFMIN2_REG_ADD]=e2proomdata.als104_Updifmin2;
    parameterport_mapping->tab_registers[ALS104_DIS_CENTER_ST_REG_ADD]=e2proomdata.als104_dis_center_st;
    parameterport_mapping->tab_registers[ALS104_DIS_CENTER_ED_REG_ADD]=e2proomdata.als104_dis_center_ed;
    parameterport_mapping->tab_registers[ALS104_B_OPENGUDINGDIMIAN_REG_ADD]=e2proomdata.als104_b_opengudingdimian;
    parameterport_mapping->tab_registers[ALS104_DIMIANPANGDINGJULI_REG_ADD]=e2proomdata.als104_dimianpangdingjuli;
    parameterport_mapping->tab_registers[ALS104_DIMIANPINGJUNSHUNUM_REG_ADD]=e2proomdata.als104_dimianpingjunshunum;
    parameterport_mapping->tab_registers[ALS104_DIS_CENTER_ST2_REG_ADD]=e2proomdata.als104_dis_center_st2;
    parameterport_mapping->tab_registers[ALS104_DIS_CENTER_ED2_REG_ADD]=e2proomdata.als104_dis_center_ed2;
    parameterport_mapping->tab_registers[ALS104_DIS_CENTER_ST3_REG_ADD]=e2proomdata.als104_dis_center_st3;
    parameterport_mapping->tab_registers[ALS104_DIS_CENTER_ED3_REG_ADD]=e2proomdata.als104_dis_center_ed3;
    parameterport_mapping->tab_registers[ALS104_XUEXIJULI_REG_ADD]=e2proomdata.als104_xuexijuli;
    parameterport_mapping->tab_registers[ALS104_B_PINGPOWENGDING_REG_ADD]=e2proomdata.als104_b_pingpowending;
    parameterport_mapping->tab_registers[ALS104_PINGPOWENGDING_DIS_REG_ADD]=e2proomdata.als104_pingpowending_dis;
    parameterport_mapping->tab_registers[ALS104_B_XIELVOPEN_REG_ADD]=e2proomdata.als104_b_xielvopen;
    parameterport_mapping->tab_registers[ALS104_XIELVFANWEI_REG_ADD]=e2proomdata.als104_xielvfanwei;
    parameterport_mapping->tab_registers[ALS104_UPLONG2_REG_ADD]=e2proomdata.als104_Uplong2;
    parameterport_mapping->tab_registers[ALS104_CEBANKONGDONGDIS_REG_ADD]=e2proomdata.als104_cebankongdongdis;
    parameterport_mapping->tab_registers[ALS104_QIATOUQUWEI_REG_ADD]=e2proomdata.als104_qiatouquweijuli;
}

}