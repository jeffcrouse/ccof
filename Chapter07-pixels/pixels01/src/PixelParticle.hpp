//
//  PixelParticle.hpp
//  images
//
//  Created by Jeffrey Crouse on 11/3/17.
//

#pragma once
#include "ofMain.h"

class PixelParticle {
public:
    
    void setup(ofPoint _pos, ofColor _color, float _size);
    void update(float deltaTime);
    void draw();
    bool isDone();
    
    float size;
    ofColor color;
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
};
