#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 800);
    ofSetWindowTitle("twoKnob");
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetCircleResolution(40);
    
    serial.setup(0, 9600);
}

//--------------------------------------------------------------
void ofApp::update(){
    while(serial.available()) {
        char b = serial.readByte();
        if(b=='\n') {
            vector<string> parts = ofSplitString(buffer, " ");
            int val = ofToInt(parts[1]);
            
            if(parts[0]=="x") {
                p.x = ofMap(val, 0, 1023, radius, ofGetWidth()-radius);
            }
            if(parts[0]=="y") {
                p.y = ofMap(val, 0, 1023, radius, ofGetHeight()-radius);
            }
            
            buffer = "";
        } else {
            buffer += b;
        }
    }
    
    int n = trail.size();
    if(n==0 || trail[n-1].distance(p)>3) {
        trail.push_back(p);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofDrawCircle(p, radius);
    
    ofNoFill();
    ofBeginShape();
    for(int i=0; i<trail.size(); i++) {
        ofVertex(trail[i]);
    }
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==' ') {
        trail.clear();
    }
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
