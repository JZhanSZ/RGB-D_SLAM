#include <iostream>
#include "ros/ros.h"
#include <opencv2/opencv.hpp>
#include "listener_images.h"
#include <pcl/pcl_config.h>

int main (int argc, char **argv)
{
    std::cout << "RGB-D SLAM!" << std::endl;
    std::cout << "OpenCV version : " << CV_VERSION << std::endl;
    std::cout << "PCL version : " <<PCL_VERSION << std::endl;

    ros::init(argc, argv, "rgbd_slam");

    const std::string TOPIC_RGB="/camera/rgb/image_color";
    ListenerImages listener_rgb(TOPIC_RGB);



    while(ros::ok())
    {
         ros::spinOnce(); //call all the callbacks
         if (listener_rgb.isThereNewMsg() == true)
         {

             listener_rgb.messageConsumed();

            cv::imshow("rgb",listener_rgb.getCurremtImage());
            cv::waitKey(1);
         }
    }


  return 0;
}
