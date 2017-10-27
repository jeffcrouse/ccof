//
//  Particle.cpp
//  fountain
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#include "Particle.hpp"

Particle::Particle() {
    acc = ofPoint(0,0);
    r = 5.0;
    timer = 100.0;
    maxspeed = 30.0;
    mass = 1.0;
}

void Particle::update() {
    vel += acc;
    vel.x = ofClamp(vel.x, -maxspeed, maxspeed);
    vel.y = ofClamp(vel.y, -maxspeed, maxspeed);
    loc += vel;
    acc.set(0, 0);
    timer -= 0.5;
}

void Particle::applyForce(ofPoint force) {
    force /= mass;
    acc += force;
}

void Particle::draw() {
    
    ofPushMatrix();
    ofTranslate(loc.x, loc.y);
    ofEnableAlphaBlending();
    ofFill();
    ofSetColor(0, 0, 0, timer);
    ofCircle(0, 0, r);
    ofSetColor(255, 0, 0, timer);
    ofLine(0, 0, vel.x, vel.y);
    ofPopMatrix();
}

bool Particle::dead() {
    if(timer <= 0.0) {
        return true;
    } else {
        return false;
    }
}
