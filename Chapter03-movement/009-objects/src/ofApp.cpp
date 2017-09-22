#include "ofApp.h"


ofPoint velocity;
ofPoint position;
ofColor color;
float radius = 20;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("object");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    velocity.x = ofRandom(-6, 6);
    velocity.y = ofRandom(-6, 6);
    position.x = ofGetWidth() / 2.0;
    position.y = ofGetHeight() / 2.0;
    
    color.set(100, 100, 100);
}

//--------------------------------------------------------------
void ofApp::update(){
    position += velocity;
    
    bool hit = false;
    if(position.x < radius) {
        position.x = radius;
        velocity.x *= -1;
        hit = true;
    }
    if(position.x > ofGetWidth()-radius) {
        position.x =ofGetWidth()-radius;
        velocity.x *= -1;
        hit = true;
    }
    if(position.y < radius) {
        position.y = radius;
        velocity.y *= -1;
        hit = true;
    }
    if(position.y > ofGetHeight()-radius) {
        position.y = ofGetHeight()-radius;
        velocity.y *= -1;
        hit = true;
    }
    
    if(hit) {
        color.r = ofRandom(0, 255);
        color.g = ofRandom(0, 255);
        color.b = ofRandom(0, 255);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(color);
    ofDrawCircle(position, radius);
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
