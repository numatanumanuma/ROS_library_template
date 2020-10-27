cmake_minimum_required(VERSION 3.0.2)
project(library_tmp)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  rostime
)


catkin_package(
   INCLUDE_DIRS include
   LIBRARIES library_tmp
   CATKIN_DEPENDS geometry_msgs roscpp rospy rostime
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(library_tmp src/library_tmp.cpp)
target_link_libraries(library_tmp ${catkin_LIBRARIES})

add_executable(library_tmp_node main/library_tmp_node.cpp)
add_dependencies(library_tmp_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(library_tmp_node library_tmp ${catkin_LIBRARIES})
