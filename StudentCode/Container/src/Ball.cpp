//
//  Ball.cpp
//  Container
//
//  Created by Jeffrey Crouse on 10/28/17.
//

#include "Ball.hpp"

// ----------------------------------------------------
void Ball::setup() {
    radius = ofRandom(10, 20);
    color.setHsb(ofRandom(255), 255, 255);
    pos.x = ofRandom(300, ofGetWidth()-300);
    pos.y = -radius * 2.0;
}

// ----------------------------------------------------
void Ball::update() {
    acc.y = 9.8 / 5.0;
    
    vel += acc;
    pos += vel;
    acc.set(0);
}

// ----------------------------------------------------
void Ball::draw() {
    ofSetColor(color);
    ofDrawCircle(pos, radius);
}
