#ifndef E2PROOMDATA_H
#define E2PROOMDATA_H

#include "fileout/tistdtypes.h"
#include "fileout/FileOut.h"
#include "float.h"

//任务号设置
#define E2POOM_TASK_NUM_SAVEBUFF           8
#define E2POOM_TASK_NUM_SYSPATH_MOTO       "./SAVE/E2P_TASK_NUM_DLG.bsd" 
#define E2POOM_TASK_NUM_MIN                0
#define E2POOM_TASK_NUM_USE                0
#define E2POOM_TASK_NUM_MAX                65535 

//机器人设置
#define E2POOM_ROBOT_SAVEBUFF              20
#define E2POOM_ROBOT_SYSPATH_MOTO			"./SAVE/E2P_ROBOT_DLG.bsd"

#define E2POOM_ROBOT_MOD_NULL               0        //无机器人
#define E2POOM_ROBOT_MOD_ZHICHANG           1        //智昌机器人
#define E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI  2        //智昌川崎机器人
#define E2POOM_ROBOT_MOD_MOKA_NABOTE        3        //摩卡纳博特机器人
#define E2POOM_ROBOT_PORT_MIN               1503     //机器人通信最小端口
#define E2POOM_ROBOT_PORT_USE               1503     //机器人通信默认端口
#define E2POOM_ROBOT_PORT_MAX               65535    //机器人通信最大端口


//算法100参数
#define E2POOM_ALG100_LASERIMAGEPOS_SAVEBUFF              54
#define E2POOM_ALG100_LASERIMAGEPOS_SYSPATH_MOTO			"./SAVE/E2P_MEASUREMENT_100.bsd"

#define E2POOM_ALG100_LASERIMAGEPOS_EXPOSURE_TIME_MIN				20         //曝光最小值
#define E2POOM_ALG100_LASERIMAGEPOS_EXPOSURE_TIME_USE				10000      //曝光默认值   
#define E2POOM_ALG100_LASERIMAGEPOS_EXPOSURE_TIME_MAX				65535      //曝光最大值'
#define E2POOM_ALG100_LASERIMAGEPOS_PINGJUN_MIN                     0
#define E2POOM_ALG100_LASERIMAGEPOS_PINGJUN_USE                     15
#define E2POOM_ALG100_LASERIMAGEPOS_PINGJUN_MAX                     255
#define E2POOM_ALG100_LASERIMAGEPOS_B_YANMOFUZHU_MIN                0 
#define E2POOM_ALG100_LASERIMAGEPOS_B_YANMOFUZHU_USE                1
#define E2POOM_ALG100_LASERIMAGEPOS_B_YANMOFUZHU_MAX                1
#define E2POOM_ALG100_LASERIMAGEPOS_B_GUDINGQUYU_MIN                0 
#define E2POOM_ALG100_LASERIMAGEPOS_B_GUDINGQUYU_USE                0
#define E2POOM_ALG100_LASERIMAGEPOS_B_GUDINGQUYU_MAX                1
#define E2POOM_ALG100_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN            0 
#define E2POOM_ALG100_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE            6
#define E2POOM_ALG100_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX            500
#define E2POOM_ALG100_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN             0 
#define E2POOM_ALG100_LASERIMAGEPOS_HIGHLIANTONGDIS_USE             15
#define E2POOM_ALG100_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX             500
#define E2POOM_ALG100_LASERIMAGEPOS_GUJIAERZHI_MIN                  0 
#define E2POOM_ALG100_LASERIMAGEPOS_GUJIAERZHI_USE                  160
#define E2POOM_ALG100_LASERIMAGEPOS_GUJIAERZHI_MAX                  255
#define E2POOM_ALG100_LASERIMAGEPOS_JIGUANGHIGHT_MIN                0 
#define E2POOM_ALG100_LASERIMAGEPOS_JIGUANGHIGHT_USE                50
#define E2POOM_ALG100_LASERIMAGEPOS_JIGUANGHIGHT_MAX                255
#define E2POOM_ALG100_LASERIMAGEPOS_JIGUANGLONG_MIN                 0 
#define E2POOM_ALG100_LASERIMAGEPOS_JIGUANGLONG_USE                 20
#define E2POOM_ALG100_LASERIMAGEPOS_JIGUANGLONG_MAX                 255
#define E2POOM_ALG100_LASERIMAGEPOS_JIGUANGKUANDU_MIN               0 
#define E2POOM_ALG100_LASERIMAGEPOS_JIGUANGKUANDU_USE               4
#define E2POOM_ALG100_LASERIMAGEPOS_JIGUANGKUANDU_MAX               20
#define E2POOM_ALG100_LASERIMAGEPOS_UPDIF_MIN                      -255 
#define E2POOM_ALG100_LASERIMAGEPOS_UPDIF_USE                       0
#define E2POOM_ALG100_LASERIMAGEPOS_UPDIF_MAX                       255
#define E2POOM_ALG100_LASERIMAGEPOS_UPDIFMIN_MIN                   -255 
#define E2POOM_ALG100_LASERIMAGEPOS_UPDIFMIN_USE                   -5
#define E2POOM_ALG100_LASERIMAGEPOS_UPDIFMIN_MAX                    255
#define E2POOM_ALG100_LASERIMAGEPOS_UPLONG_MIN                      1
#define E2POOM_ALG100_LASERIMAGEPOS_UPLONG_USE                      5
#define E2POOM_ALG100_LASERIMAGEPOS_UPLONG_MAX                      500
#define E2POOM_ALG100_LASERIMAGEPOS_DOWNDIF_MIN                    -255 
#define E2POOM_ALG100_LASERIMAGEPOS_DOWNDIF_USE                     0
#define E2POOM_ALG100_LASERIMAGEPOS_DOWNDIF_MAX                     255
#define E2POOM_ALG100_LASERIMAGEPOS_DOWNDIFMIN_MIN                 -255 
#define E2POOM_ALG100_LASERIMAGEPOS_DOWNDIFMIN_USE                  5
#define E2POOM_ALG100_LASERIMAGEPOS_DOWNDIFMIN_MAX                  255
#define E2POOM_ALG100_LASERIMAGEPOS_DOWNDLONG_MIN                   1
#define E2POOM_ALG100_LASERIMAGEPOS_DOWNDLONG_USE                   5
#define E2POOM_ALG100_LASERIMAGEPOS_DOWNDLONG_MAX                   500
#define E2POOM_ALG100_LASERIMAGEPOS_DUANXIANERZHI_MIN               0
#define E2POOM_ALG100_LASERIMAGEPOS_DUANXIANERZHI_USE               180
#define E2POOM_ALG100_LASERIMAGEPOS_DUANXIANERZHI_MAX               255
#define E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE_MIN                   80
#define E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE_USE                   150
#define E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE_MAX                   500
#define E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE2_MIN                  30
#define E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE2_USE                  60
#define E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE2_MAX                  500
#define E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMAX_MIN           30
#define E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMAX_USE           160
#define E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMAX_MAX           500
#define E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMIN_MIN           1
#define E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMIN_USE           25
#define E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMIN_MAX           500
#define E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ST_MIN               0
#define E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ST_USE               0
#define E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ST_MAX               500
#define E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ED_MIN               0
#define E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ED_USE               500
#define E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ED_MAX               500

//算法101参数
#define E2POOM_ALG101_LASERIMAGEPOS_SAVEBUFF              54
#define E2POOM_ALG101_LASERIMAGEPOS_SYSPATH_MOTO			"./SAVE/E2P_MEASUREMENT_101.bsd"

