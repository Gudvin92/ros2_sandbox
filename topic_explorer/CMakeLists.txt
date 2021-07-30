cmake_minimum_required(VERSION 3.5)
project(topic_explorer)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(autoware_vehicle_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

# find_package(turtlesim REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
include_directories(
 include
  include/${PROJECT_NAME}
#   ${catkin_INCLUDE_DIRS}
)


add_executable(topic_explorer_node 
src/topic_explorer.cpp
nodes/topic_explorer_node.cpp
)

ament_target_dependencies(topic_explorer_node 
rclcpp 
geometry_msgs
autoware_vehicle_msgs
tf2_ros )
target_include_directories(topic_explorer_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

install(TARGETS topic_explorer_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})
ament_package()
