#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("pixels02");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    ofSetCylinderResolution(50, 4);
    ofSetConeResolution(50, 4);
    ofEnableDepthTest();
    
    theCount.load("count.png");
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

    for(int y=0; y<theCount.getHeight(); y++)
    {
        for(int x=0; x<theCount.getWidth(); x++)
        {
            ofColor c = theCount.getColor(x, y);
            if(c.a > 0)
            {
                float b = c.getBrightness();
                float z = ofMap(b, 0, 255, -100, 100);
                ofSetColor(c);
                
                float _x = x - (theCount.getWidth()/2.0);
                float _y = y - (theCount.getHeight()/2.0);
                ofDrawRectangle(_x, _y, z, 1, 1);
            }
        }
    }
    ofPopMatrix();
    
    
    ofSetColor(255);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 10, 20);
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