#define E2POOM_ALG101_LASERIMAGEPOS_EXPOSURE_TIME_MIN				20         //曝光最小值
#define E2POOM_ALG101_LASERIMAGEPOS_EXPOSURE_TIME_USE				10000      //曝光默认值   
#define E2POOM_ALG101_LASERIMAGEPOS_EXPOSURE_TIME_MAX				65535      //曝光最大值'
#define E2POOM_ALG101_LASERIMAGEPOS_PINGJUN_MIN                     0
#define E2POOM_ALG101_LASERIMAGEPOS_PINGJUN_USE                     15
#define E2POOM_ALG101_LASERIMAGEPOS_PINGJUN_MAX                     255
#define E2POOM_ALG101_LASERIMAGEPOS_B_YANMOFUZHU_MIN                0 
#define E2POOM_ALG101_LASERIMAGEPOS_B_YANMOFUZHU_USE                1
#define E2POOM_ALG101_LASERIMAGEPOS_B_YANMOFUZHU_MAX                1
#define E2POOM_ALG101_LASERIMAGEPOS_B_GUDINGQUYU_MIN                0 
#define E2POOM_ALG101_LASERIMAGEPOS_B_GUDINGQUYU_USE                0
#define E2POOM_ALG101_LASERIMAGEPOS_B_GUDINGQUYU_MAX                1
#define E2POOM_ALG101_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN            0 
#define E2POOM_ALG101_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE            6
#define E2POOM_ALG101_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX            500
#define E2POOM_ALG101_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN             0 
#define E2POOM_ALG101_LASERIMAGEPOS_HIGHLIANTONGDIS_USE             15
#define E2POOM_ALG101_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX             500
#define E2POOM_ALG101_LASERIMAGEPOS_GUJIAERZHI_MIN                  0 
#define E2POOM_ALG101_LASERIMAGEPOS_GUJIAERZHI_USE                  160
#define E2POOM_ALG101_LASERIMAGEPOS_GUJIAERZHI_MAX                  255
#define E2POOM_ALG101_LASERIMAGEPOS_JIGUANGHIGHT_MIN                0 
#define E2POOM_ALG101_LASERIMAGEPOS_JIGUANGHIGHT_USE                50
#define E2POOM_ALG101_LASERIMAGEPOS_JIGUANGHIGHT_MAX                255
#define E2POOM_ALG101_LASERIMAGEPOS_JIGUANGLONG_MIN                 0 
#define E2POOM_ALG101_LASERIMAGEPOS_JIGUANGLONG_USE                 20
#define E2POOM_ALG101_LASERIMAGEPOS_JIGUANGLONG_MAX                 255
#define E2POOM_ALG101_LASERIMAGEPOS_JIGUANGKUANDU_MIN               0 
#define E2POOM_ALG101_LASERIMAGEPOS_JIGUANGKUANDU_USE               4
#define E2POOM_ALG101_LASERIMAGEPOS_JIGUANGKUANDU_MAX               20
#define E2POOM_ALG101_LASERIMAGEPOS_UPDIF_MIN                      -255 
#define E2POOM_ALG101_LASERIMAGEPOS_UPDIF_USE                       0
#define E2POOM_ALG101_LASERIMAGEPOS_UPDIF_MAX                       255
#define E2POOM_ALG101_LASERIMAGEPOS_UPDIFMIN_MIN                   -255 
#define E2POOM_ALG101_LASERIMAGEPOS_UPDIFMIN_USE                    5
#define E2POOM_ALG101_LASERIMAGEPOS_UPDIFMIN_MAX                    255
#define E2POOM_ALG101_LASERIMAGEPOS_UPLONG_MIN                      1
#define E2POOM_ALG101_LASERIMAGEPOS_UPLONG_USE                      5
#define E2POOM_ALG101_LASERIMAGEPOS_UPLONG_MAX                      500
#define E2POOM_ALG101_LASERIMAGEPOS_DOWNDIF_MIN                    -255 
#define E2POOM_ALG101_LASERIMAGEPOS_DOWNDIF_USE                     0
#define E2POOM_ALG101_LASERIMAGEPOS_DOWNDIF_MAX                     255
#define E2POOM_ALG101_LASERIMAGEPOS_DOWNDIFMIN_MIN                 -255 
#define E2POOM_ALG101_LASERIMAGEPOS_DOWNDIFMIN_USE                 -5
#define E2POOM_ALG101_LASERIMAGEPOS_DOWNDIFMIN_MAX                  255
#define E2POOM_ALG101_LASERIMAGEPOS_DOWNDLONG_MIN                   1
#define E2POOM_ALG101_LASERIMAGEPOS_DOWNDLONG_USE                   5
#define E2POOM_ALG101_LASERIMAGEPOS_DOWNDLONG_MAX                   500
#define E2POOM_ALG101_LASERIMAGEPOS_DUANXIANERZHI_MIN               0
#define E2POOM_ALG101_LASERIMAGEPOS_DUANXIANERZHI_USE               180
#define E2POOM_ALG101_LASERIMAGEPOS_DUANXIANERZHI_MAX               255
#define E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE_MIN                   80
#define E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE_USE                   150
#define E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE_MAX                   500
#define E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE2_MIN                  30
#define E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE2_USE                  60
#define E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE2_MAX                  500
#define E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMAX_MIN           30
#define E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMAX_USE           160
#define E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMAX_MAX           500
#define E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMIN_MIN           1
#define E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMIN_USE           25
#define E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMIN_MAX           500
#define E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ST_MIN               0
#define E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ST_USE               0
#define E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ST_MAX               500
#define E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ED_MIN               0
#define E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ED_USE               500
#define E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ED_MAX               500

//算法102参数
#define E2POOM_ALG102_LASERIMAGEPOS_SAVEBUFF              88
#define E2POOM_ALG102_LASERIMAGEPOS_SYSPATH_MOTO			"./SAVE/E2P_MEASUREMENT_102.bsd"

