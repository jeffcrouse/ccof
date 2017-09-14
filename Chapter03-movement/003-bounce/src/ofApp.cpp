#include "ofApp.h"

float velX;
float velY;
float posX;
float posY;
float radius = 20;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("bounce");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    velX = ofRandom(-4, 4);
    velY = ofRandom(-4, 4);
    posX = ofGetWidth() / 2.0;
    posY = ofGetHeight() / 2.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    posX += velX;
    posY += velY;
    
    if(posX < radius) {
        posX = radius;
        velX *= -1;
    }
    if(posX > ofGetWidth()-radius) {
        posX =ofGetWidth()-radius;
        velX *= -1;
    }
    if(posY < radius) {
        posY = radius;
        velY *= -1;
    }
    if(posY > ofGetHeight()-radius) {
        posY = ofGetHeight()-radius;
        velY *= -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0);
    ofDrawCircle(posX, posY, radius);
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
