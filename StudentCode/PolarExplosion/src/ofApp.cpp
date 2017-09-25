#include "ofApp.h"

#define NUM_OBJECTS 100


float angle[NUM_OBJECTS];
float dist[NUM_OBJECTS];
float speed[NUM_OBJECTS];
float color[NUM_OBJECTS];
float alpha[NUM_OBJECTS];
float size[NUM_OBJECTS];

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(800, 800);
    ofSetWindowTitle("polar coordinates");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    for(int i=0; i<NUM_OBJECTS; i++) {
        angle[i] = ofRandom(TWO_PI);
        speed[i] = ofRandom(0.5, 5);
        color[i] = ofRandom(0, 200);
        alpha[i] = ofRandom(100, 255);
        size[i] = ofRandom(5, 20);
        dist[i] = ofRandom(0, 500);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<NUM_OBJECTS; i++) {
        dist[i] += speed[i];
        if(dist[i] > 500) {
            dist[i] = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::gray);
    
    float cx = ofGetWindowWidth() / 2.0;
    float cy = ofGetWindowHeight() / 2.0;
    
    for(int i=0; i<NUM_OBJECTS; i++) {
        
        float x = cx + cos(angle[i]) * dist[i];
        float y = cy + sin(angle[i]) * dist[i];
        
        ofSetColor(color[i], alpha[i]);
        ofDrawCircle(x, y, size[i]);
        
    }
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
