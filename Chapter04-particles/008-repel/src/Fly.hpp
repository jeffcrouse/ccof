//
//  Fly.hpp
//  repel
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once

#include "ofMain.h"

class Fly {
public:

    void setup(ofImage& _img);
    void update(ofPoint mouse, vector<Fly>& flies);
    void draw();
    
    ofImage img;
    float angle;
    ofPoint lastPos;
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    ofSoundPlayer sfx;
};
