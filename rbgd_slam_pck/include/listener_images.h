#ifndef LISTENER_IMAGES_H
#define LISTENER_IMAGES_H

#include "listener_base.h"
#include <opencv2/opencv.hpp>
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

class ListenerImages: public ListenerBase
{
public:
    ListenerImages();
    ListenerImages(std::string const&tp_name);
    void messageConsumed(); // new_msg become fales

    //setter
    void setType(std::string const&type);
    void setROSTopicName(std::string const&tp_name);


    //getter
    cv::Mat& getCurremtImage();
    std::string &getType();
    std::string &getROSTopicName();
    bool isThereNewMsg ();//to be put into ListenerBase


protected:


    void cameraStampedCallback(const sensor_msgs::ImageConstPtr &msg);
    void startSub();

    //variables
    int sub_counter_ = 0;
    bool set_topic_ = 0;
    bool new_msg_ = false;
    std::string type_; // image source type, stereo or ultrasound// should be a enum instead
    std::string topic_name_; // topic for subscription of where the images are published to
    image_transport::Subscriber sub_image_;
    ros::Time mTimeStamp_;
    cv::Mat curr_image_;


};

#endif // LISTENER_IMAGES_H
