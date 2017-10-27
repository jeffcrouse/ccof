//
//  Boid.hpp
//  path
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once

#include "ofMain.h"
#include "Path.hpp"

class Boid {
public:
    Boid(ofPoint l, float ms, float mf);
    
    void update();
    void draw();
    void seek(ofPoint target);
    void arrive(ofPoint target);
    ofPoint steer(ofPoint target, bool slowdown);
    
    void follow(Path* p);
    ofPoint getNormalPoint(ofPoint p, ofPoint a, ofPoint b);
    
    ofPoint loc;
    ofPoint vel;
    ofPoint acc;
    
    ofPoint predictLoc;
    ofPoint target;
    ofPoint dir;
    float record;
    
    float r;
    float maxforce;
    float maxspeed;
    bool debug;
};
