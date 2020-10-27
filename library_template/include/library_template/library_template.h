#ifndef library_template_H
#define library_template_H

#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
   
class LibraryTmp{
public:
    LibraryTmp();
    ~LibraryTmp();
    void msgsCallback(const geometry_msgs::Twist::ConstPtr& msgs);
    void timerCallback(const ros::TimerEvent&);
   
private:
    ros::Publisher twist_pub_;
    ros::Subscriber twist_sub_;
    ros::Timer timer_;

    geometry_msgs::Twist twist_;

    void publishCurrentTwist();

};

#endif