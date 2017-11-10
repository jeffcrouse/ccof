//
//  Spinner.cpp
//  flow
//
//  Created by Jeffrey Crouse on 11/10/17.
//

#include "Spinner.hpp"

// -------------------------------------------------------
void Spinner::setup() {
    size.x = ofRandom(10, 50);
    size.y = ofRandom(20, 100);
    pos.x = ofRandom(640);
    pos.y = ofRandom(480);
    color.setHsb(ofRandom(10, 200), 100, 200);
}

// -------------------------------------------------------
void Spinner::update() {
    rot += rotVel;
    rot *= 0.9;
}

// -------------------------------------------------------
void Spinner::draw() {
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateY(rot.x);
    //ofRotateX(rot.y);
    ofTranslate(-size.x/2.0, -size.y/2.0);
    
    ofSetColor(color, 100);
    ofDrawRectangle(0, 0, size.x, size.y);
    ofPopMatrix();
}
