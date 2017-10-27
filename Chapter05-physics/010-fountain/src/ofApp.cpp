#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(200, 200, 200);
    
    gravity.y = 0.2;
}

//--------------------------------------------------------------
void ofApp::update(){
    ps.applyForce(gravity);
    ps.update();
    
    for(int i=0; i<10; i++) {
        ps.addParticle(ofGetWidth()/2, ofGetHeight()-10);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ps.draw();
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