#define E2POOM_ALG102_LASERIMAGEPOS_EXPOSURE_TIME_MIN				20         //曝光最小值
#define E2POOM_ALG102_LASERIMAGEPOS_EXPOSURE_TIME_USE				10000      //曝光默认值   
#define E2POOM_ALG102_LASERIMAGEPOS_EXPOSURE_TIME_MAX				65535      //曝光最大值
#define E2POOM_ALG102_LASERIMAGEPOS_PINGJUN_MIN                     0
#define E2POOM_ALG102_LASERIMAGEPOS_PINGJUN_USE                     15
#define E2POOM_ALG102_LASERIMAGEPOS_PINGJUN_MAX                     255
#define E2POOM_ALG102_LASERIMAGEPOS_B_YANMOFUZHU_MIN                0 
#define E2POOM_ALG102_LASERIMAGEPOS_B_YANMOFUZHU_USE                1
#define E2POOM_ALG102_LASERIMAGEPOS_B_YANMOFUZHU_MAX                1
#define E2POOM_ALG102_LASERIMAGEPOS_B_GUDINGQUYU_MIN                0 
#define E2POOM_ALG102_LASERIMAGEPOS_B_GUDINGQUYU_USE                1
#define E2POOM_ALG102_LASERIMAGEPOS_B_GUDINGQUYU_MAX                1
#define E2POOM_ALG102_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN            0 
#define E2POOM_ALG102_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE            4
#define E2POOM_ALG102_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX            500
#define E2POOM_ALG102_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN             0 
#define E2POOM_ALG102_LASERIMAGEPOS_HIGHLIANTONGDIS_USE             15
#define E2POOM_ALG102_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX             500
#define E2POOM_ALG102_LASERIMAGEPOS_GUJIAERZHI_MIN                  0 
#define E2POOM_ALG102_LASERIMAGEPOS_GUJIAERZHI_USE                  160
#define E2POOM_ALG102_LASERIMAGEPOS_GUJIAERZHI_MAX                  255
#define E2POOM_ALG102_LASERIMAGEPOS_JIGUANGHIGHT_MIN                0 
#define E2POOM_ALG102_LASERIMAGEPOS_JIGUANGHIGHT_USE                50
#define E2POOM_ALG102_LASERIMAGEPOS_JIGUANGHIGHT_MAX                255
#define E2POOM_ALG102_LASERIMAGEPOS_JIGUANGLONG_MIN                 0 
#define E2POOM_ALG102_LASERIMAGEPOS_JIGUANGLONG_USE                 20
#define E2POOM_ALG102_LASERIMAGEPOS_JIGUANGLONG_MAX                 255
#define E2POOM_ALG102_LASERIMAGEPOS_JIGUANGKUANDU_MIN               0 
#define E2POOM_ALG102_LASERIMAGEPOS_JIGUANGKUANDU_USE               6
#define E2POOM_ALG102_LASERIMAGEPOS_JIGUANGKUANDU_MAX               20
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIF_MIN                      -255 
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIF_USE                       0
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIF_MAX                       255
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIFMIN_MIN                   -255 
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIFMIN_USE                   -5
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIFMIN_MAX                    255
#define E2POOM_ALG102_LASERIMAGEPOS_UPLONG_MIN                      1
#define E2POOM_ALG102_LASERIMAGEPOS_UPLONG_USE                      20
#define E2POOM_ALG102_LASERIMAGEPOS_UPLONG_MAX                      500
#define E2POOM_ALG102_LASERIMAGEPOS_DOWNDIF_MIN                    -255 
#define E2POOM_ALG102_LASERIMAGEPOS_DOWNDIF_USE                     0
#define E2POOM_ALG102_LASERIMAGEPOS_DOWNDIF_MAX                     255
#define E2POOM_ALG102_LASERIMAGEPOS_DOWNDIFMIN_MIN                 -255 
#define E2POOM_ALG102_LASERIMAGEPOS_DOWNDIFMIN_USE                  5
#define E2POOM_ALG102_LASERIMAGEPOS_DOWNDIFMIN_MAX                  255
#define E2POOM_ALG102_LASERIMAGEPOS_DOWNDLONG_MIN                   1
#define E2POOM_ALG102_LASERIMAGEPOS_DOWNDLONG_USE                   50
#define E2POOM_ALG102_LASERIMAGEPOS_DOWNDLONG_MAX                   500
#define E2POOM_ALG102_LASERIMAGEPOS_ST_DOWN_MIN                     0
#define E2POOM_ALG102_LASERIMAGEPOS_ST_DOWN_USE                     5
#define E2POOM_ALG102_LASERIMAGEPOS_ST_DOWN_MAX                     500
#define E2POOM_ALG102_LASERIMAGEPOS_ED_DOWN_MIN                     0
#define E2POOM_ALG102_LASERIMAGEPOS_ED_DOWN_USE                     200
#define E2POOM_ALG102_LASERIMAGEPOS_ED_DOWN_MAX                     1500
#define E2POOM_ALG102_LASERIMAGEPOS_ST_UP_MIN                       0
#define E2POOM_ALG102_LASERIMAGEPOS_ST_UP_USE                       5
#define E2POOM_ALG102_LASERIMAGEPOS_ST_UP_MAX                       500
#define E2POOM_ALG102_LASERIMAGEPOS_ED_UP_MIN                       0
#define E2POOM_ALG102_LASERIMAGEPOS_ED_UP_USE                       200              
#define E2POOM_ALG102_LASERIMAGEPOS_ED_UP_MAX                       1500
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIF2_MIN                     -255
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIF2_USE                     -2
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIF2_MAX                      255
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIFMIN2_MIN                  -255
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIFMIN2_USE                  -5
#define E2POOM_ALG102_LASERIMAGEPOS_UPDIFMIN2_MAX                   255
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST_MIN               0
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST_USE               0
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST_MAX               500
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED_MIN               0
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED_USE               120
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED_MAX               500
#define E2POOM_ALG102_LASERIMAGEPOS_B_OPENGUDINGDIMIAN_MIN          0
#define E2POOM_ALG102_LASERIMAGEPOS_B_OPENGUDINGDIMIAN_MAX          1
#define E2POOM_ALG102_LASERIMAGEPOS_B_OPENGUDINGDIMIAN_USE          1
#define E2POOM_ALG102_LASERIMAGEPOS_DIMIANPANGDINGJULI_MIN          1
#define E2POOM_ALG102_LASERIMAGEPOS_DIMIANPANGDINGJULI_MAX          500
#define E2POOM_ALG102_LASERIMAGEPOS_DIMIANPANGDINGJULI_USE          30
#define E2POOM_ALG102_LASERIMAGEPOS_DIMIANPINGJUNSHUNUM_MIN         1
#define E2POOM_ALG102_LASERIMAGEPOS_DIMIANPINGJUNSHUNUM_MAX         99     
#define E2POOM_ALG102_LASERIMAGEPOS_DIMIANPINGJUNSHUNUM_USE         30
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST2_MIN              0
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST2_MAX              500
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST2_USE              20
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED2_MIN              0
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED2_MAX              500
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED2_USE              120
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST3_MIN              0
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST3_MAX              500
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST3_USE              20
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED3_MIN              0
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED3_MAX              500
#define E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED3_USE              500
#define E2POOM_ALG102_LASERIMAGEPOS_XUEXIJULI_MIN                   0
#define E2POOM_ALG102_LASERIMAGEPOS_XUEXIJULI_MAX                   255
#define E2POOM_ALG102_LASERIMAGEPOS_XUEXIJULI_USE                   30
#define E2POOM_ALG102_LASERIMAGEPOS_B_PINGPOWENGDING_MIN            0
#define E2POOM_ALG102_LASERIMAGEPOS_B_PINGPOWENGDING_MAX            1
#define E2POOM_ALG102_LASERIMAGEPOS_B_PINGPOWENGDING_USE            1
#define E2POOM_ALG102_LASERIMAGEPOS_PINGPOWENGDING_DIS_MIN          0
#define E2POOM_ALG102_LASERIMAGEPOS_PINGPOWENGDING_DIS_MAX          255
#define E2POOM_ALG102_LASERIMAGEPOS_PINGPOWENGDING_DIS_USE          4
#define E2POOM_ALG102_LASERIMAGEPOS_B_XIELVOPEN_MIN                 0
#define E2POOM_ALG102_LASERIMAGEPOS_B_XIELVOPEN_MAX                 1
#define E2POOM_ALG102_LASERIMAGEPOS_B_XIELVOPEN_USE                 1
#define E2POOM_ALG102_LASERIMAGEPOS_XIELVFANWEI_MIN                 0
#define E2POOM_ALG102_LASERIMAGEPOS_XIELVFANWEI_MAX                 255
#define E2POOM_ALG102_LASERIMAGEPOS_XIELVFANWEI_USE                 10
#define E2POOM_ALG102_LASERIMAGEPOS_UPLONG2_MIN                     1
#define E2POOM_ALG102_LASERIMAGEPOS_UPLONG2_USE                     60
#define E2POOM_ALG102_LASERIMAGEPOS_UPLONG2_MAX                     500
#define E2POOM_ALG102_LASERIMAGEPOS_CEBANKONGDONGDIS_MIN            0
#define E2POOM_ALG102_LASERIMAGEPOS_CEBANKONGDONGDIS_USE            180          
#define E2POOM_ALG102_LASERIMAGEPOS_CEBANKONGDONGDIS_MAX            500
#define E2POOM_ALG102_LASERIMAGEPOS_QIATOUQUWEI_MIN                 0
#define E2POOM_ALG102_LASERIMAGEPOS_QIATOUQUWEI_USE                 15
#define E2POOM_ALG102_LASERIMAGEPOS_QIATOUQUWEI_MAX                 120


//算法103参数
#define E2POOM_ALG103_LASERIMAGEPOS_SAVEBUFF                20
#define E2POOM_ALG103_LASERIMAGEPOS_SYSPATH_MOTO			"./SAVE/E2P_MEASUREMENT_103.bsd"

