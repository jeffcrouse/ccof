//
//  Fly.hpp
//  FlyStarter
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once
#include "ofMain.h"

class Fly {
public:

    void setup(ofImage& flyImage);
    void update(ofPoint attractor, vector<Fly>& flies);
    void pacman();
    void draw();
    void boost();
    
    ofImage img;
    ofPoint pos;
    ofPoint lastPos;
    ofPoint vel;
    
    float angle;
    float friction = 0.9;
};
