#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("IntroToFBO");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);

    
    
    
    
    fbo.allocate(600, 600);
    
    fbo.begin();
    ofClear(0);
    for(int y=20; y<fbo.getHeight()-20; y+=20) {
        for(int x = 20; x< fbo.getWidth()-20; x+=20) {
            c.setHsb(ofRandom(255), 255, 255);
            ofSetColor(c);
            ofDrawCircle(x, y, 10);
        }
    }
    fbo.end();

}

//--------------------------------------------------------------
void ofApp::update(){
    rot.x += 50 * ofGetLastFrameTime();
    rot.y += 20 * ofGetLastFrameTime();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    ofRotateX(rot.x);
    ofRotateY(rot.y);
    ofTranslate(-300, -300);
    
    fbo.draw(20, 20);
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    fbo.begin();
    ofClear(0);
    for(int y=20; y<fbo.getHeight()-20; y+=20) {
        for(int x = 20; x< fbo.getWidth()-20; x+=20) {
            c.setHsb(ofRandom(255), 255, 255);
            ofSetColor(c);
            ofDrawCircle(x, y, 10);
        }
    }
    fbo.end();
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
