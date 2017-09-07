#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(640, 480);
    ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetColor(0, 0, 255);
    ofDrawCircle(320, 240, 20);
    
    
    ofNoFill();
    ofSetColor(255, 0, 0);
    ofDrawCircle(320, 100, 20);
    
    
    ofDrawRectangle(10, 10, 40, 50);
    
    
    ofSetColor(0, 255, 0);
    ofDrawLine(320, 240, 320, 100);
    
    
    ofSetColor(40, 100, 100);
    ofFill();
    // Draw an arbitrary 3 sided shape
    // (add more calls to ofVertex to add more sides)
    ofBeginShape();
    ofVertex(20, 20);
    ofVertex(200, 20);
    ofVertex(200, 400);
    ofEndShape(true); // what does the "true" mean? And how do you know?
    
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
