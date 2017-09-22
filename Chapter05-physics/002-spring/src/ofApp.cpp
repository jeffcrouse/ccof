#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("spring");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    loc.x = ofGetWidth()/2.0;
    loc.y = ofGetHeight()/2.0;
    
    origin.x = ofGetWidth()/2.0;
    origin.y = ofGetHeight()/2.0;
    
    radius = 40;
    dragging = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(!dragging)
    {
        velocity += (origin-loc);
        velocity *= .75;
        loc += velocity;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofDrawCircle(loc.x, loc.y, radius);
    
    ofDrawLine(origin.x, origin.y, loc.x, loc.y);
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
    if(dragging)
    {
        loc.x = x;
        loc.y = y;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    float d = ofDist(loc.x, loc.y, x, y);
    if(d < radius)
    {
        dragging = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    dragging = false;
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
