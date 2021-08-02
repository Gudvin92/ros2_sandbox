#include"topic_explorer.h"
#include <iostream>
#include <fstream>

    Texplorer::Texplorer(): Node("topic_explorer_node"), count_(0)
    {
        Init();
      //publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&Texplorer::timer_callback, this));
    }

    void Texplorer::Init(){
            universal_sub_ = create_subscription<autoware_vehicle_msgs::msg::VehicleCommand>(
            "/control/vehicle_cmd", 10, std::bind(&Texplorer::callbackFromCmd, this, std::placeholders::_1));; 

          topiclist_ = get_topic_names_and_types();

            std::map<std::vector<std::string>, std::string> inverse_map;
            for (std::map<std::string, std::vector<std::string>>::iterator it = topiclist_.begin(); it != topiclist_.end(); ++it) {
                inverse_map[it->second]=it->first;
            }
          int topicnum = topiclist_.size();
          print_map(topiclist_);
          print_map(inverse_map);

    }

    void Texplorer::timer_callback(){

        std::string test = "abc";
    }

    void Texplorer::print_map(const std::map<std::string, std::vector<std::string>>& m){
        for (const auto& [key, value] : m) {
        std::cout << key << " = " << value.at(0) << "; " << std::endl;
        }
    }

    void Texplorer::print_map(const std::map<std::vector<std::string>, std::string>& m){
        for (const auto& [key, value] : m) {
        std::cout << key.at(0) << " = " << value << "; " << std::endl;
        }
    }

     void Texplorer::callbackFromCmd(const autoware_vehicle_msgs::msg::VehicleCommand::SharedPtr _msg) 
    {
        //std::cout << "callback" << std::endl;
        std::ofstream outf("ExtractText.txt", std::ios::app);

        outf << "acc = " << _msg->control.acceleration
            << " vel = " << _msg->control.velocity 
            << " steer = " << _msg->control.steering_angle << std::endl;
        //
    }
