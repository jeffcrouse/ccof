//
//  Sparkle.hpp
//  blobs
//
//  Created by Jeffrey Crouse on 11/10/17.
//

#pragma once
#include "ofMain.h"

class Sparkle {
public:
    void setup(ofPoint _pos);
    void update(float deltaTime);
    void draw();
    bool outOfBounds();
    
    ofRectangle bounds;
    float radius;
    ofColor color;
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    float friction = 0.99;
    ofPoint rNoise;
};
