#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(24);
    ofSetWindowShape(640, 480);
    ofBackgroundHex(0xEFDC9E);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // Loop 1 - blue
    ofFill();
    ofSetColor(24, 58, 117);
    for(int i=0; i<32; i++)
    {
        ofDrawCircle(20+i*20, 10, 10);
    }
    
    
    // Loop 2 - green
    ofSetColor(23, 142, 39);
    for(int x=10; x<ofGetWidth(); x+=20)
    {
        ofDrawCircle(x, ofGetHeight()-20, 10);
    }
    
    
    // Loop 3 - brown
    ofSetColor(142, 83, 23);
    float centerX = ofGetWidth()/2.0;
    float centerY = ofGetHeight()/2.0;
    for(float a=0; a<360; a+=15)
    {
        float t = ofDegToRad(a);
        float x = centerX + cos(t) * 100;
        float y = centerY + sin(t) * 100;
        ofDrawCircle(x, y, 10);
    }
    
    
    // Loop 4 - purple
    ofNoFill();
    ofSetColor(132, 84, 154);
    ofBeginShape();
    for(int a=0; a<360; a+=15)
    {
        float t = ofDegToRad(a);
        float r = (a % 10==0) ? 100 : 200;
        float x = centerX + cos(t) * r;
        float y = centerY + sin(t) * r;
        ofVertex(x, y);
    }
    ofEndShape(true);
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
