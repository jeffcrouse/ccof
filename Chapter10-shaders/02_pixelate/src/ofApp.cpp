#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("pixelate");
    ofSetFrameRate(60);
    ofBackground(100);
    ofSetDataPathRoot("../Resources/data/");
    
    cam.setup(640, 480);
    
    shader.load("pixelate");
    
    divisor.set(20, 20);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    shader.begin();
    shader.setUniform2f("sampleDivisor", divisor.x, divisor.y);
    ofSetColor(255, 255, 255);
    cam.draw(0, 0, 1024, 768);
    shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    divisor.x = ofMap(x, 0, ofGetWidth(), 1, 20);
    divisor.y = ofMap(y, 0, ofGetHeight(), 1, 20);
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
