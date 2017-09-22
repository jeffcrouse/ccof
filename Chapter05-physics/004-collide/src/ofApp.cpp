#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 800);
    ofSetWindowTitle("collide");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    int v = 5;
    
    
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        radius[i] = ofRandom(5, 20);
        pos[i].x = ofRandom(radius[i], ofGetWidth()-radius[i]);
        pos[i].y = ofRandom(radius[i], ofGetHeight()-radius[i]);
        vel[i].x = ofRandom(-v, v);
        vel[i].y = ofRandom(-v, v);
        color[i].setHsb(ofRandom(255), 200, 200);
    }
    
    
    acc.y = 0.5;
    friction = 0.9;
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        vel[i] += acc;
        pos[i] += vel[i];
        
        // bounce off walls
        if(pos[i].x > ofGetWidth()-radius[i]) {
            pos[i].x = ofGetWidth()-radius[i];
            vel[i].x *= -friction;
        }
        if(pos[i].x < radius[i]) {
            pos[i].x = radius[i];
            vel[i].x *= -friction;
        }
        if(pos[i].y > ofGetHeight()-radius[i]) {
            pos[i].y = ofGetHeight()-radius[i];
            vel[i].y *= -friction;
        }
        if(pos[i].y < radius[i]) {
            pos[i].y = radius[i];
            vel[i].y *= -friction;
        }
        
        for(int j=0; j<NUM_PARTICLES; j++)
        {
            if(i==j) continue;
            float touching = radius[i] + radius[j];
            float dist = ofDist(pos[i].x, pos[i].y, pos[j].x, pos[j].y);
            if(dist < touching)
            {
                // get the mtd
                ofPoint delta = pos[i] - pos[j];
                float d = delta.length();
                // minimum translation distance to push balls apart after intersecting
                ofVec2f mtd = delta * (((radius[i] + radius[j])-d) / d);
                
                // resolve intersection --
                // inverse mass quantities
                float im1 = 1 / radius[i];
                float im2 = 1 / radius[j];
                
                // push-pull them apart based off their mass
                pos[i] += (mtd * (im1 / (im1 + im2)));
                pos[j] -= (mtd * (im2 / (im1 + im2)));
                
                // impact speed
                ofVec2f v = vel[i] - vel[j];
                float vn = v.dot(mtd.normalize());
                
                // sphere intersecting but moving away from each other already
                if (vn > 0.0f) continue;
                
                // collision impulse
                float n = (-(2.0) * vn) / (im1 + im2);
                ofVec2f impulse = mtd * n;
                
                // change in momentum
                vel[i] += impulse * im1;
                vel[j] = vel[j] - (impulse * im2);
                
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        ofSetColor(color[i]);
        ofDrawCircle(pos[i], radius[i]);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        float dist = ofDist(x, y, pos[i].x, pos[i].y);
        if(dist < 100)
        {
            vel[i].y -= 20;
            vel[i].x = ofRandom(-10, 10);
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
