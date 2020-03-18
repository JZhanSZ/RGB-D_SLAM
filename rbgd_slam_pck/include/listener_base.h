#ifndef LISTENER_BASE_H
#define LISTENER_BASE_H

#include <ros/ros.h>
#include <ros/time.h>
#include <chrono>

class ListenerBase
{
public:
    ListenerBase();



protected:
    // ROS Subscriber
    ros::Subscriber sub_;

};

#endif // LISTENER_BASE_H
