#include"topic_explorer.h"

    Texplorer::Texplorer(): Node("topic_explorer_node"), count_(0)
    {
        Init();
      //publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&Texplorer::timer_callback, this));
    }

    void Texplorer::Init(){
          std::map<std::string, std::vector<std::string>> topiclist;

          topiclist = get_topic_names_and_types();
          int topicnum = topiclist.size();
          print_map(topiclist);
        // universal_sub_ = ;
    }

    void Texplorer::timer_callback(){}

    void Texplorer::print_map(const std::map<std::string, std::vector<std::string>>& m){
        for (const auto& [key, value] : m) {
        std::cout << key << " = " << value.at(0) << "; " << std::endl;
    }

}
 