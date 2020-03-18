cmake_minimum_required(VERSION 2.8.3)
project(rgbd_slam)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
    cv_bridge
    geometry_msgs
    image_transport
    rosbag
    roscpp
    rospy
    sensor_msgs
    std_msgs
    )

# Find OpenCV
find_package( OpenCV REQUIRED )

# Find PCL
find_package (PCL REQUIRED)

catkin_package(
    #  INCLUDE_DIRS include
    CATKIN_DEPENDS cv_bridge geometry_msgs image_transport rosbag roscpp rospy sensor_msgs std_msgs
    )



include_directories(
    ${catkin_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${PCL_INCLUDE_DIRS}

    )
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# Set your files and resources here
file(GLOB Headers include/*.h include/*.hpp
                  include/rgbd_slam/*.h include/rgbd_slam/*.hpp)
file(GLOB Sources src/*.cpp)

#message(${Sources})
#message(${Headers})

## Declare a cpp executable
add_executable( rgbd_slam
    src/main.cpp
    ${Sources}
    ${Headers}
    )

target_link_libraries(rgbd_slam
    # ${VTK_LIBRARIES}
    #${Qt5Widgets_LIBRARIES}
    ${catkin_LIBRARIES}
    ${OpenCV_LIBS}
    ${PCL_LIBRARIES}
    )



if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

