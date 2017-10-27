#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableNormalizedTexCoords();
    ofEnableDepthTest();
    
    ofSetCylinderResolution(30, 2);
    ofSetConeResolution(30, 1);
    
    texture.load("tex01.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(drawWireframe) {
        ofNoFill();
    } else {
        ofFill();
    }
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateZ(ofGetElapsedTimef() * 50.0);
    ofRotateY(ofGetElapsedTimef() * 40.0);
    ofRotateX(ofGetElapsedTimef() * 20.0);
    
    texture.bind();
    ofDrawBox(300, 200, 400);
    //ofDrawCylinder(100, 300);
    //ofDrawCone(100, 300);
    //ofDrawIcoSphere(300);
    texture.unbind();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='w') {
        drawWireframe = !drawWireframe;
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
