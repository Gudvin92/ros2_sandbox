#include"topic_explorer.h"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Texplorer>());
  rclcpp::shutdown();
  return 0;
}