//
//  Blob.hpp
//  blobs
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once
#include "ofMain.h"


class Blob {
public:
    void setup(float x, float y);
    void update();
    void draw();
    
    ofPoint noiseX;
    ofPoint noiseY;
    vector<ofPoint> baseShape;
    vector<ofPoint> contour;
    ofPoint pos;
    ofColor color;
};
