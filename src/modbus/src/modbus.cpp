#include <cstdio>

// Copyright 2019 Zhushi Tech, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <modbus/modbus.hpp>
// #include <netinet/in.h>
// #include <sys/socket.h>
// #include <sys/socket.h>
// #include <errno.h>
#include <modbus.h>
// #include <stdio.h>
#include <unistd.h>
#include <fileout/FileOut.h>
#include <fileout/E2proomData.h>


// #include <climits>
#include <memory>
#include <set>
// #include <fstream>
// #include <string>
// #include <utility>
// #include <vector>
// #include <iostream>

namespace modbus
{
//using rcl_interfaces::msg::SetParametersResult;
//tcp sock
TCPServer jsontcp;

Modbus::Modbus(const rclcpp::NodeOptions & options)
: Node("modbus_node", options)
{
  sleep(5);
  _param_camera = std::make_shared<rclcpp::AsyncParametersClient>(this, "camera_tis_node");
  _param_camera_get = std::make_shared<rclcpp::AsyncParametersClient>(this, "camera_tis_node");
  _param_gpio = std::make_shared<rclcpp::AsyncParametersClient>(this, "gpio_raspberry_node");
  _param_linecenter = std::make_shared<rclcpp::AsyncParametersClient>(this, "laser_line_center_node");
  _param_laserimagepos = std::make_shared<rclcpp::AsyncParametersClient>(this, "laser_imagepos_node");


  this->declare_parameter("robotsetport", 1501);    //机器人型号设置及通信端口
  auto robotsetport = this->get_parameter("robotsetport").as_int();

  this->declare_parameter("robot_mod", e2proomdata.robot_mod);

  robot_mapping=modbus_mapping_new(0, 0, ROBOT_SET_REGEDIST_NUM, 0);
  if (!robot_mapping) {
    RCLCPP_ERROR(this->get_logger(), "Failed to initialize modbusrobot registers.");
    rclcpp::shutdown();
    return;
  }
  robot_mapping->tab_registers[ROBOT_MOD_REG_ADD]=(u_int16_t)e2proomdata.robot_mod;
  robot_mapping->tab_registers[ROBOT_PORT_REG_ADD]=(u_int16_t)e2proomdata.robot_port;

  camer_width=1536;
  camer_height=1024;
  camer_fps=30;
  camer_view_width=3072;
  camer_view_height=2048;

  _param_camera_get->wait_for_service();
  auto parameters_future = _param_camera_get->get_parameters(
                {"width","height","fps","view_width","view_height"},
                std::bind(&Modbus::callbackGlobalParam, this, std::placeholders::_1));
               

  ctx_robot = modbus_new_tcp(NULL, robotsetport);
  if (!ctx_robot) {
    RCLCPP_ERROR(this->get_logger(), "Failed to create modbusrobot context.");
    rclcpp::shutdown();
    return;
  }
  _thread_robotset = std::thread(&Modbus::_modbusrobotset, this, robotsetport);

  this->declare_parameter("parameterport", 1500);   //框架2参数设置端口
  auto parameterport = this->get_parameter("parameterport").as_int();
  
  int port;
  this->declare_parameter("port", 1502);  //modbustcp协议端口
  port = this->get_parameter("port").as_int(); 

  int robot_port;
  this->declare_parameter("robot_port", e2proomdata.robot_port);  //modbustcp协议端口
  robot_port = this->get_parameter("robot_port").as_int(); 

  parameterport_mapping=modbus_mapping_new(0, 0, PARAMETER_REGEDIST_NUM, 0);
  if (!parameterport_mapping) {
    RCLCPP_ERROR(this->get_logger(), "Failed to initialize modbusparameter registers.");
    rclcpp::shutdown();
    return;
  }

  init_als100_parameter();
  init_als101_parameter();
  init_als102_parameter();
  init_als103_parameter();
  init_als104_parameter();
  
  static int oldparameter[PARAMETER_REGEDIST_NUM]={INT_MAX};
  for(int i=0;i<PARAMETER_REGEDIST_NUM;i++)
  {
    if(oldparameter[i]!=parameterport_mapping->tab_registers[i])
    {
      oldparameter[i]=parameterport_mapping->tab_registers[i];
      _task_parameter(i,oldparameter[i]);
    }
  }

  ctx_parameterport = modbus_new_tcp(NULL, parameterport);
  if (!ctx_parameterport) {
    RCLCPP_ERROR(this->get_logger(), "Failed to create modbusparameter context.");
    rclcpp::shutdown();
    return;
  }
  _thread_parameterport = std::thread(&Modbus::_modbusparameterport, this, parameterport);

  mb_mapping = modbus_mapping_new(0, 0, SERVER_REGEDIST_NUM, 0);
  if (!mb_mapping) {
    RCLCPP_ERROR(this->get_logger(), "Failed to initialize modbus registers.");
    rclcpp::shutdown();
    return;
  }
  mb_mapping->tab_registers[1] = 0xff;
  mb_mapping->tab_registers[0x102] = (u_int16_t)e2proomdata.task_num;
  _task_numberset(e2proomdata.task_num);
  RCLCPP_INFO(this->get_logger(), "task=%d",e2proomdata.task_num);

  mb_forwardmapping = modbus_mapping_new(0, 0, SERVER_REGEDIST_NUM, 0);
  if (!mb_forwardmapping) {
    RCLCPP_ERROR(this->get_logger(), "Failed to initialize modbusforward registers.");
    rclcpp::shutdown();
    return;
  }

  ctx = modbus_new_tcp(NULL, port);
  if (!ctx) {
    RCLCPP_ERROR(this->get_logger(), "Failed to create modbus context.");
    rclcpp::shutdown();
    return;
  }
  _thread = std::thread(&Modbus::_modbus, this, port);


  b_threadforward=false;
  b_jsontcpthread=false;
  switch(e2proomdata.robot_mod)
  {
  case E2POOM_ROBOT_MOD_NULL:
  break;
  case E2POOM_ROBOT_MOD_ZHICHANG:
  case E2POOM_ROBOT_MOD_MOKA_NABOTE:
      
      ctx_forward = modbus_new_tcp(NULL, robot_port);
      if (!ctx_forward) {
        RCLCPP_ERROR(this->get_logger(), "Failed to create modbusforward context.");
        rclcpp::shutdown();
        return;
      }
      _threadforward = std::thread(&Modbus::_modbusforward, this, robot_port);
      b_threadforward = true;
      break;
  case E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI:
      num_client=0;
      _jsontcpthread = std::thread(&Modbus::_json, this, robot_port);
      b_jsontcpthread = true;
      break;
  default:
      break;
  }
  RCLCPP_INFO(this->get_logger(), "Initialized successfully");
}

Modbus::~Modbus()
{
  try {
    _thread_robotset.join();
    _thread_parameterport.join();
    _thread.join();
    if(b_jsontcpthread==true)
      _jsontcpthread.join();
    if(b_threadforward==true)
      _threadforward.join();
    _param_gpio.reset();
    _param_camera.reset();
    _param_camera_get.reset();
    _param_linecenter.reset();
//   _handle.reset();
    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: unknown");
  }
}

/**
 * @brief Control laser on of off.
 *
 * @param f true if on.
 */
void Modbus::_gpio_laser(bool f)
{
  if (f) {
    _param_gpio->set_parameters({rclcpp::Parameter("laser", true)});
  } else {
    _param_gpio->set_parameters({rclcpp::Parameter("laser", false)});
  }
}

void Modbus::callbackGlobalParam(std::shared_future<std::vector<rclcpp::Parameter>> future)
{
    auto result = future.get();
    if(result.size()>=5)
    {
      auto width = result.at(0);
      auto height = result.at(1);
      auto fps = result.at(2);
      auto view_width = result.at(3);
      auto view_height = result.at(4);
      RCLCPP_INFO(this->get_logger(), "width param: %d", width.as_int());
      RCLCPP_INFO(this->get_logger(), "height param: %d", height.as_int());
      RCLCPP_INFO(this->get_logger(), "fps param: %d", fps.as_int());
      RCLCPP_INFO(this->get_logger(), "view_width param: %d", view_width.as_int());
      RCLCPP_INFO(this->get_logger(), "view_height param: %d", view_height.as_int());

      robot_mapping->tab_registers[CAMER_SIZE_WIDTH_REG_ADD]=(u_int16_t)width.as_int();
      robot_mapping->tab_registers[CAMER_SIZE_HEIGHT_REG_ADD]=(u_int16_t)height.as_int();  
      robot_mapping->tab_registers[CAMER_FPS_REG_ADD]=(u_int16_t)fps.as_int();  
      robot_mapping->tab_registers[CAMER_SIZE_VIEW_WIDTH_REG_ADD]=(u_int16_t)view_width.as_int();  
      robot_mapping->tab_registers[CAMER_SIZE_VIEW_HEIGHT_REG_ADD]=(u_int16_t)view_height.as_int();  
    }
    else
    {
      RCLCPP_ERROR(this->get_logger(), "Get camer info error.");
    }
}

/*
void Modbus::_camera_get_size(int *width,int *height)
{
    const std::vector<std::string> KEYS = {"width","height"};
    _param_camera_get->wait_for_service();
    auto vp = _param_camera_get->get_parameters(KEYS);
    for (auto & p : vp)
    {
        if (p.get_name() == "width")
        {
            auto k = p.as_int();
            *width=k;
        }
        else if (p.get_name() == "height")
        {
            auto k = p.as_int();
            *height=k;
        }
    }
}
*/
void Modbus::_camera_set_size(int width,int height)
{
    _param_camera->set_parameters({rclcpp::Parameter("width", width)});
    _param_camera->set_parameters({rclcpp::Parameter("height", height)});
}
/**
 * @brief Control camera capture or not.
 *
 * @param f true if enable camera capture.
 */
void Modbus::_camera_power(bool f)
{
  if (f) {
    _param_camera->set_parameters({rclcpp::Parameter("power", true)});
    _param_laserimagepos->set_parameters({rclcpp::Parameter("start", 1)});
  } else {
    _param_camera->set_parameters({rclcpp::Parameter("power", false)});
  }
}

void Modbus::_task_numberset(u_int16_t num)
{
  _param_linecenter->set_parameters({rclcpp::Parameter("task_num", num)}); 
  _param_laserimagepos->set_parameters({rclcpp::Parameter("task_num", num)}); 
  e2proomdata.task_num=num;
  e2proomdata.write_task_num_para();
}


void Modbus::_task_parameter(int ddr,u_int16_t num)
{
  switch(ddr)
  {
    case ALS_SHOW_STEP_REG_ADD:
      _param_laserimagepos->set_parameters({rclcpp::Parameter("show_step", num)});
      return;
    break;
  }
  if(0!=als100_task_parameter(ddr,num))
      return;
  if(0!=als101_task_parameter(ddr,num))
      return;
  if(0!=als102_task_parameter(ddr,num))
      return;
  if(0!=als103_task_parameter(ddr,num))
      return;
  if(0!=als104_task_parameter(ddr,num))
      return;
}

void Modbus::_task_robot(int ddr,u_int16_t num)
{
  switch(ddr)
  {
    case ROBOT_MOD_REG_ADD: 
      e2proomdata.robot_mod=num;
      this->set_parameters({rclcpp::Parameter("robot_mod", (u_int16_t)e2proomdata.robot_mod)});
    break;
    case ROBOT_PORT_REG_ADD:
      e2proomdata.robot_port=num;
      this->set_parameters({rclcpp::Parameter("robot_port", (u_int16_t)e2proomdata.robot_port)});
    break;
    case CAMER_SIZE_WIDTH_REG_ADD:
      _param_camera->set_parameters({rclcpp::Parameter("width", num)});
    break;
    case CAMER_SIZE_HEIGHT_REG_ADD:
      _param_camera->set_parameters({rclcpp::Parameter("height", num)});
    break;
    case CAMER_FPS_REG_ADD:
      _param_camera->set_parameters({rclcpp::Parameter("fps", num)});
    break;
    case CAMER_SIZE_VIEW_WIDTH_REG_ADD:
      _param_camera->set_parameters({rclcpp::Parameter("view_width", num)});
    break;
    case CAMER_SIZE_VIEW_HEIGHT_REG_ADD:
      _param_camera->set_parameters({rclcpp::Parameter("view_height", num)});
    break;
    default:
    break;
  }
}

/**
 * @brief Construct a new impl object.
 *
 * Declare parameters before usage.
 * Establish a new TCP modbus via a specific port.
 * Listen to port.
 * Initialize a mapping block.
 * Start a thread to recursively accept and receive requests.
 * @param ptr Reference to parent node.
 */
void Modbus::_modbus(int port)
{
  // int aaa = 0;
  // auto nnn = std::chrono::system_clock::now();
  // std::vector<double> vvv;
  // vvv.resize(1800);
  auto sock = modbus_tcp_listen(ctx, 10);
  if (sock == -1) 
  {
    modbus_mapping_free(mb_mapping);
    modbus_free(ctx);
    RCLCPP_ERROR(this->get_logger(), "Failed to listen.");
    rclcpp::shutdown();
    return;
  }

  std::set<int> fds {sock};

  fd_set refset;
  FD_ZERO(&refset);
  FD_SET(sock, &refset);

  int fdmax = sock;
  uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
  int ret = 0;
  while (rclcpp::ok() && ret != -1) 
  {
    auto rdset = refset;
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    ret = select(fdmax + 1, &rdset, NULL, NULL, &tv);
    if (ret == -1) 
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to select.");
      continue;
    } 
    else if (ret == 0) 
    {
      // time out.
      continue;
    }

    auto fds_bak = fds;
    for (auto fd : fds_bak) 
    {
      if (!FD_ISSET(fd, &rdset)) 
        {continue;}

      if (fd == sock) 
      {
        
        ret = modbus_tcp_accept(ctx, &sock);
        if (ret != -1) 
        {
          FD_SET(ret, &refset);
          fds.insert(fds.end(), ret);
          fdmax = *fds.rbegin();
        } else 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to accept.");
          break;
        }
      } 
      else 
      {
        // A client is asking for reply
        ret = modbus_set_socket(ctx, fd);
        if (ret == -1) 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to set socket.");
          break;
        }
        ret = modbus_receive(ctx, query);
        if (ret == -1) 
        {
          // Connection closed by the client or error
          close(fd);
          FD_CLR(fd, &refset);
          fds.erase(fd);
          fdmax = *fds.rbegin();
          ret = 0;
        } 
        else if (ret > 0) 
        {
          if (ret > 14 && query[7] == 0x10 && query[8] == 0x01 && query[9] == 0x01) 
          {
            if (query[14]) 
            {
              _gpio_laser(true);
              _camera_power(true);
            } else 
            {
              _camera_power(false);
              _gpio_laser(false);
            }
          }
          ret = modbus_reply(ctx, query, ret, mb_mapping);

          static int oldtasknum=INT_MAX;
          if(oldtasknum!=mb_mapping->tab_registers[0x102])
          {
            oldtasknum=mb_mapping->tab_registers[0x102];
            _task_numberset(oldtasknum);
          }

          switch(e2proomdata.robot_mod)
          {
            case E2POOM_ROBOT_MOD_NULL:
            break;
            case E2POOM_ROBOT_MOD_ZHICHANG:
            case E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI:
              for(int i=0;i<SERVER_REGEDIST_NUM;i++)
              {
                mb_forwardmapping->tab_registers[i],mb_mapping->tab_registers[i];
              }
            break;
            case E2POOM_ROBOT_MOD_MOKA_NABOTE:
              mb_forwardmapping->tab_registers[0x0000]=mb_mapping->tab_registers[0x102];
              if(mb_mapping->tab_registers[0x02]==0xff)
                  mb_forwardmapping->tab_registers[0x0010]=1;
              else 
                  mb_forwardmapping->tab_registers[0x0010]=0;
              mb_forwardmapping->tab_registers[0x0011]=0;
              mb_forwardmapping->tab_registers[0x0012]=mb_mapping->tab_registers[0x03];
              mb_forwardmapping->tab_registers[0x0013]=mb_mapping->tab_registers[0x04];
            break; 
            default:
            break;
          }
          

          if (ret == -1) 
          {
            RCLCPP_ERROR(this->get_logger(), "Failed to reply.");
          //break;
          }
        }
      }
    }
  }

  close(sock);
  modbus_mapping_free(mb_mapping);
  modbus_free(ctx);
  if (ret == -1) 
  {
    rclcpp::shutdown();
  }
}

