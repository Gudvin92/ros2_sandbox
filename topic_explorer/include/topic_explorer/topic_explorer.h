#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class Texplorer : public rclcpp::Node
{
  public:
    Texplorer();


  private:

    void print_map(const std::map<std::string, std::vector<std::string>>& m);
    rclcpp::SubscriptionBase::SharedPtr universal_sub_;
    void Init();
    void timer_callback();
    rclcpp::TimerBase::SharedPtr timer_;
    //rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
};

