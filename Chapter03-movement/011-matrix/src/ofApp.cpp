#include "ofApp.h"

void drawSnowman()
{
    ofPushStyle();
    
    // Head
    ofFill();
    ofSetColor(255,255,255);
    ofDrawCircle(50, 50, 25);
    ofDrawCircle(50, 90, 30);
    ofDrawCircle(50, 160, 50);
    
    // Eyes & Buttons
    ofSetColor(0, 0, 0);
    ofDrawCircle(42, 43, 4);
    ofDrawCircle(57, 43, 4);
    ofDrawCircle(50, 80, 3);
    ofDrawCircle(50, 100, 3);
    ofDrawCircle(50, 120, 3);
    
    // Nose
    ofSetHexColor(0xED9121);
    ofDrawTriangle(45, 51, 55, 51, 50, 65);
    
    //Arms
    ofSetHexColor(0x7B3F00);
    ofSetLineWidth(3);
    ofDrawLine(76, 85, 101, 75);
    ofDrawLine(96, 78, 97, 65);
    ofDrawLine(96, 79, 102, 85);
    ofDrawLine(24, 86, -3, 77);
    ofDrawLine(2, 80, 4, 68);
    
    // Hat
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(0, 0, 0);
    ofDrawRectangle(50, 25, 50, 5);
    ofDrawRectangle(50, 15, 30, 20);
    
    ofPopStyle();
}

void drawBoat()
{
    ofPushStyle();
    ofFill();
    
    // Hull
    ofSetHexColor(0x603311);
    ofDrawCurve(800, -400, 50, 200, 400, 200, 200, -400);
    
    // Mast
    ofDrawRectangle(200, 0, 10, 200);
    
    // Flag
    ofSetColor(0, 0, 0);
    ofDrawRectangle(100, 0, 100, 60);
    
    ofPopStyle();
}

void drawSkullAndCrossbones()
{
    ofPushStyle();
    
    // Bones
    ofFill();
    ofSetHexColor(0xFFFFCC);
    ofSetLineWidth(10);
    ofDrawLine(85, 110, 305, 308);
    ofDrawLine(330, 112, 87, 286);
    ofDrawCircle(85, 110, 20);
    ofDrawCircle(305, 308, 20);
    ofDrawCircle(330, 112, 20);
    ofDrawCircle(87, 286, 20);
    
    // Skull
    ofDrawEllipse(200, 200, 180, 200);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(200, 280, 100, 100);
    
    // Teeth
    ofSetLineWidth(3);
    ofSetColor(0, 0, 0);
    ofDrawLine(170, 300, 170, 330);
    ofDrawLine(190, 300, 190, 330);
    ofDrawLine(210, 300, 210, 330);
    ofDrawLine(230, 300, 230, 330);
    
    // Eyes
    ofDrawCircle(166, 168, 30);
    ofDrawCircle(230, 168, 25);
    
    ofPopStyle();
    
}


void drawWater()
{
    ofPushStyle();
    
    ofSetColor(0, 100, 255);
    
    for(int i=0; i<ofGetWidth(); i+=5)
    {
        float height = 20 * cos(i/30.0) + 40;
        ofDrawRectangle(i, 0, 5, height);
    }
    
    ofPopStyle();
}

float boatX, boatY;
float boatAngle;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 800);
    ofSetWindowTitle("matrix");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    boatX = 100;
    boatY = ofGetHeight();
    boatAngle=0;
}

//--------------------------------------------------------------
void ofApp::update(){
    boatX += 5;
    
    if(boatX > ofGetWidth())
    {
        boatX = -400;
    }
    boatAngle = 30 * cos(ofGetFrameNum()/20.0);
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofDrawBitmapString(ofToString(mouseX)+", "+ofToString(mouseY), mouseX, mouseY);
    
    ofPushMatrix();
    ofTranslate(boatX, boatY);
    ofRotateZ(boatAngle);
    ofTranslate(-250, -400);
    
    ofPushMatrix();
    ofTranslate(70, 100);
    ofScale(.5, .5);
    drawSnowman();
    
    ofTranslate(100, 0);
    drawSnowman();
    ofTranslate(100, 0);
    drawSnowman();
    ofTranslate(100, 0);
    drawSnowman();
    ofPopMatrix();
    
    
    drawBoat();
    
    ofPushMatrix();
    ofTranslate(110, -15);
    ofScale(.20, .20);
    drawSkullAndCrossbones();
    ofPopMatrix();
    
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofTranslate(0, ofGetHeight());
    ofScale(1, -1);
    drawWater();
    ofPopMatrix();

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