#define E2POOM_ALG103_LASERIMAGEPOS_EXPOSURE_TIME_MIN				20         //曝光最小值
#define E2POOM_ALG103_LASERIMAGEPOS_EXPOSURE_TIME_USE				10000      //曝光默认值   
#define E2POOM_ALG103_LASERIMAGEPOS_EXPOSURE_TIME_MAX				65535      //曝光最大值
#define E2POOM_ALG103_LASERIMAGEPOS_PINGJUN_MIN                     0
#define E2POOM_ALG103_LASERIMAGEPOS_PINGJUN_USE                     15
#define E2POOM_ALG103_LASERIMAGEPOS_PINGJUN_MAX                     255
#define E2POOM_ALG103_LASERIMAGEPOS_GUJIAERZHI_MIN                  0
#define E2POOM_ALG103_LASERIMAGEPOS_GUJIAERZHI_USE                  160
#define E2POOM_ALG103_LASERIMAGEPOS_GUJIAERZHI_MAX                  255
#define E2POOM_ALG103_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN            0
#define E2POOM_ALG103_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE            5
#define E2POOM_ALG103_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX            255
#define E2POOM_ALG103_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN             0
#define E2POOM_ALG103_LASERIMAGEPOS_HIGHLIANTONGDIS_USE             5
#define E2POOM_ALG103_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX             255
#define E2POOM_ALG103_LASERIMAGEPOS_JIGUANGLONG_MIN                 0
#define E2POOM_ALG103_LASERIMAGEPOS_JIGUANGLONG_USE                 5
#define E2POOM_ALG103_LASERIMAGEPOS_JIGUANGLONG_MAX                 255
#define E2POOM_ALG103_LASERIMAGEPOS_JIGUANGKUANDU_MIN               0
#define E2POOM_ALG103_LASERIMAGEPOS_JIGUANGKUANDU_USE               10
#define E2POOM_ALG103_LASERIMAGEPOS_JIGUANGKUANDU_MAX               255
#define E2POOM_ALG103_LASERIMAGEPOS_JIGUANGDUIBIDU_MIN              0
#define E2POOM_ALG103_LASERIMAGEPOS_JIGUANGDUIBIDU_USE              5
#define E2POOM_ALG103_LASERIMAGEPOS_JIGUANGDUIBIDU_MAX              255


//算法104参数
#define E2POOM_ALG104_LASERIMAGEPOS_SAVEBUFF              88
#define E2POOM_ALG104_LASERIMAGEPOS_SYSPATH_MOTO			"./SAVE/E2P_MEASUREMENT_104.bsd"

#define E2POOM_ALG104_LASERIMAGEPOS_EXPOSURE_TIME_MIN				20         //曝光最小值
#define E2POOM_ALG104_LASERIMAGEPOS_EXPOSURE_TIME_USE				10000      //曝光默认值   
#define E2POOM_ALG104_LASERIMAGEPOS_EXPOSURE_TIME_MAX				65535      //曝光最大值
#define E2POOM_ALG104_LASERIMAGEPOS_PINGJUN_MIN                     0
#define E2POOM_ALG104_LASERIMAGEPOS_PINGJUN_USE                     15
#define E2POOM_ALG104_LASERIMAGEPOS_PINGJUN_MAX                     255
#define E2POOM_ALG104_LASERIMAGEPOS_B_YANMOFUZHU_MIN                0 
#define E2POOM_ALG104_LASERIMAGEPOS_B_YANMOFUZHU_USE                1
#define E2POOM_ALG104_LASERIMAGEPOS_B_YANMOFUZHU_MAX                1
#define E2POOM_ALG104_LASERIMAGEPOS_B_GUDINGQUYU_MIN                0 
#define E2POOM_ALG104_LASERIMAGEPOS_B_GUDINGQUYU_USE                1
#define E2POOM_ALG104_LASERIMAGEPOS_B_GUDINGQUYU_MAX                1
#define E2POOM_ALG104_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN            0 
#define E2POOM_ALG104_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE            4
#define E2POOM_ALG104_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX            500
#define E2POOM_ALG104_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN             0 
#define E2POOM_ALG104_LASERIMAGEPOS_HIGHLIANTONGDIS_USE             15
#define E2POOM_ALG104_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX             500
#define E2POOM_ALG104_LASERIMAGEPOS_GUJIAERZHI_MIN                  0 
#define E2POOM_ALG104_LASERIMAGEPOS_GUJIAERZHI_USE                  160
#define E2POOM_ALG104_LASERIMAGEPOS_GUJIAERZHI_MAX                  255
#define E2POOM_ALG104_LASERIMAGEPOS_JIGUANGHIGHT_MIN                0 
#define E2POOM_ALG104_LASERIMAGEPOS_JIGUANGHIGHT_USE                50
#define E2POOM_ALG104_LASERIMAGEPOS_JIGUANGHIGHT_MAX                255
#define E2POOM_ALG104_LASERIMAGEPOS_JIGUANGLONG_MIN                 0 
#define E2POOM_ALG104_LASERIMAGEPOS_JIGUANGLONG_USE                 20
#define E2POOM_ALG104_LASERIMAGEPOS_JIGUANGLONG_MAX                 255
#define E2POOM_ALG104_LASERIMAGEPOS_JIGUANGKUANDU_MIN               0 
#define E2POOM_ALG104_LASERIMAGEPOS_JIGUANGKUANDU_USE               4
#define E2POOM_ALG104_LASERIMAGEPOS_JIGUANGKUANDU_MAX               20
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIF_MIN                      -255 
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIF_USE                       0
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIF_MAX                       255
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN_MIN                   -255 
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN_USE                   -5
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN_MAX                    255
#define E2POOM_ALG104_LASERIMAGEPOS_UPLONG_MIN                      1
#define E2POOM_ALG104_LASERIMAGEPOS_UPLONG_USE                      20
#define E2POOM_ALG104_LASERIMAGEPOS_UPLONG_MAX                      500
#define E2POOM_ALG104_LASERIMAGEPOS_DOWNDIF_MIN                    -255 
#define E2POOM_ALG104_LASERIMAGEPOS_DOWNDIF_USE                     0
#define E2POOM_ALG104_LASERIMAGEPOS_DOWNDIF_MAX                     255
#define E2POOM_ALG104_LASERIMAGEPOS_DOWNDIFMIN_MIN                 -255 
#define E2POOM_ALG104_LASERIMAGEPOS_DOWNDIFMIN_USE                  5
#define E2POOM_ALG104_LASERIMAGEPOS_DOWNDIFMIN_MAX                  255
#define E2POOM_ALG104_LASERIMAGEPOS_DOWNDLONG_MIN                   1
#define E2POOM_ALG104_LASERIMAGEPOS_DOWNDLONG_USE                   50
#define E2POOM_ALG104_LASERIMAGEPOS_DOWNDLONG_MAX                   500
#define E2POOM_ALG104_LASERIMAGEPOS_ST_DOWN_MIN                     0
#define E2POOM_ALG104_LASERIMAGEPOS_ST_DOWN_USE                     5
#define E2POOM_ALG104_LASERIMAGEPOS_ST_DOWN_MAX                     500
#define E2POOM_ALG104_LASERIMAGEPOS_ED_DOWN_MIN                     0
#define E2POOM_ALG104_LASERIMAGEPOS_ED_DOWN_USE                     200
#define E2POOM_ALG104_LASERIMAGEPOS_ED_DOWN_MAX                     1500
#define E2POOM_ALG104_LASERIMAGEPOS_ST_UP_MIN                       0
#define E2POOM_ALG104_LASERIMAGEPOS_ST_UP_USE                       5
#define E2POOM_ALG104_LASERIMAGEPOS_ST_UP_MAX                       500
#define E2POOM_ALG104_LASERIMAGEPOS_ED_UP_MIN                       0
#define E2POOM_ALG104_LASERIMAGEPOS_ED_UP_USE                       200              //180
#define E2POOM_ALG104_LASERIMAGEPOS_ED_UP_MAX                       1500
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIF2_MIN                     -255
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIF2_USE                     -2
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIF2_MAX                      255
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN2_MIN                  -255
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN2_USE                  -5
#define E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN2_MAX                   255
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST_MIN               0
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST_USE               0
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST_MAX               500
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED_MIN               0
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED_USE               120
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED_MAX               500
#define E2POOM_ALG104_LASERIMAGEPOS_B_OPENGUDINGDIMIAN_MIN          0
#define E2POOM_ALG104_LASERIMAGEPOS_B_OPENGUDINGDIMIAN_MAX          1
#define E2POOM_ALG104_LASERIMAGEPOS_B_OPENGUDINGDIMIAN_USE          1
#define E2POOM_ALG104_LASERIMAGEPOS_DIMIANPANGDINGJULI_MIN          1
#define E2POOM_ALG104_LASERIMAGEPOS_DIMIANPANGDINGJULI_MAX          500
#define E2POOM_ALG104_LASERIMAGEPOS_DIMIANPANGDINGJULI_USE          30
#define E2POOM_ALG104_LASERIMAGEPOS_DIMIANPINGJUNSHUNUM_MIN         1
#define E2POOM_ALG104_LASERIMAGEPOS_DIMIANPINGJUNSHUNUM_MAX         99     //当心越界,不能大于99
#define E2POOM_ALG104_LASERIMAGEPOS_DIMIANPINGJUNSHUNUM_USE         30
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST2_MIN              0
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST2_MAX              500
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST2_USE              20
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED2_MIN              0
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED2_MAX              500
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED2_USE              120
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST3_MIN              0
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST3_MAX              500
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST3_USE              20
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED3_MIN              0
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED3_MAX              500
#define E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED3_USE              500
#define E2POOM_ALG104_LASERIMAGEPOS_XUEXIJULI_MIN                   0
#define E2POOM_ALG104_LASERIMAGEPOS_XUEXIJULI_MAX                   255
#define E2POOM_ALG104_LASERIMAGEPOS_XUEXIJULI_USE                   30
#define E2POOM_ALG104_LASERIMAGEPOS_B_PINGPOWENGDING_MIN            0
#define E2POOM_ALG104_LASERIMAGEPOS_B_PINGPOWENGDING_MAX            1
#define E2POOM_ALG104_LASERIMAGEPOS_B_PINGPOWENGDING_USE            1
#define E2POOM_ALG104_LASERIMAGEPOS_PINGPOWENGDING_DIS_MIN          0
#define E2POOM_ALG104_LASERIMAGEPOS_PINGPOWENGDING_DIS_MAX          255
#define E2POOM_ALG104_LASERIMAGEPOS_PINGPOWENGDING_DIS_USE          4
#define E2POOM_ALG104_LASERIMAGEPOS_B_XIELVOPEN_MIN                 0
#define E2POOM_ALG104_LASERIMAGEPOS_B_XIELVOPEN_MAX                 1
#define E2POOM_ALG104_LASERIMAGEPOS_B_XIELVOPEN_USE                 1
#define E2POOM_ALG104_LASERIMAGEPOS_XIELVFANWEI_MIN                 0
#define E2POOM_ALG104_LASERIMAGEPOS_XIELVFANWEI_MAX                 255
#define E2POOM_ALG104_LASERIMAGEPOS_XIELVFANWEI_USE                 10
#define E2POOM_ALG104_LASERIMAGEPOS_UPLONG2_MIN                     1
#define E2POOM_ALG104_LASERIMAGEPOS_UPLONG2_USE                     60
#define E2POOM_ALG104_LASERIMAGEPOS_UPLONG2_MAX                     500
#define E2POOM_ALG104_LASERIMAGEPOS_CEBANKONGDONGDIS_MIN            0
#define E2POOM_ALG104_LASERIMAGEPOS_CEBANKONGDONGDIS_USE            180          //180
#define E2POOM_ALG104_LASERIMAGEPOS_CEBANKONGDONGDIS_MAX            500
#define E2POOM_ALG104_LASERIMAGEPOS_QIATOUQUWEI_MIN                 0
#define E2POOM_ALG104_LASERIMAGEPOS_QIATOUQUWEI_USE                 15
#define E2POOM_ALG104_LASERIMAGEPOS_QIATOUQUWEI_MAX                 120



