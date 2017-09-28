#include "ofApp.h"

// OPTION 1: The code is a bit more complicated, but less math!
void ofDrawStipple(ofPoint start, ofPoint end) {
    glPushAttrib(GL_ENABLE_BIT);

    glLineStipple(5, 0xAAAA); // do a Google Image search for glLineStipple to see how to modify this pattern
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex3f(start.x, start.y, start.z);
    glVertex3f(end.x, end.y, end.z);
    glEnd();
    
    glPopAttrib();
}

// OPTION 2: The code is less complicated (ie: you know all of the functions)
// but there is more math.
// PS: This isn't "perfect" -- you might need to add one more dash at the end...
void ofDrawDashedLine(ofPoint start, ofPoint end, float dash, float gap) {
    float angle =  atan2(end.y - start.y, end.x - start.x);
    float length = start.distance(end);

    ofPoint dir;
    dir.x = cos(angle);
    dir.y = sin(angle);
    
    for(float pos=0; pos < length; pos += dash+gap) {
        ofDrawLine(start + dir * pos, start + dir * (pos+dash) );
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1200, 200);
    ofSetWindowTitle("dotted line");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofSetLineWidth(8);
    ofDrawStipple(ofPoint(100, 50), ofPoint(1100, 50));
    ofDrawDashedLine(ofPoint(100, 150), ofPoint(1100, 150), 10, 15);
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
