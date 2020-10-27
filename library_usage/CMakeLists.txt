cmake_minimum_required(VERSION 3.0.2)
project(library_usage)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  library_template
  roscpp
  rospy
  rostime
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES library_usage
#  CATKIN_DEPENDS library_template roscpp rospy rostime
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(library_usage src/library_usage.cpp)
add_dependencies(library_usage ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(library_usage library_template ${catkin_LIBRARIES})
