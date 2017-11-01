//
//  Ball.hpp
//  Container
//
//  Created by Jeffrey Crouse on 10/28/17.
//

#pragma once
#include "ofMain.h"

class Ball {
public:
    void setup();
    void update();
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    ofColor color;
    float radius;
};