void Modbus::_modbusrobotset(int port)
{
  auto sock = modbus_tcp_listen(ctx_robot, 10);
  if (sock == -1) 
  {
    modbus_mapping_free(robot_mapping);
    modbus_free(ctx_robot);
    RCLCPP_ERROR(this->get_logger(), "Failed to listen.");
    rclcpp::shutdown();
    return;
  }

  std::set<int> fds {sock};

  fd_set refset;
  FD_ZERO(&refset);
  FD_SET(sock, &refset);

  int fdmax = sock;
  uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
  int ret = 0;
  while (rclcpp::ok() && ret != -1) 
  {
    auto rdset = refset;
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    ret = select(fdmax + 1, &rdset, NULL, NULL, &tv);
    if (ret == -1) 
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to select.");
      continue;
    } 
    else if (ret == 0) 
    {
      // time out.
      continue;
    }

    auto fds_bak = fds;
    for (auto fd : fds_bak) 
    {
      if (!FD_ISSET(fd, &rdset)) 
        {continue;}

      if (fd == sock) 
      {
        // A client is asking a new connection
        // struct sockaddr_in clientaddr;
        // socklen_t addrlen = sizeof(clientaddr);
        // memset(&clientaddr, 0, sizeof(clientaddr));
        // ret = accept(sock, (struct sockaddr *)&clientaddr, &addrlen);
        ret = modbus_tcp_accept(ctx_robot, &sock);
        if (ret != -1) 
        {
          FD_SET(ret, &refset);
          fds.insert(fds.end(), ret);
          fdmax = *fds.rbegin();
        } 
        else 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to accept.");
          break;
        }
      }
      else 
      {
        // A client is asking for reply
        ret = modbus_set_socket(ctx_robot, fd);
        if (ret == -1) 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to set socket.");
          break;
        }
        ret = modbus_receive(ctx_robot, query);
        if (ret == -1) 
        {
          // Connection closed by the client or error
          close(fd);
          FD_CLR(fd, &refset);
          fds.erase(fd);
          fdmax = *fds.rbegin();
          ret = 0;
        } 
        else if (ret > 0) 
        {
          ret = modbus_reply(ctx_robot, query, ret, robot_mapping);
          
          static int oldrobot[ROBOT_SET_REGEDIST_NUM]={INT_MAX};
          u_int8_t u8_temp=0;
          for(int i=0;i<ROBOT_SET_REGEDIST_NUM;i++)
          {
            if(oldrobot[i]!=robot_mapping->tab_registers[i])
            {
              oldrobot[i]=robot_mapping->tab_registers[i];
              u8_temp=1;
              _task_robot(i,oldrobot[i]);
            }
          }
          if(u8_temp==1)
          {
            e2proomdata.write_robot_para();
          }
          
         /*
          e2proomdata.robot_mod=(Uint16)robot_mapping->tab_registers[0];
          e2proomdata.robot_port=(Uint16)robot_mapping->tab_registers[1];
          e2proomdata.write_robot_para();
        */
          if (ret == -1) 
          {
            RCLCPP_ERROR(this->get_logger(), "Failed to reply.");
          //break;
          }
        }
      }
    }
  }

  close(sock);
  modbus_mapping_free(robot_mapping);
  modbus_free(ctx_robot);
  if (ret == -1) 
  {
    rclcpp::shutdown();
  }
  // std::ofstream ofile("/diff.txt");
  // for(auto d : vvv) {
  //   ofile << d << "\n";
  // }
  // ofile.close();
}

