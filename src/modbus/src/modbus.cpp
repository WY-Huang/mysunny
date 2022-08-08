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
  _param_camera = std::make_shared<rclcpp::AsyncParametersClient>(this, "camera_tis_node");
  _param_gpio = std::make_shared<rclcpp::AsyncParametersClient>(this, "gpio_raspberry_node");
  _param_linecenter = std::make_shared<rclcpp::AsyncParametersClient>(this, "laser_line_center_node");
  _param_laserimagepos = std::make_shared<rclcpp::AsyncParametersClient>(this, "laser_imagepos_node");


  this->declare_parameter("parameterpotr", 1500);
  auto parameterpotr = this->get_parameter("parameterpotr").as_int();
  this->declare_parameter("port", 1502);
  auto port = this->get_parameter("port").as_int(); 
  this->declare_parameter("jsonport", 11503);
  auto jsonport = this->get_parameter("jsonport").as_int();
  
  parameterpotr_mapping=modbus_mapping_new(0, 0, PARAMETER_REGEDIST_NUM, 0);
  if (!parameterpotr_mapping) {
    RCLCPP_ERROR(this->get_logger(), "Failed to initialize modbus registers.");
    rclcpp::shutdown();
    return;
  }

  parameterpotr_mapping->tab_registers[als1_threshold_reg_add]=e2proomdata.als1_threshold;
  

  static int oldtasknum[PARAMETER_REGEDIST_NUM]={INT_MAX};
  for(int i=0;i<PARAMETER_REGEDIST_NUM;i++)
  {
    if(oldtasknum[i]!=parameterpotr_mapping->tab_registers[i])
    {
      oldtasknum[i]=parameterpotr_mapping->tab_registers[i];
      _task_parameter(i,oldtasknum[i]);
    }
  }


  ctx_parameterpotr = modbus_new_tcp(NULL, parameterpotr);
  if (!ctx_parameterpotr) {
    RCLCPP_ERROR(this->get_logger(), "Failed to create modbus context.");
    rclcpp::shutdown();
    return;
  }
  _thread_parameterpotr = std::thread(&Modbus::_modbusparameterpotr, this, parameterpotr);


  // _mb_mapping = modbus_mapping_new(MODBUS_MAX_READ_BITS, 0, MODBUS_MAX_READ_REGISTERS, 0);
  mb_mapping = modbus_mapping_new(0, 0, 400, 0);
  if (!mb_mapping) {
    RCLCPP_ERROR(this->get_logger(), "Failed to initialize modbus registers.");
    rclcpp::shutdown();
    return;
  }
  mb_mapping->tab_registers[1] = 0xff;

  ctx = modbus_new_tcp(NULL, port);
  if (!ctx) {
    RCLCPP_ERROR(this->get_logger(), "Failed to create modbus context.");
    rclcpp::shutdown();
    return;
  }
  _thread = std::thread(&Modbus::_modbus, this, port);

  num_client=0;
  _jsontcpthread = std::thread(&Modbus::_json, this, jsonport);

/*
  static int s_port=0,s_jsport=0;
  _handle = this->add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & parameters) {
      SetParametersResult result;
      result.successful = true;
      for (const auto & p : parameters) {
        if (p.get_name() == "port") {
          if(s_port==0)
          {
            s_port=1;
            auto port = p.as_int();
            ctx = modbus_new_tcp(NULL, port);
            if (!ctx) {
              RCLCPP_ERROR(this->get_logger(), "Failed to create modbus context.");
              rclcpp::shutdown();
              return result;
            }
            _thread = std::thread(&Modbus::_modbus, this, port);
          }
        } 
        else if (p.get_name() == "jsonport") 
        {
          if(s_jsport==0)
          {
            s_jsport=1;
            auto jsonport = p.as_int();
            num_client=0;
            _jsontcpthread = std::thread(&Modbus::_json, this, jsonport);
          }
        }
      }
      return result;
    }
  );
*/
  RCLCPP_INFO(this->get_logger(), "Initialized successfully");
}

