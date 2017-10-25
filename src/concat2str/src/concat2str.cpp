#include "ros/ros.h"
#include "concat2str/concat2str.h"


bool serverCallback(concat2str::concat2str::Request &req,
                    concat2str::concat2str::Response &res)
{
  res.result = req.s1 + req.s2;
  return true;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "concat2str");
  ros::NodeHandle n;
  std::string name = ros::this_node::getName() + "/my_service";
  ros::ServiceServer server = n.advertiseService(name, serverCallback);
  ros::spin();

  return 0;
}