class E2proomData
{
public:
    E2proomData();
    ~E2proomData();
/****************************/   //任务号参数
    //任务号参数
    Uint16 task_num;             //任务号参数

    void write_task_num_para();	     //保存机器人参数
    void init_task_num_para();		 //初始化机器人参数
    
    Uint16 task_num_min;         //任务号参数最小值
    Uint16 task_num_max;         //任务号参数最大值
    Uint16 task_num_use;         //任务号参数默认值

/****************************/
    //机器人参数
    Uint16 robot_mod;           //机器人型号
    Uint16 robot_port;          //机器人端口

    void write_robot_para();	//保存机器人参数
    void init_robot_para();		//初始化机器人参数

    Uint16 robot_port_min;      //机器人端口最小值
    Uint16 robot_port_max;      //机器人端口最大值
    Uint16 robot_port_use;      //机器人端口默认值

/****************************/
    //任务100参数
    Uint16 als100_exposure_time;  //曝光模式
    Int16 als100_pingjun;//二值阈值
    Int16 als100_b_yanmofuzhu;//是否使用掩摸辅助
    Int16 als100_b_gudingquyu;//是否固定区域
    Int16 als100_widthliantongdis;//激光宽度连通距离
    Int16 als100_highliantongdis;//激光长度连通距离
    Int16 als100_gujiaerzhi;//找骨架二值图
    Int16 als100_jiguanghight;//整体激光最短长度
    Int16 als100_jiguanglong;//单边激光最短长度
    Int16 als100_jiguangkuandu;//激光粗细
    Int16 als100_Updif;//上半段倾斜开始斜度10
    Int16 als100_Updifmin;//上半段倾斜终止斜度10
    Int16 als100_Uplong;//上半段直线长度
    Int16 als100_Downdif;//下半段倾斜开始斜度0
    Int16 als100_Downdifmin;//下半段倾斜终止斜度0
    Int16 als100_Downdlong;//下半段直线长度
    Int16 als100_duanxianerzhi;//找断线的二值阈值
    Int16 als100_erzhisize;//断线二值图的上下阈值尺寸
    Int16 als100_erzhisize2;//断线二值图的左右阈值尺寸
    Int16 als100_searchdectancemax;//搜寻焊缝端点距离中央凹槽最远的距离
    Int16 als100_searchdectancemin;//搜寻焊缝端点距离中央凹槽最近的距离
    Int16 als100_dis_center_st;//距离中心点此处后开始统计
    Int16 als100_dis_center_ed;//距离中心点此处后停止统计
      

