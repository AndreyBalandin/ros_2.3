cmake_minimum_required(VERSION 2.8.3)
project(client)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  concat2str
)
catkin_package(
  CATKIN_DEPENDS roscpp concat2str
)
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
add_executable(client client.cpp)
add_dependencies(client concat2str_generate_messages_cpp)
target_link_libraries(client
  ${catkin_LIBRARIES}
)
