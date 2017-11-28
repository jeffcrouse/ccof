//
//  Projectile.hpp
//  encoder
//
//  Created by Jeffrey Crouse on 11/28/17.
//

#pragma once
#include "ofMain.h"

class Projectile {
public:
    
    void setup(ofPoint start);
    void update(float deltaTime);
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    int w = 4;
    int h = 15;
};