void Modbus::_modbusparameterport(int port)
{
  // int aaa = 0;
  // auto nnn = std::chrono::system_clock::now();
  // std::vector<double> vvv;
  // vvv.resize(1800);
  auto sock = modbus_tcp_listen(ctx_parameterport, 10);
  if (sock == -1) 
  {
    modbus_mapping_free(parameterport_mapping);
    modbus_free(ctx_parameterport);
    RCLCPP_ERROR(this->get_logger(), "Failed to listen.");
    rclcpp::shutdown();
    return;
  }

  std::set<int> fds {sock};

  fd_set refset;
  FD_ZERO(&refset);
  FD_SET(sock, &refset);

  int fdmax = sock;
  uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
  int ret = 0;
  while (rclcpp::ok() && ret != -1) 
  {
    auto rdset = refset;
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    ret = select(fdmax + 1, &rdset, NULL, NULL, &tv);
    if (ret == -1) 
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to select.");
      continue;
    } 
    else if (ret == 0) 
    {
      // time out.
      continue;
    }

    auto fds_bak = fds;
    for (auto fd : fds_bak) 
    {
      if (!FD_ISSET(fd, &rdset)) {continue;}

      if (fd == sock) 
      {
        // A client is asking a new connection
        // struct sockaddr_in clientaddr;
        // socklen_t addrlen = sizeof(clientaddr);
        // memset(&clientaddr, 0, sizeof(clientaddr));
        // ret = accept(sock, (struct sockaddr *)&clientaddr, &addrlen);
        ret = modbus_tcp_accept(ctx_parameterport, &sock);
        if (ret != -1) 
        {
          FD_SET(ret, &refset);
          fds.insert(fds.end(), ret);
          fdmax = *fds.rbegin();
        } 
        else 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to accept.");
          break;
        }
      } 
      else 
      {
        // A client is asking for reply
        ret = modbus_set_socket(ctx_parameterport, fd);
        if (ret == -1) 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to set socket.");
          break;
        }
        ret = modbus_receive(ctx_parameterport, query);
        if (ret == -1) 
        {
          // Connection closed by the client or error
          close(fd);
          FD_CLR(fd, &refset);
          fds.erase(fd);
          fdmax = *fds.rbegin();
          ret = 0;
        } 
        else if (ret > 0) 
        {
          ret = modbus_reply(ctx_parameterport, query, ret, parameterport_mapping);

          static int oldparameter[PARAMETER_REGEDIST_NUM]={INT_MAX};
          u_int8_t u8_temp=0;
          for(int i=0;i<PARAMETER_REGEDIST_NUM;i++)
          {
            if(oldparameter[i]!=parameterport_mapping->tab_registers[i])
            {
              oldparameter[i]=parameterport_mapping->tab_registers[i];
              u8_temp=1;
              _task_parameter(i,oldparameter[i]);
            }
          }
          if(u8_temp==1)
          {
            e2proomdata.write();
          }
          if (ret == -1) 
          {
            RCLCPP_ERROR(this->get_logger(), "Failed to reply.");
          //break;
          }
        }
      }
    }
  }
  close(sock);
  modbus_mapping_free(parameterport_mapping);
  modbus_free(ctx_parameterport);
  if (ret == -1) {
    rclcpp::shutdown();
  }
  // std::ofstream ofile("/diff.txt");
  // for(auto d : vvv) {
  //   ofile << d << "\n";
  // }
  // ofile.close();
}

