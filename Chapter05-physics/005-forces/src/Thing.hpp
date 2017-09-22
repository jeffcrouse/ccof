//
//  Thing.hpp
//  forces
//
//  Created by Jeffrey Crouse on 9/22/17.
//

#pragma once
#include "ofMain.h"

class Thing{
public:
    Thing();
    
    void reset();
    void draw();
    void update();
    void applyForce(ofPoint force);
    void drawVector(ofPoint loc, ofPoint vel, float scayl);
    
    ofPoint loc;
    ofPoint vel;
    ofPoint acc;
    
    float mass;
    float radius;
    float max_vel;
    float bounce;  // How "elastic" is the object
    
};

