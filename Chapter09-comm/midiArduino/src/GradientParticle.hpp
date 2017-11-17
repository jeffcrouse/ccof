//
//  GradientParticle.hpp
//  Control02
//
//  Created by Jeffrey Crouse on 11/5/17.
//

#pragma once
#include "ofMain.h"

class GradientParticle {
public:
    
    void setup(float vel);
    void update();
    void draw();
    float scale;
    
protected:
    static ofImage img;
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
};

