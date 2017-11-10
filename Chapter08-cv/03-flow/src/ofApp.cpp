#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("flow01");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    
    cam.initGrabber(640, 480);
    
//    int width, int height,
//    double pyramidScale,
//    int pyramidLevels,
//    int windowSize,
//    int iterationsPerLevel,
//    int expansionArea,
//    double expansionSigma,
//    bool flowFeedback,
//    bool gaussianFiltering
    flowSolver.setup(640, 480, 0.35, 5, 10, 1, 3, 2.25, false, false);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        flowSolver.update(cam);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofFill();
    ofRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    ofSetColor(255, 255, 255);
    cam.draw(0, 0, cam.getWidth()*2.0, cam.getHeight()*2.0);
    
    // width,  height, lineScale, res
    flowSolver.drawColored(cam.getWidth()*2, cam.getHeight()*2, 10, 10);
    
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 20);
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
