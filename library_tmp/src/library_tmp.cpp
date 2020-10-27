#include "library_tmp/library_tmp.h"
   
LibraryTmp::LibraryTmp(){
    ros::NodeHandle nh("~");
    twist_pub_ = nh.advertise<geometry_msgs::Twist>("/sample/cmd_vel", 10);
    twist_sub_ = nh.subscribe("/cmd_vel", 1, &LibraryTmp::msgsCallback, this);
    timer_ = nh.createTimer(ros::Duration(0.05), &LibraryTmp::timerCallback, this);
    
}

LibraryTmp::~LibraryTmp(){

}

void LibraryTmp::msgsCallback(const geometry_msgs::Twist::ConstPtr& msgs){
    twist_ = *msgs;
}

void LibraryTmp::timerCallback(const ros::TimerEvent&){
    ROS_INFO("x:%0.3f, y:%0.3f", twist_.linear.x, twist_.linear.y);
}

void LibraryTmp::publishCurrentTwist(){
    twist_pub_.publish(twist_);
    ros::Duration(0.01).sleep();
}


