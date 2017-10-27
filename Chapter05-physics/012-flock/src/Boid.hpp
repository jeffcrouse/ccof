//
//  Boid.hpp
//  flock
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once

#include "ofMain.h"

class Boid {
public:
    Boid();
    
    void update(vector<Boid*> boids);
    void draw();
    void seek(ofPoint target);
    void arrive(ofPoint target);
    ofPoint steer(ofPoint target, bool slowdown);
    
    void flock(vector<Boid*> boids);
    ofPoint separate(vector<Boid*> boids);
    ofPoint align(vector<Boid*> boids);
    ofPoint cohesion(vector<Boid*> boids);
    
    ofPoint loc;
    ofPoint vel;
    ofPoint acc;
    float r;
    float maxforce;
    float maxspeed;
};

