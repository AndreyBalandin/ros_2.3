#include "ros/ros.h"
#include "concat2str/concat2str.h"
#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

int test(ros::ServiceClient& clnt, string s1, string s2) {
	concat2str::concat2str test;
	test.request.s1 = s1;
	test.request.s2 = s2;
	if (clnt.call(test)) {
		if (test.response.result != s1+s2) {
			cout << "Error: request s1=" << test.request.s1.c_str() 
                             << " s2=" << test.request.s2.c_str() << endl
			     << "	response out=" << test.response.result.c_str() << endl;
			return 1;
		}
	}
	else {
		cout << "Error: could not call service.";
		return 1;
	}
	return 0;
}

int main(int argc, char** argv) {
	ros::init(argc, argv, "client");
	ros::NodeHandle n;
	sleep(5);
	system("rosservice list | grep /meow > services.txt");
	ifstream services("services.txt");
	string service_line("");

	do {
		getline(services, service_line);
		cout << service_line.c_str() << endl;
	} while ((service_line == string("/meow/get_loggers") ||
	         service_line == string("/meow/set_logger_level")) && !services.eof());

	ros::ServiceClient clnt = n.serviceClient<concat2str::concat2str>(service_line.c_str());
	
	if (test(clnt, "","")) {return 1;}
	if (test(clnt, "","2")) {return 1;}
	if (test(clnt, "2","")) {return 1;}
	if (test(clnt, "111","222")) {return 1;}
	if (test(clnt, "qqq", " ")) {return 1;}
	ros::spinOnce();
	cout << "success tests" << endl;
}