    void write_als100_para();				//保存任务100参数
    void init_als100_para();				//初始化任务100参数
    //默认参数
    Uint16 als100_exposure_time_min;    //曝光最小值
    Uint16 als100_exposure_time_max;    //曝光最大值
    Uint16 als100_exposure_time_use;    //曝光默认值
    Int16 als100_pingjun_min;
    Int16 als100_pingjun_max;
    Int16 als100_pingjun_use;
    Int16 als100_b_yanmofuzhu_min;
    Int16 als100_b_yanmofuzhu_max;
    Int16 als100_b_yanmofuzhu_use;
    Int16 als100_b_gudingquyu_min;
    Int16 als100_b_gudingquyu_max;
    Int16 als100_b_gudingquyu_use;
    Int16 als100_widthliantongdis_min;
    Int16 als100_widthliantongdis_max;
    Int16 als100_widthliantongdis_use;
    Int16 als100_highliantongdis_min;
    Int16 als100_highliantongdis_max;
    Int16 als100_highliantongdis_use;
    Int16 als100_gujiaerzhi_min;
    Int16 als100_gujiaerzhi_max;
    Int16 als100_gujiaerzhi_use;
    Int16 als100_jiguanghight_min;
    Int16 als100_jiguanghight_max;
    Int16 als100_jiguanghight_use;
    Int16 als100_jiguanglong_min;
    Int16 als100_jiguanglong_max;
    Int16 als100_jiguanglong_use;
    Int16 als100_jiguangkuandu_min;
    Int16 als100_jiguangkuandu_max;
    Int16 als100_jiguangkuandu_use;
    Int16 als100_Updif_min;
    Int16 als100_Updif_max;
    Int16 als100_Updif_use;
    Int16 als100_Updifmin_min;
    Int16 als100_Updifmin_max;
    Int16 als100_Updifmin_use;
    Int16 als100_Uplong_min;
    Int16 als100_Uplong_max;
    Int16 als100_Uplong_use;
    Int16 als100_Downdif_min;
    Int16 als100_Downdif_max;
    Int16 als100_Downdif_use;
    Int16 als100_Downdifmin_min;
    Int16 als100_Downdifmin_max;
    Int16 als100_Downdifmin_use;
    Int16 als100_Downdlong_min;
    Int16 als100_Downdlong_max;
    Int16 als100_Downdlong_use;
    Int16 als100_duanxianerzhi_min;
    Int16 als100_duanxianerzhi_max;
    Int16 als100_duanxianerzhi_use;
    Int16 als100_erzhisize_min;
    Int16 als100_erzhisize_max;
    Int16 als100_erzhisize_use;
    Int16 als100_erzhisize2_min;
    Int16 als100_erzhisize2_max;
    Int16 als100_erzhisize2_use;
    Int16 als100_searchdectancemax_min;
    Int16 als100_searchdectancemax_max;
    Int16 als100_searchdectancemax_use;
    Int16 als100_searchdectancemin_min;
    Int16 als100_searchdectancemin_max;
    Int16 als100_searchdectancemin_use;
    Int16 als100_dis_center_st_min;
    Int16 als100_dis_center_st_max;
    Int16 als100_dis_center_st_use;
    Int16 als100_dis_center_ed_min;
    Int16 als100_dis_center_ed_max;
    Int16 als100_dis_center_ed_use;

/****************************/
    //任务101参数
    Uint16 als101_exposure_time;  //曝光模式
    Int16 als101_pingjun;//二值阈值
    Int16 als101_b_yanmofuzhu;//是否使用掩摸辅助
    Int16 als101_b_gudingquyu;//是否固定区域
    Int16 als101_widthliantongdis;//激光宽度连通距离
    Int16 als101_highliantongdis;//激光长度连通距离
    Int16 als101_gujiaerzhi;//找骨架二值图
    Int16 als101_jiguanghight;//整体激光最短长度
    Int16 als101_jiguanglong;//单边激光最短长度
    Int16 als101_jiguangkuandu;//激光粗细
    Int16 als101_Updif;//上半段倾斜开始斜度10
    Int16 als101_Updifmin;//上半段倾斜终止斜度10
    Int16 als101_Uplong;//上半段直线长度
    Int16 als101_Downdif;//下半段倾斜开始斜度0
    Int16 als101_Downdifmin;//下半段倾斜终止斜度0
    Int16 als101_Downdlong;//下半段直线长度
    Int16 als101_duanxianerzhi;//找断线的二值阈值
    Int16 als101_erzhisize;//断线二值图的上下阈值尺寸
    Int16 als101_erzhisize2;//断线二值图的左右阈值尺寸
    Int16 als101_searchdectancemax;//搜寻焊缝端点距离中央凹槽最远的距离
    Int16 als101_searchdectancemin;//搜寻焊缝端点距离中央凹槽最近的距离
    Int16 als101_dis_center_st;//距离中心点此处后开始统计
    Int16 als101_dis_center_ed;//距离中心点此处后停止统计
      

    void write_als101_para();				//保存任务101参数
    void init_als101_para();				//初始化任务101参数
    //默认参数
    Uint16 als101_exposure_time_min;    //曝光最小值
    Uint16 als101_exposure_time_max;    //曝光最大值
    Uint16 als101_exposure_time_use;    //曝光默认值
    Int16 als101_pingjun_min;
    Int16 als101_pingjun_max;
    Int16 als101_pingjun_use;
    Int16 als101_b_yanmofuzhu_min;
    Int16 als101_b_yanmofuzhu_max;
    Int16 als101_b_yanmofuzhu_use;
    Int16 als101_b_gudingquyu_min;
    Int16 als101_b_gudingquyu_max;
    Int16 als101_b_gudingquyu_use;
    Int16 als101_widthliantongdis_min;
    Int16 als101_widthliantongdis_max;
    Int16 als101_widthliantongdis_use;
    Int16 als101_highliantongdis_min;
    Int16 als101_highliantongdis_max;
    Int16 als101_highliantongdis_use;
    Int16 als101_gujiaerzhi_min;
    Int16 als101_gujiaerzhi_max;
    Int16 als101_gujiaerzhi_use;
    Int16 als101_jiguanghight_min;
    Int16 als101_jiguanghight_max;
    Int16 als101_jiguanghight_use;
    Int16 als101_jiguanglong_min;
    Int16 als101_jiguanglong_max;
    Int16 als101_jiguanglong_use;
    Int16 als101_jiguangkuandu_min;
    Int16 als101_jiguangkuandu_max;
    Int16 als101_jiguangkuandu_use;
    Int16 als101_Updif_min;
    Int16 als101_Updif_max;
    Int16 als101_Updif_use;
    Int16 als101_Updifmin_min;
    Int16 als101_Updifmin_max;
    Int16 als101_Updifmin_use;
    Int16 als101_Uplong_min;
    Int16 als101_Uplong_max;
    Int16 als101_Uplong_use;
    Int16 als101_Downdif_min;
    Int16 als101_Downdif_max;
    Int16 als101_Downdif_use;
    Int16 als101_Downdifmin_min;
    Int16 als101_Downdifmin_max;
    Int16 als101_Downdifmin_use;
    Int16 als101_Downdlong_min;
    Int16 als101_Downdlong_max;
    Int16 als101_Downdlong_use;
    Int16 als101_duanxianerzhi_min;
    Int16 als101_duanxianerzhi_max;
    Int16 als101_duanxianerzhi_use;
    Int16 als101_erzhisize_min;
    Int16 als101_erzhisize_max;
    Int16 als101_erzhisize_use;
    Int16 als101_erzhisize2_min;
    Int16 als101_erzhisize2_max;
    Int16 als101_erzhisize2_use;
    Int16 als101_searchdectancemax_min;
    Int16 als101_searchdectancemax_max;
    Int16 als101_searchdectancemax_use;
    Int16 als101_searchdectancemin_min;
    Int16 als101_searchdectancemin_max;
    Int16 als101_searchdectancemin_use;
    Int16 als101_dis_center_st_min;
    Int16 als101_dis_center_st_max;
    Int16 als101_dis_center_st_use;
    Int16 als101_dis_center_ed_min;
    Int16 als101_dis_center_ed_max;
    Int16 als101_dis_center_ed_use;

/****************************/
    //任务102参数
    Uint16 als102_exposure_time;  //曝光模式
    Int16 als102_pingjun;//二值阈值
    Int16 als102_b_yanmofuzhu;//是否使用掩摸辅助
    Int16 als102_b_gudingquyu;//是否固定区域
    Int16 als102_widthliantongdis;//激光宽度连通距离
    Int16 als102_highliantongdis;//激光长度连通距离
    Int16 als102_gujiaerzhi;//找骨架二值图
    Int16 als102_jiguanghight;//整体激光最短长度
    Int16 als102_jiguanglong;//单边激光最短长度
    Int16 als102_jiguangkuandu;//激光粗细
    Int16 als102_Updif;//上半段倾斜开始斜度10
    Int16 als102_Updifmin;//上半段倾斜终止斜度10
    Int16 als102_Uplong;//上半段直线长度
    Int16 als102_Downdif;//下半段倾斜开始斜度0
    Int16 als102_Downdifmin;//下半段倾斜终止斜度0
    Int16 als102_Downdlong;//下半段直线长度
    Int16 als102_St_Down;//下半段拟合起点
    Int16 als102_Ed_Down;//下半段拟合终点
    Int16 als102_St_Up;//上半段拟合起点
    Int16 als102_Ed_Up;//上半段拟合终点
    Int16 als102_Updif2;//上半段倾斜开始斜度10
    Int16 als102_Updifmin2;//上半段倾斜终止斜度10
    Int16 als102_dis_center_st;//距离中心点此处后开始统计
    Int16 als102_dis_center_ed;//距离中心点此处后停止统计
    Int16 als102_b_opengudingdimian;//是否固定底面
    Int16 als102_dimianpangdingjuli;//底面判定距离
    Int16 als102_dimianpingjunshunum;//底面平均数统计个数
    Int16 als102_dis_center_st2;
    Int16 als102_dis_center_ed2;
    Int16 als102_dis_center_st3;
    Int16 als102_dis_center_ed3;  
    Int16 als102_xuexijuli;
    Int16 als102_b_pingpowending;
    Int16 als102_pingpowending_dis;
    Int16 als102_b_xielvopen;
    Int16 als102_xielvfanwei;
    Int16 als102_Uplong2;
    Int16 als102_cebankongdongdis;
    Int16 als102_qiatouquweijuli;

