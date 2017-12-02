#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("magnify");
    ofSetFrameRate(60);
    ofBackground(100);
    
    
    cam.setup(640, 480);
    bDrawSquares = true;
    buffer.allocate(ofGetWidth(), ofGetHeight());
    shader.load("zoom");
    
    radius = 120;
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    buffer.begin();
    cam.draw(0, 0, 1024, 768);
    
    if(bDrawSquares)
    {
        ofSetColor(255);
        for(int y = 0; y<ofGetHeight(); y+=10)
            for(int x=0; x<ofGetWidth(); x+=10) {
                ofDrawRectangle(x, y, 5, 5);
            }
    }
    buffer.end();
    
    
    shader.begin();
    shader.setUniform2f("circlePos", mouseX, mouseY);
    shader.setUniform1f("circleRadius", radius);
    shader.setUniform1f("minZoom", 0.1);
    shader.setUniform1f("maxZoom", 1);
    buffer.draw(0, 0);
    shader.end();
    
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key==' ') {
        bDrawSquares = !bDrawSquares;
    }
    if(key==OF_KEY_UP && radius < 300) {
        radius += 10;
    }
    if(key==OF_KEY_DOWN && radius > 20) {
        radius -= 10;
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
