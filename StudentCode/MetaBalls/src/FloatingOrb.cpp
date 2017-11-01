//
//  FloatingOrb.cpp
//  MetaBalls
//
//  Created by Jeffrey Crouse on 10/31/17.
//

#include "FloatingOrb.hpp"

#define MAX_VEL 2

// ---------------------------------------------------------------
void FloatingOrb::setup(ofImage& gradient) {
    bounds.set(200, 200, ofGetWidth()-400, ofGetHeight()-400);
    pos.x = ofRandom(bounds.getMinX(), bounds.getMaxX());
    pos.y = ofRandom(bounds.getMinY(), bounds.getMaxY());
    vel.x = ofRandom(-MAX_VEL, MAX_VEL);
    vel.y = ofRandom(-MAX_VEL, MAX_VEL);
    img = gradient;
}

// ---------------------------------------------------------------
void FloatingOrb::update() {
    pos += vel;
    bounce();
}

// ---------------------------------------------------------------
void FloatingOrb::bounce() {
    if(pos.x < bounds.getMinX()) {
        pos.x = bounds.getMinX();
        vel.x *= -1;
    }
    if(pos.y < bounds.getMinY()) {
        pos.y = bounds.getMinY();
        vel.y *= -1;
    }
    
    if(pos.x > bounds.getMaxX()) {
        pos.x = bounds.getMaxX();
        vel.x *= -1;
    }
    if(pos.y > bounds.getMaxY()) {
        pos.y = bounds.getMaxY();
        vel.y *= -1;
    }
}

// ---------------------------------------------------------------
void FloatingOrb::draw() {
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofScale(0.5, 0.5);
    img.draw(-img.getWidth()/2.0, -img.getHeight()/2.0);
    ofPopMatrix();
}
