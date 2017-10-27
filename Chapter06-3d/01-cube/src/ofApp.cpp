#include "ofApp.h"

#define SIZE 200

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("cube");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    ofSetCylinderResolution(50, 4);
    ofSetConeResolution(50, 4);
    ofEnableDepthTest();

    
    center.x = ofGetWidth() / 2.0;
    center.y = ofGetHeight() / 2.0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(100, 100, 100);
    if(bWireframe) ofNoFill();
    else ofFill();
    
    ofPushMatrix();
    
        ofTranslate(center);

        ofRotateX(ofGetElapsedTimef()*20.0);
        ofRotateY(ofGetElapsedTimef()*50.0);
        ofRotateZ(ofGetElapsedTimef()*10.0);

        ofDrawBox(200);
        //ofDrawCylinder(0, 0, 100, 300);
        //ofDrawCone(200, 400);
        
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='w') {
        bWireframe = !bWireframe;
    }
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
