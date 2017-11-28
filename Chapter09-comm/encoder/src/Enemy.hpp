//
//  Enemy.hpp
//  encoder
//
//  Created by Jeffrey Crouse on 11/28/17.
//

#pragma once
#include "ofMain.h"

class Enemy {
public:
    void setup(float x, float y, float n);
    void update();
    void draw();
    
    ofRectangle bounds;
    ofPoint pos;
    float w;
    float h;
    float noiseIndex;
};
