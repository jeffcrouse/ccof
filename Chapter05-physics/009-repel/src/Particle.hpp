//
//  Particle.hpp
//  repel
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once
#include "ofMain.h"


class Particle {
public:
    Particle();
    
    ofPoint loc;
    ofPoint vel;
    ofPoint acc;
    float r;
    float timer;
    float maxspeed;
    float mass;
    
    void update();
    void draw();
    
    void applyForce(ofPoint force);
    bool dead();
};
