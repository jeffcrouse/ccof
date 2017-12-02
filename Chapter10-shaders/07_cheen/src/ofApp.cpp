#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 960);
    ofSetWindowTitle("cheen");
    ofSetFrameRate(60);
    ofBackground(100);
    
    
    shader.load("cheen");

    ofEnableDepthTest();
    ofEnableNormalizedTexCoords();
    
    dir.listDir("LUTs");
    int n = ofRandom(dir.size());
    lut.load(dir.getFile(n));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    lut.draw(5, 5);
    
    cam.begin();
    
    float weight = ofMap(mouseX, 0, ofGetWidth(), 0.5, 1);
    
    shader.begin();
    shader.setUniformTexture("Tex0", lut, 0);
    shader.setUniform2f("textureSize", lut.getWidth(), lut.getHeight());
    shader.setUniform1f("alpha", weight);
    shader.setUniform4f("eyePosition", 0.0, 0.0, 1000.0, 0.0);
    
    ofDrawBox(200);
    
    shader.end();
    
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key==' ') {
        int n = ofRandom(dir.size());
        lut.load(dir.getFile(n));
    }
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
