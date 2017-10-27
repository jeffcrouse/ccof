//
//  Thing.hpp
//  attractor
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once

#include "ofMain.h"

class Thing{
public:
    Thing();
    
    void draw();
    void update();
    void applyForce(ofPoint force);
    static void drawVector(ofPoint loc, ofPoint v, float scayl);
    
    ofPoint loc;
    ofPoint vel;
    ofPoint acc;
    
    float mass;
    float max_vel;
    float bounce;  // How "elastic" is the object
    
};
