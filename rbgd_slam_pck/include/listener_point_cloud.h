#ifndef LISTENERPOINTCLOUD_H
#define LISTENERPOINTCLOUD_H

#include "listener_base.h"
#include <ros/ros.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <sensor_msgs/PointCloud2.h>

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

class ListenerPointCloud
{
public:
    ListenerPointCloud();
};

#endif // LISTENERPOINTCLOUD_H
