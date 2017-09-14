#include "ofApp.h"


float posX;
float posY;
float radius = 20;
float halfHeight;
float amplitude = 50.0;


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1200, 200);
    ofSetWindowTitle("wave");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    halfHeight = ofGetHeight()/2.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    // Move the X position of the circle with a constant speed
    posX += 3.5;
    
    // Do some trigonometry to calculate the y position
    posY = halfHeight + cos( ofGetFrameNum() / 5.0 ) * amplitude;
    
    // Do the pacman loop
    if(posX > ofGetWidth() + radius) {
        posX = -radius;
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
