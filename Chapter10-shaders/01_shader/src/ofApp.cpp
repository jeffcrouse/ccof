#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 800);
    ofSetWindowTitle("passthrough");
    ofSetFrameRate(60);
    ofBackground(100);
    ofEnableSmoothing();

    //shader.load("passthrough");
    shader.load("shader");
}

//--------------------------------------------------------------
void ofApp::update(){
    rotate.x = cos(ofGetElapsedTimef() / M_TWO_PI) * 360;
    rotate.y = sin(ofGetElapsedTimef() / M_TWO_PI) * 360;
    rotate.z = sin(ofGetElapsedTimef() / M_TWO_PI) * 360;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    ofRotateX(rotate.x);
    ofRotateY(rotate.y);
    ofRotateZ(rotate.z);
    {
        // Draw fill
        shader.begin();
        shader.setUniform1f("time", ofGetElapsedTimef());
        ofFill();
        ofSetColor(100, 200, 100);
        ofDrawBox(200);
        shader.end();
        
        
        // Draw outline
        ofNoFill();
        ofSetColor(0);
        ofDrawBox(200);
    }
    ofPopMatrix();
    
    ofDisableDepthTest();
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

