#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("flies");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    
    image.load("fly.png");
    
    for(int i=0; i<50; i++)
    {
        Fly fly;
        fly.setup(image);
        flies.push_back(fly);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<flies.size(); i++)
        flies[i].update(mouse, flies);
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<flies.size(); i++)
        flies[i].draw();
    
    ofSetColor(0);
    ofDrawBitmapString(ofGetFrameRate(), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouse.x = x;
    mouse.y = y;
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
