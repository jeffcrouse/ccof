//
//  PixelParticle.cpp
//  images
//
//  Created by Jeffrey Crouse on 11/3/17.
//

#include "PixelParticle.hpp"

// ----------------------------------------------------------
void PixelParticle::setup(ofPoint _pos, ofColor _color, float _size){
    pos = _pos;
    color = _color;
    size = _size;
    vel.x = ofRandom(-200, 200);
    vel.y = ofRandom(-500, -200);
}


// ----------------------------------------------------------
void PixelParticle::update(float deltaTime){
    acc.y = 9.8; // acclerate 9.8 pixels per second
    vel += acc;
    pos += vel * deltaTime;
    acc.set(0, 0);
}


// ----------------------------------------------------------
void PixelParticle::draw(){
    ofSetColor(color);
    ofDrawRectangle(pos, size, size);
}

