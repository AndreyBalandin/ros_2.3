cmake_minimum_required(VERSION 2.8.3)
project(concat2str)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  message_runtime
  std_msgs
  roscpp
)

add_service_files(
  FILES
  concat2str.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_generation message_runtime std_msgs roscpp
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(concat2str src/concat2str.cpp)
target_link_libraries(concat2str ${catkin_LIBRARIES})
add_dependencies(concat2str concat2str_generate_messages_cpp)
