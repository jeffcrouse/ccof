#include "ofApp.h"


#define HALF_HEIGHT ofGetHeight()/2.0
float r1;
float r2;
float r3;


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("map");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    r1 = ofMap(mouseX, 0, 1024, 10, 50);
    r2 = ofMap(mouseY, 0, 768, 10, 50);
    r3 = ofMap(ofDist(mouseX, mouseY, 0, 0), 0, 1000, 10, 50);
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(0);
    
    ofDrawCircle(256, HALF_HEIGHT, r1);
    
    ofDrawCircle(512, HALF_HEIGHT, r2);
    
    ofDrawCircle(768, HALF_HEIGHT, r3);
    
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
