#include "ofApp.h"

int frogX;
int frogY;
int frogAngle;

void ofDrawFrog() {
    
    // Draw frog body
    ofSetColor(32, 219, 36);
    ofBeginShape();
    ofVertex(9, 1);
    ofVertex(13, 1);
    ofVertex(14, 4);
    ofVertex(17, 6);
    ofVertex(18, 5);
    ofVertex(18, 1);
    ofVertex(21, 3);
    ofVertex(19, 4);
    ofVertex(19, 8);
    ofVertex(16, 7);
    ofVertex(19, 9);
    ofVertex(20, 10);
    ofVertex(21, 14);
    ofVertex(18, 15);
    ofVertex(18, 11);
    ofVertex(15, 10);
    ofVertex(13, 13);
    ofVertex(8, 13);
    ofVertex(7, 11);
    ofVertex(5, 10);
    ofVertex(4, 15);
    ofVertex(1, 13);
    ofVertex(3, 11);
    ofVertex(4, 8);
    ofVertex(6, 9);
    ofVertex(6, 7);
    ofVertex(3, 7);
    ofVertex(3, 4);
    ofVertex(1, 3);
    ofVertex(5, 1);
    ofVertex(4, 6);
    ofVertex(8, 4);
    ofVertex(9, 1);
    ofEndShape();
    
    // Draw yellow spot on back
    ofSetColor(248, 235, 21);
    ofDrawCircle(11, 7, 2);
    
    // Draw eyes
    ofSetColor(253, 3, 217);
    ofDrawCircle(7, 3, 2);
    ofDrawCircle(15, 3, 2);
}


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("matrix");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    frogX = ofGetWidth()/2;
    frogY = ofGetHeight()/2;
    frogAngle=0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    {
        ofTranslate(frogX, frogY);
        ofRotateZ(frogAngle);
        ofScale(5, 5);
        ofTranslate(-10, -7);
        
        ofDrawFrog();
    }
    ofPopMatrix();
    
    
    
    ofSetColor(255, 0, 0);
    ofRect(0, ofGetHeight()-100, ofGetWidth(), 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == OF_KEY_UP)
    {
        frogY-=10;
        frogAngle=0;
    }
    if(key == OF_KEY_DOWN)
    {
        frogY+=10;
        frogAngle=180;
    }
    if(key == OF_KEY_RIGHT)
    {
        frogX+=10;
        frogAngle=90;
    }
    if(key == OF_KEY_LEFT)
    {
        frogX-=10;
        frogAngle=270;
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
