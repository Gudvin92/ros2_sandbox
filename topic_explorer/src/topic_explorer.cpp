#include"topic_explorer.h"

    Texplorer::Texplorer(): Node("topic_explorer_node"), count_(0)
    {
        Init();
      //publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&Texplorer::timer_callback, this));
    }

    void Texplorer::Init(){

          topiclist_ = get_topic_names_and_types();

            std::map<std::vector<std::string>, std::string> inverse_map;
            for (std::map<std::string, std::vector<std::string>>::iterator it = topiclist_.begin(); it != topiclist_.end(); ++it) {
                inverse_map[it->second]=it->first;
            }
          int topicnum = topiclist_.size();
          print_map(topiclist_);
          print_map(inverse_map);
        // universal_sub_ = ;
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
 