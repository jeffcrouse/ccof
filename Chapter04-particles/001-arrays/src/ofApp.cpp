#include "ofApp.h"

#define NUM_PARTICLES 100

float x_pos[NUM_PARTICLES];
float y_pos[NUM_PARTICLES];
float x_vel[NUM_PARTICLES];
float y_vel[NUM_PARTICLES];
float radius[NUM_PARTICLES];
int color[NUM_PARTICLES];

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("arrays");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    
    
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        radius[i] = ofRandom(10, 20);
        x_pos[i] = ofRandom(radius[i], ofGetWidth()-radius[i]);
        y_pos[i] = ofRandom(radius[i], ofGetHeight()-radius[i]);
        x_vel[i] = ofRandom(-10, 10);
        y_vel[i] = ofRandom(-10, 10);
        color[i] = ofRandom(0xFFFFFF);
        //color[i].setHsb(ofRandom(255), 200, 200);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        x_pos[i] += x_vel[i];
        y_pos[i] += y_vel[i];
        
        // bounce
        if(x_pos[i] > ofGetWidth()-radius[i]) {
            x_pos[i] = ofGetWidth()-radius[i];
            x_vel[i] *= -1;
        }
        if(x_pos[i] < radius[i]) {
            x_pos[i] = radius[i];
            x_vel[i] *= -1;
        }
        if(y_pos[i] > ofGetHeight()-radius[i]) {
            y_pos[i] = ofGetHeight()-radius[i];
            y_vel[i] *= -1;
        }
        if(y_pos[i] < radius[i]) {
            y_pos[i] = radius[i];
            y_vel[i] *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<NUM_PARTICLES; i++)
    {
        ofSetHexColor(color[i]);
        ofCircle(x_pos[i], y_pos[i], radius[i]);
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
