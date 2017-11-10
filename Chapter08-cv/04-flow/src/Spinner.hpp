//
//  Spinner.hpp
//  flow
//
//  Created by Jeffrey Crouse on 11/10/17.
//

#pragma once
#include "ofMain.h"

class Spinner {
public:
    void setup();
    void update();
    void draw();
    
    ofColor color;
    ofPoint size;
    ofPoint pos;
    ofPoint rotVel;
    ofPoint rot;
    
};
