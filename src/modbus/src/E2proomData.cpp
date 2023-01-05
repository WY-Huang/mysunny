#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

E2proomData::E2proomData()
{
    std::string dir = "./SAVE";
    if (access(dir.c_str(), 0) == -1)
    {
      mkdir("./SAVE",S_IRWXU);
    }

    task_num_min=E2POOM_TASK_NUM_MIN;
    task_num_use=E2POOM_TASK_NUM_USE;
    task_num_max=E2POOM_TASK_NUM_MAX;

    robot_port_min=E2POOM_ROBOT_PORT_MIN;
    robot_port_max=E2POOM_ROBOT_PORT_MAX;
    robot_port_use=E2POOM_ROBOT_PORT_USE;
    
    Init_als100_E2proomData();
    Init_als101_E2proomData();
    Init_als102_E2proomData();
    Init_als103_E2proomData();
    Init_als104_E2proomData();

    read_para();
}

E2proomData::~E2proomData()
{

}

void E2proomData::check_para()
{
    if(task_num<task_num_min||task_num_min>task_num_max)
      task_num=task_num_use;

    if(robot_mod!=E2POOM_ROBOT_MOD_NULL&&
       robot_mod!=E2POOM_ROBOT_MOD_ZHICHANG&&
       robot_mod!=E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI&&
       robot_mod!=E2POOM_ROBOT_MOD_MOKA_NABOTE
      )
      robot_mod=E2POOM_ROBOT_MOD_NULL;

    if(robot_port<robot_port_min||robot_port>robot_port_max)
        robot_port=robot_port_use;

    als100_check_para();
    als101_check_para();
    als102_check_para();
    als103_check_para();
    als104_check_para();
}

void E2proomData::read_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_TASK_NUM_SAVEBUFF];    
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_TASK_NUM_SYSPATH_MOTO,buff,E2POOM_TASK_NUM_SAVEBUFF))
    {
        init_task_num_para();
        if(buff!=NULL)
        {
          delete []buff;
          buff=NULL;
        }
    }
    else
    {
      Uint16 *u16_p;

      u16_p = (Uint16*)buff;
      task_num=*u16_p;
      u16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }


    buff=new Uint8[E2POOM_ROBOT_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_ROBOT_SYSPATH_MOTO,buff,E2POOM_ROBOT_SAVEBUFF))
    {
        init_robot_para();
        if(buff!=NULL)
        {
          delete []buff;
          buff=NULL;
        }
    }
    else
    {
      Uint16 *u16_p;

      u16_p = (Uint16*)buff;
      robot_mod=*u16_p;
      u16_p++;
      robot_port=*u16_p;
      u16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

    als100_read_para();
    als101_read_para();
    als102_read_para();
    als103_read_para();
    als104_read_para();
    
    check_para();

}

void E2proomData::write_task_num_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_TASK_NUM_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *u16_p;

    u16_p = (Uint16*)buff;
    *u16_p=task_num;
    u16_p++;

    fo.WriteFile(E2POOM_TASK_NUM_SYSPATH_MOTO,buff,E2POOM_TASK_NUM_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_task_num_para()
{
    task_num=E2POOM_TASK_NUM_USE;
}

void E2proomData::write_robot_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ROBOT_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *u16_p;

    u16_p = (Uint16*)buff;
    *u16_p=robot_mod;
    u16_p++;
    *u16_p=robot_port;
    u16_p++;

    fo.WriteFile(E2POOM_ROBOT_SYSPATH_MOTO,buff,E2POOM_ROBOT_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_robot_para()
{
    robot_mod=E2POOM_ROBOT_MOD_NULL;
    robot_port=E2POOM_ROBOT_PORT_USE;
}

void E2proomData::write()
{
    write_als100_para();
    write_als101_para();
    write_als102_para();
    write_als103_para();
    write_als104_para();
}
