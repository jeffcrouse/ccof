#include "ofApp.h"
#include "Elastic.h"
#include "Quart.h"

float t;        // The current "time" measured in frames.
float start_x;  // The start x position
float dist_x;   // How far should the circle travel?
float duration; // How many frames does the easing take to complete?

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 768);
    ofSetWindowTitle("penner easing");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    t           = 0;
    start_x     = 200;
    dist_x        = ofGetWindowWidth()-400;
    duration    = 200; // the animation will take 200 frames total
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Incremement "t" to move the easing forward
    if (t < duration) t++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(100, 100, 200);
    ofDrawCircle( Elastic::easeIn(t, start_x, dist_x, duration), 100, 20);
    ofDrawCircle( Elastic::easeOut(t, start_x, dist_x, duration), 200, 20);
    ofDrawCircle( Elastic::easeInOut(t, start_x, dist_x, duration), 300, 20);
    
    ofSetColor(100, 100, 200);
    ofDrawCircle( Quart::easeIn(t, start_x, dist_x, duration), 400, 20);
    ofDrawCircle( Quart::easeOut(t, start_x, dist_x, duration), 500, 20);
    ofDrawCircle( Quart::easeInOut(t, start_x, dist_x, duration), 600, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    t = 0;
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
