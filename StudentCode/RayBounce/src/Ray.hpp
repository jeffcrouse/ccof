//
//  Ray.hpp
//  RayBounce
//
//  Created by Jeffrey Crouse on 10/30/17.
//

#pragma once
#include "ofMain.h"
#include "Obstacle.hpp"




class Ray {
public:
    void setup(ofPoint startPos, float angle);
    void update(vector<Obstacle>& obstacles);
    void draw();
    bool isDone();
    void bounce(Obstacle& o);
    
    ofPoint pos;
    float vel;
    float angle;
    ofColor c;
};
