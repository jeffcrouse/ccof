#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 800);
    ofSetWindowTitle("forces");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    gravity.x = 0;
    gravity.y = 0.08;
    
    wind.x = -0.1;
    wind.y = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    t.applyForce(gravity);
    t.applyForce(wind);
    
    // Make the Thing slow down as it passes through some "liquid"
    // Do this by applying a negative force
    // 1. Decide on a drag coeffecient (negative)
    // 2. Multiply it by the vel
    // 3. Apply the force
    // 4. update()
    
    
    t.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    t.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    t.reset();
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
