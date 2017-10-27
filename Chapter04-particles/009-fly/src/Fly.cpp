//
//  Fly.cpp
//  FlyStarter
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#include "Fly.hpp"


// --------------------------------------------------------------
void Fly::setup(ofImage& flyImage) {
    img = flyImage;
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    vel.x = ofRandom(-10, 10);
    vel.y = ofRandom(-10, 10);
}

// --------------------------------------------------------------
void Fly::update(ofPoint attractor, vector<Fly>& flies) {
    ofPoint acc;
    
    // 1. Accelerate *towards* the mouse
    float dist = pos.distance(attractor);
    if(dist < 300) {
        ofPoint dir = attractor - pos;
        dir.normalize();
        
        float force = ofMap(dist, 5, 300, 0, 20);
        acc = dir * force;
    }
    
    
    // 2. Accelerate *away* from any other flies
    for(int i=0; i<flies.size(); i++)
    {
        float dist = pos.distance(flies[i].pos);
        if(dist>0 && dist < 20) {
            ofPoint dir = pos - flies[i].pos;
            dir.normalize();
            float force = ofMap(dist, 0, 20, 0, 100);
            acc = dir * force;
        }
    }
    
    vel += acc;
    vel.limit(10);
    pos += vel;
    pacman();
    
    vel *= friction;
    
    if(pos.distance(lastPos) > 1) {
        angle =  atan2(lastPos.y - pos.y, lastPos.x - pos.x);
    }
    lastPos = pos;
}

// --------------------------------------------------------------
void Fly::pacman() {
    if(pos.x > ofGetWidth()+20) {
        pos.x = -20;
    }
    if(pos.y > ofGetHeight()+20) {
        pos.y = -20;
    }
    if(pos.x < -20) {
        pos.x = ofGetWidth()+20;
    }
    if(pos.y < -20) {
        pos.y = ofGetHeight()+20;
    }
}

// --------------------------------------------------------------
void Fly::boost() {
    vel.x = ofRandom(-10, 10);
    vel.y = ofRandom(-10, 10);
}

// --------------------------------------------------------------
void Fly::draw() {
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotate(ofRadToDeg(angle)-90);
    ofScale(0.1, 0.1);
    ofSetColor(255);
    img.draw(-img.getWidth()/2.0, -img.getHeight()/2.0);
    ofPopMatrix();
}
