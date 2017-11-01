//
//  Obstacle.hpp
//  RayBounce
//
//  Created by Jeffrey Crouse on 10/30/17.
//

#pragma once
#include "ofMain.h"

class Obstacle {
public:
    void setup(ofPoint a, float angle, float length);
    void draw();
    
    ofPoint start;
    ofPoint end;
    float length;
    float angle;
};

