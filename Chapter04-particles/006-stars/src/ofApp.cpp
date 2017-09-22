#include "ofApp.h"
#include "Star.hpp"

vector<Star> stars;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("stars");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<stars.size(); i++)
    {
        stars[i].updateMe(stars);
        
        if(stars[i].age > 240)
        {
            stars.erase( stars.begin() + i );
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::black);
    ofEnableAlphaBlending();
    
    
    for (int i=0; i<stars.size(); i++)
    {
        stars[i].drawMe();
    }
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
    Star b;
    b.radius = ofRandom(5, 20);
    b.mass = b.radius;
    b.age = 0;
    b.r = ofRandom(0, 255);
    b.g = ofRandom(0, 255);
    b.b = ofRandom(0, 255);
    b.a = 255;
    b.position.x = mouseX;
    b.position.y = mouseY;
    b.sides = (int)ofRandom(3,10)*2;
    b.starishness = ofRandom(2, 4);
    b.rotate_speed = ofRandom(-20, 20);
    b.velocity.x = ofRandom(-10, 10);
    b.velocity.y = ofRandom(-10, -20);
    
    stars.push_back( b );
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
