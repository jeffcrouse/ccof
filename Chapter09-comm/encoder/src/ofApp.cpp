#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 800);
    ofSetWindowTitle("encoder");
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(30);
    
    serial.setup(0, 9600);
}

//--------------------------------------------------------------
void ofApp::update(){
    while(serial.available()) {
        char b = serial.readByte();
        if(b=='\n') {
            string line = ss.str();
            //ofLogNotice() << line;
            vector<string> words = ofSplitString(line, " ");
            
            if(words[0]=="move") {
                int amount = ofToInt(words[1]);
                if(mode==MODE_ANGLE) {
                    angle += amount / 20.0;
                }
                if(mode==MODE_RADIUS) {
                    radius += amount / 5.0;
                }
                if(mode==MODE_SIZE) {
                    size += amount / 5.0;
                }
            }
            if(words[0]=="click") {
                int num = ofToInt(words[1]);
                if(num==1) {
                    color.setHsb(ofRandom(255), 255, 255);
                }
                if(num==2) {
                    mode = mode+1;
                    mode %= 3;
                }
            }
            ss.str("");
        } else {
            ss << b;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    
    ofNoFill();
    ofSetColor(color);
    ofDrawCircle(0, 0, radius);
    
    float x = cos(angle) * radius;
    float y = sin(angle) * radius;
    ofFill();
    ofDrawCircle(x, y, size);
    
    ofPopMatrix();
    
    
    ofSetColor(255);
    stringstream message;
    if(mode==MODE_ANGLE) {
        message << "mode: angle" << endl;
    }
    else if(mode==MODE_RADIUS) {
        message << "mode: radius" << endl;
    }
    else if(mode==MODE_SIZE) {
        message << "mode: size" << endl;
    }
    message << "angle: " << ofRadToDeg( angle ) << endl;
    message << "radius: " << radius << endl;
    message << "size: " << size << endl;
    ofDrawBitmapString(message.str(), 10, 20);
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