void Modbus::_modbusforward(int port)
{
 // int aaa = 0;
  // auto nnn = std::chrono::system_clock::now();
  // std::vector<double> vvv;
  // vvv.resize(1800);
  auto sock = modbus_tcp_listen(ctx_forward, 10);
  if (sock == -1) 
  {
    modbus_mapping_free(mb_forwardmapping);
    modbus_free(ctx_forward);
    RCLCPP_ERROR(this->get_logger(), "Failed to listen.");
    rclcpp::shutdown();
    return;
  }

  std::set<int> fds {sock};

  fd_set refset;
  FD_ZERO(&refset);
  FD_SET(sock, &refset);

  int fdmax = sock;
  uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
  int ret = 0;
  while (rclcpp::ok() && ret != -1) 
  {
    auto rdset = refset;
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    ret = select(fdmax + 1, &rdset, NULL, NULL, &tv);
    if (ret == -1) 
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to select.");
      continue;
    } 
    else if (ret == 0) 
    {
      // time out.
      continue;
    }

    auto fds_bak = fds;
    for (auto fd : fds_bak) 
    {
      if (!FD_ISSET(fd, &rdset)) {continue;}

      if (fd == sock) 
      {
        
        ret = modbus_tcp_accept(ctx_forward, &sock);
        if (ret != -1) 
        {
          FD_SET(ret, &refset);
          fds.insert(fds.end(), ret);
          fdmax = *fds.rbegin();
        } 
        else 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to accept.");
          break;
        }
      } 
      else 
      {
        // A client is asking for reply
        ret = modbus_set_socket(ctx_forward, fd);
        if (ret == -1) 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to set socket.");
          break;
        }
        ret = modbus_receive(ctx_forward, query);
        if (ret == -1) 
        {
          // Connection closed by the client or error
          close(fd);
          FD_CLR(fd, &refset);
          fds.erase(fd);
          fdmax = *fds.rbegin();
          ret = 0;
        } 
        else if (ret > 0) 
        {
          ret = modbus_reply(ctx_forward, query, ret, mb_forwardmapping);

          switch(e2proomdata.robot_mod)
          {
            case E2POOM_ROBOT_MOD_NULL:
            case E2POOM_ROBOT_MOD_ZHICHANG:
            {
              if (ret > 14 && query[7] == 0x10 && query[8] == 0x01 && query[9] == 0x01) {
                if (query[14]) {
                  _gpio_laser(true);
                  _camera_power(true);
                  mb_mapping->tab_registers[0x101]=mb_forwardmapping->tab_registers[0x101];
                } else {
                  _camera_power(false);
                  _gpio_laser(false);
                  mb_mapping->tab_registers[0x101]=mb_forwardmapping->tab_registers[0x101];
                }
              }
            
              static int oldtasknum=INT_MAX;
              if(oldtasknum!=mb_forwardmapping->tab_registers[0x102])
              {
                oldtasknum=mb_forwardmapping->tab_registers[0x102];
                mb_mapping->tab_registers[0x102]=oldtasknum;
                _task_numberset(oldtasknum);
              }
            }
            break;
            case E2POOM_ROBOT_MOD_MOKA_NABOTE:
            {
              static int oldtasknum=INT_MAX;
              if(oldtasknum!=mb_forwardmapping->tab_registers[0x000])
              {
                oldtasknum=mb_forwardmapping->tab_registers[0x000];
                mb_mapping->tab_registers[0x102]=oldtasknum;
                _task_numberset(oldtasknum);
              }

              static int oldgpio_laser=INT_MAX;
              if(oldgpio_laser!=mb_forwardmapping->tab_registers[0x001])
              {
                oldgpio_laser=mb_forwardmapping->tab_registers[0x001];
                if(oldgpio_laser==0x001)
                {
                  _gpio_laser(true);
                }
                else if(oldgpio_laser==0x000)
                {
                  _gpio_laser(false);
                }
              }

              static int oldcamera_power=INT_MAX;
              if(mb_forwardmapping->tab_registers[0x002]==1||mb_forwardmapping->tab_registers[0x003]==1)
              {
                if(oldcamera_power!=1)
                {
                  oldcamera_power=1;
                  _camera_power(true);
                }
              }
              else
              {
                if(oldcamera_power!=0)
                {
                  oldcamera_power=0;
                  _camera_power(false);
                }
              }
            }
            break;
            default:
            break;
          }
          if (ret == -1) 
          {
            RCLCPP_ERROR(this->get_logger(), "Failed to reply.");
          //break;
          }
        }
      }
    }
  }

  close(sock);
  modbus_mapping_free(mb_forwardmapping);
  modbus_free(ctx_forward);
  if (ret == -1) {
    rclcpp::shutdown();
  }
  // std::ofstream ofile("/diff.txt");
  // for(auto d : vvv) {
  //   ofile << d << "\n";
  // }
  // ofile.close();
}


