#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "autoware_vehicle_msgs/msg/vehicle_command.hpp"

using namespace std::chrono_literals;


class Texplorer : public rclcpp::Node
{
  public:
    Texplorer();

  private:

    void print_map(const std::map<std::string, std::vector<std::string>>& m);
    void print_map(const std::map<std::vector<std::string>, std::string>& m);
    rclcpp::SubscriptionBase::SharedPtr universal_sub_;
    void Init();
    void timer_callback();
    void callbackFromCmd(const autoware_vehicle_msgs::msg::VehicleCommand::SharedPtr _msg);
    rclcpp::TimerBase::SharedPtr timer_;
    //rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    std::map<std::string, std::vector<std::string>> topiclist_;
    size_t count_;
};

