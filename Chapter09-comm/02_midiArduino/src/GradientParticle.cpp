//
//  GradientParticle.cpp
//  Control02
//
//  Created by Jeffrey Crouse on 11/5/17.
//

#include "GradientParticle.hpp"


ofImage GradientParticle::img;

// ----------------------------------------------------------------
void GradientParticle::setup(float s) {

    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    
    scale = ofMap(s, 0, 128, 1, 4);
    vel.set(ofRandom(-10, 10), ofRandom(-10, 10));
}

// ----------------------------------------------------------------
void GradientParticle::update() {
    if(!img.isAllocated()) {
        img.load("gradient.png");
    }
    scale *= 0.95;
    pos += vel;
}

// ----------------------------------------------------------------
void GradientParticle::draw() {
    
    ofPushMatrix();
    ofTranslate(pos);
    ofScale(scale, scale);
    ofTranslate(-img.getWidth()/2.0, -img.getWidth()/2.0);
    GradientParticle::img.draw(0, 0);
    ofPopMatrix();
}