void Modbus::_json(int port)
{
    pthread_t msg;
    std::signal(SIGINT, close_app);
    std::vector<int> opts = { SO_REUSEPORT, SO_REUSEADDR };
    if( jsontcp.setup(port,opts) != 0)
    {
         RCLCPP_ERROR(this->get_logger(), "Errore json socket.");
    }
    else
    {
        if( pthread_create(&msg, NULL, received, this) == 0)
        {
            while(rclcpp::ok()) {
                jsontcp.accepted();
                cerr << "Accepted" << endl;
            }
        }
    } 
}

void close_app(int s) 
{
    jsontcp.closed();
    rclcpp::shutdown();
}

void* received(void *m)
{
    Modbus *_p=(Modbus*)m;
    pthread_detach(pthread_self());
    while(rclcpp::ok())
    {
        _p->desc = jsontcp.getMessage();
        for(unsigned int i = 0; i < _p->desc.size(); i++) 
        {
            if( _p->desc[i] )
            {
                cout << "id:      " << _p->desc[i]->id      << endl
                    << "ip:      " << _p->desc[i]->ip      << endl
                    << "message: " << _p->desc[i]->message << endl
                    << "socket:  " << _p->desc[i]->socket  << endl
                    << "enable:  " << _p->desc[i]->enable_message_runtime << endl;

                    Json::Value root;
                    jsonfuction js;
                    Json::Value sent_root;
                switch(_p->e2proomdata.robot_mod)
                {
                  case E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI:
                  {
                #ifdef USE_PARENTHESES_INSTEAD_QUOTATION
                    for(unsigned int n=0;n<_p->desc[i]->message.size();n++)
                    {
                        if(_p->desc[i]->message[n]==0x28||_p->desc[i]->message[n]==0x29)   //"
                        {
                           _p->desc[i]->message[n]=0x22; 
                        }
                    }
                #endif
                    if(0==js.readJsonFromString(_p->desc[i]->message,&root))
                    {
                        Json::Value::Members mem = root.getMemberNames();
                        Json::Value::Members::iterator it = mem.begin(), end = mem.end();
                        for(; it != end; it ++)
                        {
                        //  cout<<*it<< endl; 
                            if(*it=="leaser")   
                            {
                              //  cout<<root[*it].asString();
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        if(root[*it].asString()=="open")
                                        {
                                            _p->_gpio_laser(true);
                                            _p->_camera_power(true);
                                            _p->mb_mapping->tab_registers[0x101]=0xff;  
                                            sent_root["leaser"]="open ok";
                                        }
                                        else if(root[*it].asString()=="close")
                                        {
                                            _p->_gpio_laser(false);
                                            _p->_camera_power(false);
                                            _p->mb_mapping->tab_registers[0x101]=0; 
                                            sent_root["leaser"]="close ok";
                                        }
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                            else if(*it=="tasknum")
                            {
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        std::string s_tasknum=root[*it].asString();
                                        int ID = atoi(s_tasknum.c_str());
                                        _p->mb_mapping->tab_registers[0x102]=ID;
                                        sent_root["tasknum"]=s_tasknum+" ok";
                                        static int oldtasknum=INT_MAX;
                                        if(oldtasknum!=_p->mb_mapping->tab_registers[0x102])
                                        {
                                          oldtasknum=_p->mb_mapping->tab_registers[0x102];
                                          _p->_task_numberset(oldtasknum);
                                        }
                                        
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                            else if(*it=="getdelay")
                            {
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        if(root[*it].asString()=="once")
                                        {
                                            u_int16_t delay=_p->mb_mapping->tab_registers[0x001];
                                            sent_root["getdelay"]=to_string(delay);
                                        }
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                            else if(*it=="getsearchstat")
                            {
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        if(root[*it].asString()=="once")
                                        {
                                            u_int16_t stat=_p->mb_mapping->tab_registers[0x002];
                                            if(stat==0xff)
                                            {
                                                sent_root["getsearchstat"]="ok";
                                            }
                                            else if(stat==0)
                                            {
                                                sent_root["getsearchstat"]="ng";
                                            }
                                            else
                                            {
                                                sent_root["getsearchstat"]="failed";
                                            }
                                        }
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                            else if(*it=="getpos2")
                            {
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        if(root[*it].asString()=="once")
                                        {
                                            u_int16_t stat=_p->mb_mapping->tab_registers[0x002];
                                            if(stat==0xff)
                                            {
                                                int16_t i_posy=_p->mb_mapping->tab_registers[0x003];
                                                int16_t i_posz=_p->mb_mapping->tab_registers[0x004];
                                                float posy=i_posy/100.0;
                                                float posz=i_posz/100.0;
                                                sent_root["getpos2"].append(posy);
                                                sent_root["getpos2"].append(posz);
                                            }
                                            else
                                            {
                                                sent_root["getpos2"]="failed";
                                            }
                                        }
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                            else if(*it=="getsize2")
                            {
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        if(root[*it].asString()=="once")
                                        {
                                            u_int16_t stat=_p->mb_mapping->tab_registers[0x002];
                                            if(stat==0xff)
                                            {
                                                int16_t i_sizew=_p->mb_mapping->tab_registers[0x005];
                                                int16_t i_sizeh=_p->mb_mapping->tab_registers[0x006];
                                                float sizew=i_sizew/100.0;
                                                float sizeh=i_sizeh/100.0;
                                                sent_root["getsize2"].append(sizew);
                                                sent_root["getsize2"].append(sizeh);
                                            }
                                            else
                                            {
                                                sent_root["getsize2"]="failed";
                                            }
                                        }
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                        }
                    }
                    if(sent_root.size()!=0)
                    {
                        Json::StreamWriterBuilder builder;
                        std::string json_file=Json::writeString(builder, sent_root);
                        if(!jsontcp.is_online() && jsontcp.get_last_closed_sockets() == _p->desc[i]->id) 
                        {
                            cerr << "Connessione chiusa: stop send_clients( id:" << _p->desc[i]->id << " ip:" << _p->desc[i]->ip << " )"<< endl;
                        }
                    #ifdef USE_PARENTHESES_INSTEAD_QUOTATION 
                        int time_s=0;
                        for(unsigned int n=0;n<json_file.size();n++)
                        {
                            if(json_file[n]==0x22)   //"
                            {
                                if(time_s==0)
                                {
                                    json_file[n]=0x28; //(
                                    time_s=1;
                                }
                                else if(time_s==1)
                                {
                                    json_file[n]=0x29; //)
                                    time_s=0;
                                }
                            }
                        }
                    #endif 
                    #ifdef DEL_SPACE_AND_LINEN
                        std::string json_file2;
                        for(unsigned int n=0;n<json_file.size();n++)
                        {
                            if(json_file[n]!='\n')
                            {
                                json_file2.push_back(json_file[n]);
                            }
                        }
                        json_file=json_file2;
                    #endif
                        jsontcp.Send(json_file, _p->desc[i]->id);
                    }


                    _p->num_client++;
                  // start message background thread
                  }
                  break;
                  default:
                  break;
                }
                jsontcp.clean(i);
            }
        }
        sleep(0);
    }
    return 0;
}

}  // namespace modbus

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(modbus::Modbus)
