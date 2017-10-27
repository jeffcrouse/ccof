//
//  Fly.cpp
//  repel
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#include "Fly.hpp"

void Fly::setup(ofImage& _img) {
    img = _img;
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    sfx.load("fly.wav");
    sfx.setLoop(true);
    sfx.play();
    sfx.setPosition(ofRandomf());
    sfx.setVolume(0);
}

void Fly::update(ofPoint mouse, vector<Fly>& flies) {
    
    // 1. Stay away from mouse if it is close
    float dist = ofDist(mouse.x, mouse.y, pos.x, pos.y);
    if(dist < 300) {
        float force = dist / 10.0;
        ofPoint dir = mouse - pos;
        dir.normalize();
        acc += dir * force;
    }
    
    // 2. Stay away from other flies if they are close
    for(int i=0; i<flies.size(); i++)
    {
        if(&flies[i]==this)
            continue;
        
        float dist = ofDist(pos.x, pos.y, flies[i].pos.x, flies[i].pos.y);
        if(dist < 40)
        {
            ofPoint dir = pos - flies[i].pos; // "away" direction
            dir.normalize();
            acc += dir * (dist / 10.0);
        }
    }
    
    // 3. Now apply the acceleration we've calculated
    vel += acc;
    vel.limit(10);
    vel *= 0.99;
    acc.set(0, 0);
    

    // Apply the velocity to the position
    pos += vel;
    
    // loop position 
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
    
    // set the volume of the sound effect
    sfx.setVolume(ofMap(vel.length(), 0, 10, 0, 1));
    
    // Calculate the angle that the fly is heading
    angle =  atan2(lastPos.y - pos.y, lastPos.x - pos.x);
    
    
    // Save the position for the next time through the loop
    lastPos = pos;
}

void Fly::draw() {
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotate(ofRadToDeg(angle)-90);
    ofScale(0.1, 0.1);
    ofSetColor(255);
    img.draw(-img.getWidth()/2.0, -img.getHeight()/2.0);
    ofPopMatrix();
}
