#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("pixels03");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    ofSetCylinderResolution(50, 4);
    ofSetConeResolution(50, 4);
    ofEnableDepthTest();
    
    webcam.initGrabber(640, 480);
    inc.x = 5;
    inc.y = 50;
}

//--------------------------------------------------------------
void ofApp::update(){
    webcam.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofPushMatrix();
    
    ofRotateX(180);
    ofTranslate(-webcam.getWidth()/2.0, -webcam.getHeight()/2.0);
    
    for(int y=0; y<webcam.getHeight(); y+=inc.y)
    {
        for(int x=0; x<webcam.getWidth(); x+=inc.x)
        {
            ofColor c = webcam.getPixels().getColor(x, y);        
            float b = c.getBrightness();
            float z = ofMap(b, 0, 255, -100, 100);
            
            ofSetColor(c);
            ofDrawRectangle(x, y, z, inc.x, inc.y);
        }
    }
    ofPopMatrix();
    cam.end();
    
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
