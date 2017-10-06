#include "ofApp.h"

float x_1;
float y_1;
float x_2;
float y_2;
float length = 250;

//--------------------------------------------------------------
void ofApp::setup(){
    x_1 = ofGetWidth() / 2.0;
    y_1 = ofGetHeight() / 2.0;
    
    float angle = ofRandom(TWO_PI);
    x_2 = x_1 + cos(angle) * length;
    y_2 = y_1 + sin(angle) * length;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    ofDrawLine(x_1, y_1, x_2, y_2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    float angle = ofRandom(TWO_PI);
    x_2 = x_1 + cos(angle) * length;
    y_2 = y_1 + sin(angle) * length;
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
