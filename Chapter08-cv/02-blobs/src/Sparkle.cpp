//
//  Sparkle.cpp
//  blobs
//
//  Created by Jeffrey Crouse on 11/10/17.
//

#include "Sparkle.hpp"

// ---------------------------------------------------------
void Sparkle::setup(ofPoint _pos) {
    pos = _pos;
    pos.x += ofRandom(-10, 10);
    pos.y += ofRandom(-10, 10);
    vel.x = ofRandom(-100, 100);
    vel.y = ofRandom(-100, 100);
    color.setHsb(ofRandom(255), 255, 255);
    rNoise.x = ofRandomf();
    rNoise.y = ofRandomf();
    acc.y = 9.8;
}

// ---------------------------------------------------------
void Sparkle::update(float deltaTime) {
    vel += acc;
    pos += vel * deltaTime;
    vel *= friction;

    color.setHue( color.getHue() + (deltaTime * 255.0));
    radius = ofMap(ofNoise(rNoise), 0, 1, 3, 5);
    bounds.set(-radius, -radius, ofGetWidth()+radius, ofGetHeight()+radius);
    rNoise.y += 0.5;
}

// ---------------------------------------------------------
void Sparkle::draw() {
    ofSetColor(color);
    ofDrawCircle(pos, radius);
}

// ---------------------------------------------------------
bool Sparkle::outOfBounds() {
    return !bounds.inside(pos);
}
