#include "listener_images.h"

ListenerImages::ListenerImages()
{
    std::cout << "listener images is created" <<std::endl;
}


ListenerImages::ListenerImages(std::string const&tp_name)
{
    setROSTopicName(tp_name);
    startSub();
}


void ListenerImages::startSub()
{
    if (set_topic_ == 1)
    {
        ros::NodeHandle nh;
        //    sub_ = nh.subscribe(topic_name_, 0,&ListenerImages::cameraStampedCallback, this);
        image_transport::ImageTransport it(nh);
        sub_image_ = it.subscribe(topic_name_, 1, &ListenerImages::cameraStampedCallback, this);

    }
    else
    {
        throw "The topic is not set! Please set the ROS topic first";
    }
}

void ListenerImages::cameraStampedCallback(const sensor_msgs::ImageConstPtr &msg)
{
    curr_image_ = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8)->image;
    //    cv::medianBlur(curr_image_, curr_image_,11);
    mTimeStamp_ = msg->header.stamp;
    sub_counter_ ++;
    new_msg_ = true;

//     std::chrono::milliseconds ms1= std::chrono::duration_cast< std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
//          std::cout<< "get image at:" <<std::chrono::duration_cast<std::chrono::milliseconds>(ms1).count()<< std::endl
//                   <<"from" << topic_name_ << std::endl;

    //    vector<int> compression_params;
    //    compresion_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    //    compression_params.push_back(9);

    //std::string file_name = "out_img/"+type_+"/img_"+std::to_string(sub_counter_)+".png";
    //std::cout << "file name:" << file_name<< std::endl;
    //cv::imwrite(file_name,curr_image_);

}

void ListenerImages::messageConsumed()
{
    new_msg_ = false;
}

void ListenerImages::setType(std::string const&type)
{
    type_ = type;
}

void ListenerImages::setROSTopicName(std::string const&tp_name)
{
    topic_name_ = tp_name;
    set_topic_ = 1;
}


std::string& ListenerImages::getType()
{
    return type_;
}

std::string& ListenerImages::getROSTopicName()
{
    return topic_name_;
}


cv::Mat& ListenerImages::getCurremtImage()
{
    return curr_image_;
}

bool ListenerImages::isThereNewMsg ()
{
    return new_msg_;
}




