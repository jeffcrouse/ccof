#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    newPath();
    
    boid0 = new Boid(ofPoint(0, ofGetHeight()/2), 3.0, 0.5);
    boid1 = new Boid(ofPoint(0, ofGetHeight()/2), 5.0, 1.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    // The boids follow the path
    boid0->follow(path);
    boid1->follow(path);
    // Call the generic run method (update, borders, display, etc.)
    boid0->update();
    boid1->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    path->draw();
    boid0->draw();
    boid1->draw();
    
    // Instructions
    ofDrawBitmapString("Hit space bar to toggle debugging lines.\nClick the mouse to generate a new path.",10,ofGetHeight()-30);

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
    newPath();
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

//--------------------------------------------------------------
void ofApp::newPath() {
    // A path is a series of connected points
    // A more sophisticated path might be a curve
    path = new Path();
    path->addPoint(0,ofGetHeight()/2);
    path->addPoint(ofRandom(0,ofGetWidth()/2), ofRandomHeight());
    path->addPoint(ofRandom(ofGetWidth()/2, ofGetWidth()), ofRandomHeight());
    path->addPoint(ofGetWidth(),ofGetHeight()/2);
}
