#include "ofApp.h"


float px;
float py;
float ix = 0;
float iy = 0.5;


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("noise");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
   
    float cx = ofGetWidth() / 2.0;
    float cy = ofGetHeight() / 2.0;
    
    float nx = ofNoise(ix);
    float ny = ofNoise(iy);
    

    px = centerX + offsetX;
    py = centerY + offsetY;
    
    ix += 0.01;
    iy += 0.01;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofDrawCircle(px, py, 20);
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
