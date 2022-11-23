#pragma once

#include <ros/ros.h>
#include <string>
#include <map>

#include "geometry_msgs/Point.h"
#include "block_detector/ObjectPt_srv.h"

class Camera_State{

public:

    Camera_State(){}

    void Init(ros::NodeHandle nh);

    void CatchBlocks();

    std::map<char, geometry_msgs::Point> GetBlockPositions();

private:


    // Only client since it just needs to catch once
    // And no need to trace anything
    ros::ServiceClient camera_client;

    // Block position record
    // Not catch : (-1, -1)
    std::map<char, geometry_msgs::Point> BlockPositions;

};