    void write_als102_para();				//保存任务102参数
    void init_als102_para();				//初始化任务102参数
    //默认参数
    Uint16 als102_exposure_time_min;    //曝光最小值
    Uint16 als102_exposure_time_max;    //曝光最大值
    Uint16 als102_exposure_time_use;    //曝光默认值
    Int16 als102_pingjun_min;
    Int16 als102_pingjun_max;
    Int16 als102_pingjun_use;
    Int16 als102_b_yanmofuzhu_min;
    Int16 als102_b_yanmofuzhu_max;
    Int16 als102_b_yanmofuzhu_use;
    Int16 als102_b_gudingquyu_min;
    Int16 als102_b_gudingquyu_max;
    Int16 als102_b_gudingquyu_use;
    Int16 als102_widthliantongdis_min;
    Int16 als102_widthliantongdis_max;
    Int16 als102_widthliantongdis_use;
    Int16 als102_highliantongdis_min;
    Int16 als102_highliantongdis_max;
    Int16 als102_highliantongdis_use;
    Int16 als102_gujiaerzhi_min;
    Int16 als102_gujiaerzhi_max;
    Int16 als102_gujiaerzhi_use;
    Int16 als102_jiguanghight_min;
    Int16 als102_jiguanghight_max;
    Int16 als102_jiguanghight_use;
    Int16 als102_jiguanglong_min;
    Int16 als102_jiguanglong_max;
    Int16 als102_jiguanglong_use;
    Int16 als102_jiguangkuandu_min;
    Int16 als102_jiguangkuandu_max;
    Int16 als102_jiguangkuandu_use;
    Int16 als102_Updif_min;
    Int16 als102_Updif_max;
    Int16 als102_Updif_use;
    Int16 als102_Updifmin_min;
    Int16 als102_Updifmin_max;
    Int16 als102_Updifmin_use;
    Int16 als102_Uplong_min;
    Int16 als102_Uplong_max;
    Int16 als102_Uplong_use;
    Int16 als102_Downdif_min;
    Int16 als102_Downdif_max;
    Int16 als102_Downdif_use;
    Int16 als102_Downdifmin_min;
    Int16 als102_Downdifmin_max;
    Int16 als102_Downdifmin_use;
    Int16 als102_Downdlong_min;
    Int16 als102_Downdlong_max;
    Int16 als102_Downdlong_use;
    Int16 als102_St_Down_min;
    Int16 als102_St_Down_max;
    Int16 als102_St_Down_use;
    Int16 als102_Ed_Down_min;
    Int16 als102_Ed_Down_max;
    Int16 als102_Ed_Down_use;
    Int16 als102_St_Up_min;
    Int16 als102_St_Up_max;
    Int16 als102_St_Up_use;
    Int16 als102_Ed_Up_min;
    Int16 als102_Ed_Up_max;
    Int16 als102_Ed_Up_use;
    Int16 als102_Updif2_min;
    Int16 als102_Updif2_max;
    Int16 als102_Updif2_use;
    Int16 als102_Updifmin2_min;
    Int16 als102_Updifmin2_max;
    Int16 als102_Updifmin2_use;
    Int16 als102_dis_center_st_min;
    Int16 als102_dis_center_st_max;
    Int16 als102_dis_center_st_use;
    Int16 als102_dis_center_ed_min;
    Int16 als102_dis_center_ed_max;
    Int16 als102_dis_center_ed_use;
    Int16 als102_b_opengudingdimian_min;
    Int16 als102_b_opengudingdimian_max;
    Int16 als102_b_opengudingdimian_use;
    Int16 als102_dimianpangdingjuli_min;
    Int16 als102_dimianpangdingjuli_max;
    Int16 als102_dimianpangdingjuli_use;
    Int16 als102_dimianpingjunshunum_min;
    Int16 als102_dimianpingjunshunum_max;
    Int16 als102_dimianpingjunshunum_use;
    Int16 als102_dis_center_st2_min;
    Int16 als102_dis_center_st2_max;
    Int16 als102_dis_center_st2_use;
    Int16 als102_dis_center_ed2_min;
    Int16 als102_dis_center_ed2_max;
    Int16 als102_dis_center_ed2_use;
    Int16 als102_dis_center_st3_min;
    Int16 als102_dis_center_st3_max;
    Int16 als102_dis_center_st3_use;
    Int16 als102_dis_center_ed3_min; 
    Int16 als102_dis_center_ed3_max;
    Int16 als102_dis_center_ed3_use;  
    Int16 als102_xuexijuli_min;
    Int16 als102_xuexijuli_max;
    Int16 als102_xuexijuli_use;
    Int16 als102_b_pingpowending_min;
    Int16 als102_b_pingpowending_max;
    Int16 als102_b_pingpowending_use;
    Int16 als102_pingpowending_dis_min;
    Int16 als102_pingpowending_dis_max;
    Int16 als102_pingpowending_dis_use;
    Int16 als102_b_xielvopen_min;
    Int16 als102_b_xielvopen_max;
    Int16 als102_b_xielvopen_use;
    Int16 als102_xielvfanwei_min;
    Int16 als102_xielvfanwei_max;
    Int16 als102_xielvfanwei_use;
    Int16 als102_Uplong2_min;
    Int16 als102_Uplong2_max;
    Int16 als102_Uplong2_use;
    Int16 als102_cebankongdongdis_min;
    Int16 als102_cebankongdongdis_max;
    Int16 als102_cebankongdongdis_use;
    Int16 als102_qiatouquweijuli_min;
    Int16 als102_qiatouquweijuli_max;
    Int16 als102_qiatouquweijuli_use;

/****************************/
    //任务103参数
    Uint16 als103_exposure_time;  //曝光模式
    Int16 als103_pingjun;
    Int16 als103_gujiaerzhi;
    Int16 als103_widthliantongdis;
    Int16 als103_highliantongdis;
    Int16 als103_jiguanglong;//激光长度
    Int16 als103_jiguangkuandu;//激光宽度
    Int16 als103_jiguangduibidu;

