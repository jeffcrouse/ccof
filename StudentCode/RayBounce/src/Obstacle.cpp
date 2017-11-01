//
//  Obstacle.cpp
//  RayBounce
//
//  Created by Jeffrey Crouse on 10/30/17.
//

#include "Obstacle.hpp"

// ------------------------------------------------------------------------
void Obstacle::setup(ofPoint a, float angle, float length) {
    start = a;
    end.x = a.x + cos(ofDegToRad(angle)) * length;
    end.y = a.y + sin(ofDegToRad(angle)) * length;
}

// ------------------------------------------------------------------------
void Obstacle::draw() {
    ofSetColor(0);
    ofDrawLine(start, end);
}
