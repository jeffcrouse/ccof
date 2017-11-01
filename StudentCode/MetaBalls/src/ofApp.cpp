#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("metaball");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofSetCircleResolution(40);
    
    
    filter.setup();
    
    gradient.load("gradient.png");
    for(int i=0; i<NUM_ORBS; i++) {
        orbs[i].setup(gradient);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<NUM_ORBS; i++) {
        orbs[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    filter.begin();
    for(int i=0; i<NUM_ORBS; i++) {
        orbs[i].draw();
    }
    filter.end();
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
