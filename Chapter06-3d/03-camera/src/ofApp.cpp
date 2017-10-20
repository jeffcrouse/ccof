#include "ofApp.h"

#define SIZE 200

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("texture");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    ofEnableDepthTest();
    ofSetCylinderResolution(50, 4);
    
    
    camPosition.set(0, 0, 500);
    
    ofEnableNormalizedTexCoords();
    
    texture.load("tex02.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.setPosition(camPosition);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(100, 100, 100);
    if(bWireframe) ofNoFill();
    else ofFill();
    
    cam.begin();
    
    ofPushMatrix();
    
        ofRotateX(ofGetElapsedTimef()*20.0);
        ofRotateY(ofGetElapsedTimef()*50.0);
        ofRotateZ(ofGetElapsedTimef()*10.0);

        texture.bind();
        //ofDrawBox(200);
        ofDrawCylinder(0, 0, 50, 200);
        texture.unbind();
    
    ofPopMatrix();
    
    cam.end();
    
    ofSetColor(255);
    ofDrawBitmapString(camPosition, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='w') {
        bWireframe = !bWireframe;
    }
    if(key==OF_KEY_LEFT) {
        camPosition.x -= 10;
    }
    if(key==OF_KEY_RIGHT) {
        camPosition.x += 10;
    }
    if(key==OF_KEY_UP) {
        camPosition.y -= 10;
    }
    if(key==OF_KEY_DOWN) {
        camPosition.y += 10;
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
