#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 800);
    ofSetWindowTitle("ReadFromArduino");
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetCircleResolution(40);
    
    
    serial.setup(0, 9600);
}

//--------------------------------------------------------------
void ofApp::update(){
    while(serial.available()) {
        char b = serial.readByte();
        if(b=='\n') {
            size = ofToInt(ss.str());
            ss.str("");
        } else {
            ss << b;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    float radius = ofMap(size, 0, 1024, 10, 400);
    ofDrawCircle(ofGetWidth()/2.0, ofGetHeight()/2.0, radius);
    
    ofSetColor(0);
    ofDrawBitmapString(ofToString(radius), 10, 20);
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
