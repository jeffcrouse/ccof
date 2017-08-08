#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Think of everything in "setup" as the settings of your program
    
    // Set the window size.
    ofSetWindowShape(640, 480);
    
    // Set the background color with R, G, and B values
    ofSetBackgroundColor(100, 100, 100);
    
    
    // Try commenting this out
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(24, 58, 117);
    ofDrawCircle(100, 200, 50);
    
    ofSetColor(23, 142, 39);
    ofDrawCircle(200, 200, 50);
    
    ofSetColor(142, 83, 23);
    ofDrawCircle(300, 200, 50);
    
    ofSetColor(132, 84, 154);
    ofDrawCircle(400, 200, 50);
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