Modbus::~Modbus()
{
  try {
    _thread_parameterpotr.join();
    _thread.join();
    _jsontcpthread.join();
    _param_gpio.reset();
    _param_camera.reset();
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

/**
 * @brief Control camera capture or not.
 *
 * @param f true if enable camera capture.
 */
void Modbus::_camera_power(bool f)
{
  if (f) {
    _param_camera->set_parameters({rclcpp::Parameter("power", true)});
  } else {
    _param_camera->set_parameters({rclcpp::Parameter("power", false)});
  }
}

void Modbus::_task_numberset(u_int16_t num)
{
  _param_linecenter->set_parameters({rclcpp::Parameter("task_num", num)}); 
  _param_laserimagepos->set_parameters({rclcpp::Parameter("task_num", num)}); 
}


void Modbus::_task_parameter(int ddr,u_int16_t num)
{
  switch(ddr)
  {
    case als1_threshold_reg_add:
      e2proomdata.als1_threshold=num;
      _param_laserimagepos->set_parameters({rclcpp::Parameter("als1_threshold", (int16_t)num)}); 
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
  if (sock == -1) {
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
  while (rclcpp::ok() && ret != -1) {
    auto rdset = refset;
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    ret = select(fdmax + 1, &rdset, NULL, NULL, &tv);
    if (ret == -1) {
      RCLCPP_ERROR(this->get_logger(), "Failed to select.");
      continue;
    } else if (ret == 0) {
      // time out.
      continue;
    }

    auto fds_bak = fds;
    for (auto fd : fds_bak) {
      if (!FD_ISSET(fd, &rdset)) {continue;}

      if (fd == sock) {
        // A client is asking a new connection
        // struct sockaddr_in clientaddr;
        // socklen_t addrlen = sizeof(clientaddr);
        // memset(&clientaddr, 0, sizeof(clientaddr));
        // ret = accept(sock, (struct sockaddr *)&clientaddr, &addrlen);
        ret = modbus_tcp_accept(ctx, &sock);
        if (ret != -1) {
          FD_SET(ret, &refset);
          fds.insert(fds.end(), ret);
          fdmax = *fds.rbegin();
        } else {
          RCLCPP_ERROR(this->get_logger(), "Failed to accept.");
          break;
        }
      } else {
        // A client is asking for reply
        ret = modbus_set_socket(ctx, fd);
        if (ret == -1) {
          RCLCPP_ERROR(this->get_logger(), "Failed to set socket.");
          break;
        }
        ret = modbus_receive(ctx, query);
        if (ret == -1) {
          // Connection closed by the client or error
          close(fd);
          FD_CLR(fd, &refset);
          fds.erase(fd);
          fdmax = *fds.rbegin();
          ret = 0;
        } else if (ret > 0) {
          // Client request
          // if (ret == 19 && query[7] == 0x10) {
          //   auto ptr = reinterpret_cast<uint8_t *> (mb_mapping->tab_registers);
          //   ptr[5] = query[13];
          //   ptr[4] = query[14];
          //   ptr[7] = query[15];
          //   ptr[6] = query[16];
          //   ptr[9] = query[17];
          //   ptr[8] = query[18];
          //   // if (++ccc % 30 == 0) {
          //   //   RCLCPP_INFO(this->get_logger(), "%d %d %d",
          //   //     int(mb_mapping->tab_registers[2]),
          //   //     int(mb_mapping->tab_registers[3]),
          //   //     int(mb_mapping->tab_registers[4]));
          //   // }
          //   continue;
          // }
          if (ret > 14 && query[7] == 0x10 && query[8] == 0x01 && query[9] == 0x01) {
            if (query[14]) {
              _gpio_laser(true);
              _camera_power(true);
            } else {
              _camera_power(false);
              _gpio_laser(false);
            }
          }
          // if (ret == 19) {
          //   auto ttt = std::chrono::system_clock::now();
          //   std::chrono::duration<double> diff = ttt - nnn;
          //   vvv[aaa++ % 1800] = diff.count();
          //   nnn = ttt;
          // }
          ret = modbus_reply(ctx, query, ret, mb_mapping);

          static int oldtasknum=INT_MAX;
          if(oldtasknum!=mb_mapping->tab_registers[0x102])
          {
            oldtasknum=mb_mapping->tab_registers[0x102];
            _task_numberset(oldtasknum);
          }

          if (ret == -1) {
            RCLCPP_ERROR(this->get_logger(), "Failed to reply.");
            break;
          }
        }
      }
    }
  }

  close(sock);
  modbus_mapping_free(mb_mapping);
  modbus_free(ctx);
  if (ret == -1) {
    rclcpp::shutdown();
  }
  // std::ofstream ofile("/diff.txt");
  // for(auto d : vvv) {
  //   ofile << d << "\n";
  // }
  // ofile.close();
}

void Modbus::_modbusparameterpotr(int port)
{
  // int aaa = 0;
  // auto nnn = std::chrono::system_clock::now();
  // std::vector<double> vvv;
  // vvv.resize(1800);
  auto sock = modbus_tcp_listen(ctx_parameterpotr, 10);
  if (sock == -1) {
    modbus_mapping_free(parameterpotr_mapping);
    modbus_free(ctx_parameterpotr);
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
  while (rclcpp::ok() && ret != -1) {
    auto rdset = refset;
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    ret = select(fdmax + 1, &rdset, NULL, NULL, &tv);
    if (ret == -1) {
      RCLCPP_ERROR(this->get_logger(), "Failed to select.");
      continue;
    } else if (ret == 0) {
      // time out.
      continue;
    }

    auto fds_bak = fds;
    for (auto fd : fds_bak) {
      if (!FD_ISSET(fd, &rdset)) {continue;}

      if (fd == sock) {
        // A client is asking a new connection
        // struct sockaddr_in clientaddr;
        // socklen_t addrlen = sizeof(clientaddr);
        // memset(&clientaddr, 0, sizeof(clientaddr));
        // ret = accept(sock, (struct sockaddr *)&clientaddr, &addrlen);
        ret = modbus_tcp_accept(ctx_parameterpotr, &sock);
        if (ret != -1) {
          FD_SET(ret, &refset);
          fds.insert(fds.end(), ret);
          fdmax = *fds.rbegin();
        } else {
          RCLCPP_ERROR(this->get_logger(), "Failed to accept.");
          break;
        }
      } else {
        // A client is asking for reply
        ret = modbus_set_socket(ctx_parameterpotr, fd);
        if (ret == -1) {
          RCLCPP_ERROR(this->get_logger(), "Failed to set socket.");
          break;
        }
        ret = modbus_receive(ctx_parameterpotr, query);
        if (ret == -1) {
          // Connection closed by the client or error
          close(fd);
          FD_CLR(fd, &refset);
          fds.erase(fd);
          fdmax = *fds.rbegin();
          ret = 0;
        } else if (ret > 0) {
          ret = modbus_reply(ctx_parameterpotr, query, ret, parameterpotr_mapping);

          static int oldtasknum[PARAMETER_REGEDIST_NUM]={INT_MAX};
          u_int8_t u8_temp=0;
          for(int i=0;i<PARAMETER_REGEDIST_NUM;i++)
          {
            if(oldtasknum[i]!=parameterpotr_mapping->tab_registers[i])
            {
              oldtasknum[i]=parameterpotr_mapping->tab_registers[i];
              u8_temp=1;
              _task_parameter(i,oldtasknum[i]);
            }
          }
          if(u8_temp==1)
          {
            e2proomdata.write();
          }

          if (ret == -1) {
            RCLCPP_ERROR(this->get_logger(), "Failed to reply.");
            break;
          }
        }
      }
    }
  }

  close(sock);
  modbus_mapping_free(parameterpotr_mapping);
  modbus_free(ctx_parameterpotr);
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

/*
void * send_client(void * m) 
{
    struct descript_socket *desc = (struct descript_socket*) m;
	  while(rclcpp::ok()) 
    {
        if(!jsontcp.is_online() && jsontcp.get_last_closed_sockets() == desc->id) 
        {
            cerr << "Connessione chiusa: stop send_clients( id:" << desc->id << " ip:" << desc->ip << " )"<< endl;
            break;
		    }
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        int hour = now->tm_hour;
        int min  = now->tm_min;
        int sec  = now->tm_sec;

        std::string date = 
              to_string(now->tm_year + 1900) + "-" +
              to_string(now->tm_mon + 1)     + "-" +
              to_string(now->tm_mday)        + " " +
              to_string(hour)                + ":" +
              to_string(min)                 + ":" +
              to_string(sec)                 + "\r\n";
        cerr << date << endl;
        jsontcp.Send(date, desc->id);
        sleep(1);
	  }
    pthread_exit(NULL);
    return 0;
}
*/

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

          //    if(!_p->desc[i]->enable_message_runtime) 
          //    {
          //        _p->desc[i]->enable_message_runtime = true;
                    /*
                    if( pthread_create(&_p->client[_p->num_client], NULL, send_client, (void *) _p->desc[i]) == 0) 
                    {
                        cerr << "ATTIVA THREAD INVIO MESSAGGI" << endl;
                    }
                    */

                    Json::Value root;
                    jsonfuction js;
                    Json::Value sent_root;

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
            //  }
                
                jsontcp.clean(i);
            }
        }
        sleep(0);
    }
    return 0;
}

}  // namespace modbus
/*
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<modbus::Modbus>());
  rclcpp::shutdown();
  
  return 0;
}
*/

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(modbus::Modbus)
