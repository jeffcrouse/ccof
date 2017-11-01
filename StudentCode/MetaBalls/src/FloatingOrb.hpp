//
//  FloatingOrb.hpp
//  MetaBalls
//
//  Created by Jeffrey Crouse on 10/31/17.
//

#pragma once
#include "ofMain.h"

class FloatingOrb {
public:
    void setup(ofImage& gradient);
    void update();
    void bounce();
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    ofImage img;
    ofRectangle bounds;
};
