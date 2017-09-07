#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    int sides = 12;
    float radius = 100;
    bool dip=true;
    int x, y;
    float starishness = 2;
    
    
    ofBeginShape();
    for(int i=0; i<360; i+=(360/sides))
    {
        float r;
        if(dip) {
            r = radius-(radius/starishness);
        } else {
            r = radius;
        }
        
        x = r * cos(ofDegToRad(i)) + (ofGetWidth()/2.0);
        y = r * sin(ofDegToRad(i)) + (ofGetHeight()/2.0);
        
        ofVertex(x, y);
        dip = !dip;
    }

    ofEndShape();
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
