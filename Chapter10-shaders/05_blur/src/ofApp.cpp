#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 960);
    ofSetWindowTitle("noise");
    ofSetFrameRate(60);
    ofBackground(100);
    ofEnableSmoothing();
    
    cam.initGrabber(640, 480);
    buffer[0].allocate(ofGetWidth(), ofGetHeight());
    buffer[1].allocate(ofGetWidth(), ofGetHeight());
    
    hBlur.load("blur.vert", "hblur.frag");
    vBlur.load("blur.vert", "vblur.frag");
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    
    buffer[0].begin();
    cam.draw(50, 50);
    buffer[0].end();

    float amount = ofMap(mouseY, 0, ofGetHeight(), 4, 0);
    int iterations = 5;
    for (int i=0; i<iterations; i++)
    {
        //apply horizontal blur to fbo1 and put the result in fbo2
        buffer[1].begin();
        hBlur.begin();
        hBlur.setUniform1f("amt", amount);
        buffer[0].draw(0,0);
        hBlur.end();
        buffer[1].end();
        
        //apply vertical blur to fbo2 and put this back in fbo1
        buffer[0].begin();
        vBlur.begin();
        vBlur.setUniform1f("amt", amount);
        buffer[1].draw(0,0);
        hBlur.end();
        buffer[0].end();
    }
    
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 20);
}

//--------------------------------------------------------------
void ofApp::draw(){
    buffer[0].draw(20, 20, 1024, 768);
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