    void write_als103_para();				//保存任务103参数
    void init_als103_para();				//初始化任务103参数
    //默认参数
    Uint16 als103_exposure_time_min;    //曝光最小值
    Uint16 als103_exposure_time_max;    //曝光最大值
    Uint16 als103_exposure_time_use;    //曝光默认值
    Int16 als103_pingjun_min;
    Int16 als103_pingjun_max;
    Int16 als103_pingjun_use;
    Int16 als103_gujiaerzhi_min;
    Int16 als103_gujiaerzhi_max;
    Int16 als103_gujiaerzhi_use;
    Int16 als103_widthliantongdis_min;
    Int16 als103_widthliantongdis_max;
    Int16 als103_widthliantongdis_use;
    Int16 als103_highliantongdis_min;
    Int16 als103_highliantongdis_max;
    Int16 als103_highliantongdis_use;
    Int16 als103_jiguanglong_min;
    Int16 als103_jiguanglong_max;
    Int16 als103_jiguanglong_use;
    Int16 als103_jiguangkuandu_min;
    Int16 als103_jiguangkuandu_max;
    Int16 als103_jiguangkuandu_use;
    Int16 als103_jiguangduibidu_min;
    Int16 als103_jiguangduibidu_use;
    Int16 als103_jiguangduibidu_max;

/****************************/
    //任务104参数
    Uint16 als104_exposure_time;//曝光值
    Int16 als104_pingjun;//二值阈值
    Int16 als104_b_yanmofuzhu;//是否使用掩摸辅助
    Int16 als104_b_gudingquyu;//是否固定区域
    Int16 als104_widthliantongdis;//激光宽度连通距离
    Int16 als104_highliantongdis;//激光长度连通距离
    Int16 als104_gujiaerzhi;//找骨架二值图
    Int16 als104_jiguanghight;//整体激光最短长度
    Int16 als104_jiguanglong;//单边激光最短长度
    Int16 als104_jiguangkuandu;//激光粗细
    Int16 als104_Updif;//上半段倾斜开始斜度10
    Int16 als104_Updifmin;//上半段倾斜终止斜度10
    Int16 als104_Uplong;//上半段直线长度
    Int16 als104_Downdif;//下半段倾斜开始斜度0
    Int16 als104_Downdifmin;//下半段倾斜终止斜度0
    Int16 als104_Downdlong;//下半段直线长度
    Int16 als104_St_Down;//下半段拟合起点
    Int16 als104_Ed_Down;//下半段拟合终点
    Int16 als104_St_Up;//上半段拟合起点
    Int16 als104_Ed_Up;//上半段拟合终点
    Int16 als104_Updif2;//上半段倾斜开始斜度10
    Int16 als104_Updifmin2;//上半段倾斜终止斜度10
    Int16 als104_dis_center_st;     //距离中心点此处后开始统计
    Int16 als104_dis_center_ed;  //距离中心点此处后停止统计
    Int16 als104_b_opengudingdimian; //是否固定底面
    Int16 als104_dimianpangdingjuli;//两直线平面距离
    Int16 als104_dimianpingjunshunum;//底面平均数统计个数//10
    Int16 als104_dis_center_st2;//5;//0;     //距离中心点此处后开始统计
    Int16 als104_dis_center_ed2;//100;//30;  //距离中心点此处后停止统计
    Int16 als104_dis_center_st3;//5;//0;     //距离中心点此处后开始统计
    Int16 als104_dis_center_ed3;//500;//30;  //距离中心点此处后停止统计
    Int16 als104_xuexijuli;//学习距离
    Int16 als104_b_pingpowending;//平坡处稳定焊点
    Int16 als104_pingpowending_dis;//平坡处稳定距离
    Int16 als104_b_xielvopen;//斜率限制
    Int16 als104_xielvfanwei;//斜率范围
    Int16 als104_Uplong2;//在坡度时上半段直线检测长度
    Int16 als104_cebankongdongdis;//侧板跨孔洞的激光最短距离
    Int16 als104_qiatouquweijuli;//恰头去尾距离

    void write_als104_para();				//保存任务104参数
    void init_als104_para();				//初始化任务104参数

    Uint16 als104_exposure_time_min;
    Uint16 als104_exposure_time_max;
    Uint16 als104_exposure_time_use;
    Int16 als104_pingjun_min;
    Int16 als104_pingjun_max;
    Int16 als104_pingjun_use;
    Int16 als104_b_yanmofuzhu_min;
    Int16 als104_b_yanmofuzhu_max;
    Int16 als104_b_yanmofuzhu_use;
    Int16 als104_b_gudingquyu_min;
    Int16 als104_b_gudingquyu_max;
    Int16 als104_b_gudingquyu_use;
    Int16 als104_widthliantongdis_min;
    Int16 als104_widthliantongdis_max;
    Int16 als104_widthliantongdis_use;
    Int16 als104_highliantongdis_min;
    Int16 als104_highliantongdis_max;
    Int16 als104_highliantongdis_use;
    Int16 als104_gujiaerzhi_min;
    Int16 als104_gujiaerzhi_max;
    Int16 als104_gujiaerzhi_use;
    Int16 als104_jiguanghight_min;
    Int16 als104_jiguanghight_max;
    Int16 als104_jiguanghight_use;
    Int16 als104_jiguanglong_min;
    Int16 als104_jiguanglong_max;
    Int16 als104_jiguanglong_use;
    Int16 als104_jiguangkuandu_min;
    Int16 als104_jiguangkuandu_max;
    Int16 als104_jiguangkuandu_use;
    Int16 als104_Updif_min;
    Int16 als104_Updif_max;
    Int16 als104_Updif_use;
    Int16 als104_Updifmin_min;
    Int16 als104_Updifmin_max;
    Int16 als104_Updifmin_use;
    Int16 als104_Uplong_min;
    Int16 als104_Uplong_max;
    Int16 als104_Uplong_use;
    Int16 als104_Downdif_min;
    Int16 als104_Downdif_max;
    Int16 als104_Downdif_use;
    Int16 als104_Downdifmin_min;
    Int16 als104_Downdifmin_max;
    Int16 als104_Downdifmin_use;
    Int16 als104_Downdlong_min;
    Int16 als104_Downdlong_max;
    Int16 als104_Downdlong_use;
    Int16 als104_St_Down_min;
    Int16 als104_St_Down_max;
    Int16 als104_St_Down_use;
    Int16 als104_Ed_Down_min;
    Int16 als104_Ed_Down_max;
    Int16 als104_Ed_Down_use;
    Int16 als104_St_Up_min;
    Int16 als104_St_Up_max;
    Int16 als104_St_Up_use;
    Int16 als104_Ed_Up_min;
    Int16 als104_Ed_Up_max;
    Int16 als104_Ed_Up_use;
    Int16 als104_Updif2_min;
    Int16 als104_Updif2_max;
    Int16 als104_Updif2_use;
    Int16 als104_Updifmin2_min;
    Int16 als104_Updifmin2_max;
    Int16 als104_Updifmin2_use;
    Int16 als104_dis_center_st_min;
    Int16 als104_dis_center_st_max;
    Int16 als104_dis_center_st_use;
    Int16 als104_dis_center_ed_min;
    Int16 als104_dis_center_ed_max;
    Int16 als104_dis_center_ed_use;
    Int16 als104_b_opengudingdimian_min;
    Int16 als104_b_opengudingdimian_max;
    Int16 als104_b_opengudingdimian_use;
    Int16 als104_dimianpangdingjuli_min;
    Int16 als104_dimianpangdingjuli_max;
    Int16 als104_dimianpangdingjuli_use;
    Int16 als104_dimianpingjunshunum_min;
    Int16 als104_dimianpingjunshunum_max;
    Int16 als104_dimianpingjunshunum_use;
    Int16 als104_dis_center_st2_min;
    Int16 als104_dis_center_st2_max;
    Int16 als104_dis_center_st2_use;
    Int16 als104_dis_center_ed2_min;
    Int16 als104_dis_center_ed2_max;
    Int16 als104_dis_center_ed2_use;
    Int16 als104_dis_center_st3_min;
    Int16 als104_dis_center_st3_max;
    Int16 als104_dis_center_st3_use;
    Int16 als104_dis_center_ed3_min;
    Int16 als104_dis_center_ed3_max;
    Int16 als104_dis_center_ed3_use;
    Int16 als104_xuexijuli_min;
    Int16 als104_xuexijuli_max;
    Int16 als104_xuexijuli_use;
    Int16 als104_b_pingpowending_min;
    Int16 als104_b_pingpowending_max;
    Int16 als104_b_pingpowending_use;
    Int16 als104_pingpowending_dis_min;
    Int16 als104_pingpowending_dis_max;
    Int16 als104_pingpowending_dis_use;
    Int16 als104_b_xielvopen_min;
    Int16 als104_b_xielvopen_max;
    Int16 als104_b_xielvopen_use;
    Int16 als104_xielvfanwei_min;
    Int16 als104_xielvfanwei_max;
    Int16 als104_xielvfanwei_use;
    Int16 als104_Uplong2_min;
    Int16 als104_Uplong2_max;
    Int16 als104_Uplong2_use;
    Int16 als104_cebankongdongdis_min;
    Int16 als104_cebankongdongdis_max;
    Int16 als104_cebankongdongdis_use;
    Int16 als104_qiatouquweijuli_min;
    Int16 als104_qiatouquweijuli_max;
    Int16 als104_qiatouquweijuli_use;

/****************************/
    void write();
private:
    void read_para();				//读取
    void check_para();			//检查参数

    void Init_als100_E2proomData();
    void Init_als101_E2proomData();
    void Init_als102_E2proomData();
    void Init_als103_E2proomData();
    void Init_als104_E2proomData();
    
    void als100_check_para();
    void als101_check_para();
    void als102_check_para();
    void als103_check_para();
    void als104_check_para();

    void als100_read_para();
    void als101_read_para();
    void als102_read_para();
    void als103_read_para();
    void als104_read_para();
};

#endif // E2PROOMDATA_H
