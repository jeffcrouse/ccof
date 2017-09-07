#include "ofApp.h"

// Why are we putting the variables up here???
int radius = 100;
int xPos;
int yPos;
int speed = 5;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Pacman");
    ofSetWindowShape(1500, 200);
    ofSetCircleResolution(50);
    
    
    // And why are we assigning them values here?
    xPos = -radius;
    yPos = ofGetHeight() / 2.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    xPos = xPos + speed;
    if(xPos > ofGetWidth() + radius) {
        xPos = -radius;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::violet);
    
    ofSetColor(ofColor::mediumBlue);
    ofDrawCircle(xPos, yPos, radius);
    
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
