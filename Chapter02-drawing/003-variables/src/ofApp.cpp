#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Variables!");
    ofSetWindowShape(1200, 200);
    ofSetBackgroundColor(255, 255, 255);
    ofSetCircleResolution(50);

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Some variables down here.
    int yPos = ofGetHeight() / 2.0;
    int xPos = 50;
    int red = 50;
    int green = 40;
    int blue = 20;

    
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);
    
    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);

    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);

    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);

    
    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);

    
    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);
    
    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);
    
    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);
    
    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);
    
    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);
    
    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);
    
    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);
    
    xPos += 100;
    blue -= 20;
    green += 15;
    ofSetColor(red, green, blue);
    ofDrawCircle(xPos, yPos, 50);
    
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
