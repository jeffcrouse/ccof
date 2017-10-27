//
//  Fly.hpp
//  repel
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once

#include "ofMain.h"

class Fly {
public:

    void setup(ofImage& _img) {
        img = _img;
        pos.x = ofRandomWidth();
        pos.y = ofRandomHeight();
 
    }
    
    void update(ofPoint mouse) {
        float dist = ofDist(mouse.x, mouse.y, pos.x, pos.y);
        if(dist < 300) {
            float force = dist / 10.0;
            ofPoint dir = mouse - pos;
            dir.normalize();
            acc = dir * force;
        }
        
        vel += acc;
        vel.limit(10);
        
        vel *= 0.99;
        
        pos += vel;
        angle =  atan2(lastPos.y - pos.y, lastPos.x - pos.x);
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
        
        acc.set(0, 0);
        lastPos = pos;
    }
    
    void draw() {
        ofPushMatrix();
        ofTranslate(pos.x, pos.y);
        ofRotate(ofRadToDeg(angle)-90);
        ofScale(0.1, 0.1);
        ofSetColor(255);
        img.draw(-img.getWidth()/2.0, -img.getHeight()/2.0);
        ofPopMatrix();
    }
    
    ofImage img;
    float angle;
    ofPoint lastPos;
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
};
