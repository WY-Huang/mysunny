#include "fileout/E2camData.h"
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

    camer_size_width_min=E2POOM_CAMER_SIZE_WIDTH_MIN;
    camer_size_width_max=E2POOM_CAMER_SIZE_WIDTH_MAX;
    camer_size_width_use=E2POOM_CAMER_SIZE_WIDTH_USE;
    camer_size_height_min=E2POOM_CAMER_SIZE_HEIGHT_MIN;
    camer_size_height_max=E2POOM_CAMER_SIZE_HEIGHT_MAX;
    camer_size_height_use=E2POOM_CAMER_SIZE_HEIGHT_USE;
    camer_fps_min=E2POOM_CAMER_FPS_MIN;
    camer_fps_max=E2POOM_CAMER_FPS_MAX;
    camer_fps_use=E2POOM_CAMER_FPS_USE;
    camer_size_view_width_min=E2POOM_CAMER_SIZE_VIEW_WIDTH_MIN;
    camer_size_view_width_use=E2POOM_CAMER_SIZE_VIEW_WIDTH_USE;
    camer_size_view_width_max=E2POOM_CAMER_SIZE_VIEW_WIDTH_MAX;
    camer_size_view_height_min=E2POOM_CAMER_SIZE_VIEW_HEIGHT_MIN;
    camer_size_view_height_use=E2POOM_CAMER_SIZE_VIEW_HEIGHT_USE;
    camer_size_view_height_max=E2POOM_CAMER_SIZE_VIEW_HEIGHT_MAX;

    read_para();
}

E2proomData::~E2proomData()
{

}

void E2proomData::check_para()
{

    if(camer_size_width<camer_size_width_min||camer_size_width>camer_size_width_max)
        camer_size_width=camer_size_width_use;
    
    if(camer_size_height<camer_size_height_min||camer_size_height>camer_size_height_max)
        camer_size_height=camer_size_height_use;

    if(camer_fps<camer_fps_min||camer_fps>camer_fps_max)
        camer_fps=camer_fps_use;

    if(camer_size_view_width<camer_size_view_width_min||camer_size_view_width>camer_size_view_width_max)
        camer_size_view_width=camer_size_view_width_use;

    if(camer_size_view_height<camer_size_view_height_min||camer_size_view_height>camer_size_view_height_max)
        camer_size_view_height=camer_size_view_height_use;
}

void E2proomData::read_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_CAMER_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_CAMER_SYSPATH_MOTO,buff,E2POOM_CAMER_SAVEBUFF))
    {
        init_camer_para();
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
      camer_size_width=*u16_p;
      u16_p++;
      camer_size_height=*u16_p;
      u16_p++;
      camer_fps=*u16_p;
      u16_p++;
      camer_size_view_width=*u16_p;
      u16_p++;
      camer_size_view_height=*u16_p;
      u16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
    
    check_para();

}

void E2proomData::write_camer_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_CAMER_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *u16_p;

    u16_p = (Uint16*)buff;
    *u16_p=camer_size_width;
    u16_p++;
    *u16_p=camer_size_height;
    u16_p++;
    *u16_p=camer_fps;
    u16_p++;
    *u16_p=camer_size_view_width;
    u16_p++;
    *u16_p=camer_size_view_height;
    u16_p++;

    fo.WriteFile(E2POOM_CAMER_SYSPATH_MOTO,buff,E2POOM_CAMER_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_camer_para()
{
    camer_size_width=camer_size_width_use;
    camer_size_height=camer_size_height_use;
    camer_fps=camer_fps_use;
    camer_size_view_width=camer_size_view_width_use;
    camer_size_view_height=camer_size_view_height_use;
}
