#include "ofApp.h"

float anchorX, anchorY;             // The position of the bottom circle
float dist, angle;                  // We will use dist and angle (in radians) to determine the position of the top circle
float targetAngle;                  // This is the angle where we want the top circle to be (the dist will always stay the same)
float topX, topY, topRadius;        // Every frame, we will use the dist and angle to calculate the x,y position of the top
bool dragging;                      // Are we dragging the circle?

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    anchorX = ofGetWidth()/2.0;
    anchorY = ofGetHeight()/2.0;
    dist = 200;
    angle = targetAngle = ofDegToRad(-90);
    topRadius = 30;
    dragging = false;
    ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    // If the user is dragging the top circle, calculate the angle between
    // the mouse and the anchor point
    // Otherwise, move the angle back towards the targetAngle (remember, easing?)
    if(dragging)
    {
        angle = atan2(mouseY-anchorY, mouseX-anchorX);
    }
    else
    {
        angle += (targetAngle-angle) / 10.0;
    }
    
    
    // Determine the position of the top based on the angle and distance
    topX = anchorX + cos(angle) * dist;
    topY = anchorY + sin(angle) * dist;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    ofFill();
    ofDrawCircle(anchorX, anchorY, 10);
    
    ofNoFill();
    ofDrawCircle(topX, topY, topRadius);
    ofDrawLine(anchorX, anchorY, topX, topY);
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
    float d = ofDist(x, y, topX, topY);
    if(d < topRadius) {
        dragging = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    dragging = false;
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
