#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("gravity");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    radius = 20;
    pos.set(ofGetWidth()/2.0, 20);
    vel.set(0, 0);
    acc.set(0, 0.8);
}

//--------------------------------------------------------------
void ofApp::update(){
    vel += acc;
    pos += vel;
    
    // gravity
    if(pos.y >= ofGetHeight()-radius)
    {
        pos.y = ofGetHeight()-radius;
        vel.y *= -0.7;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetColor(24, 58, 117);
    ofDrawCircle(pos.x, pos.y, radius);
    
    // Shows velocity
    ofSetColor(255, 0, 0);
    ofDrawLine(pos.x, pos.y, pos.x+vel.x, pos.y+vel.y);
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
