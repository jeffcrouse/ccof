#include "ofApp.h"

#define SIZE 200

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("light");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    ofEnableDepthTest();
    ofSetCylinderResolution(50, 4);
    ofSetConeResolution(50, 4);
    
    ofEnableNormalizedTexCoords();
    
    texture.load("tex03.jpg");
    
    light.setPointLight();
    lightColor.setHsb(ofRandom(255), 255, 255);
}

//--------------------------------------------------------------
void ofApp::update(){
    float hue = (int)(ofGetElapsedTimef() * 50) % 255;
    
    lightColor.setHue(hue);
    light.setPosition(cam.getPosition());
    light.setDiffuseColor(lightColor);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(100, 100, 100);
    if(bWireframe) ofNoFill();
    else ofFill();
    
    cam.begin();
    ofEnableLighting();
    light.enable();
    
    ofPushMatrix();
    
    texture.bind();
    //ofDrawBox(200);
    //ofDrawCylinder(0, 0, 100, 300);
    ofDrawCone(200, 400);
    texture.unbind();
    
    ofPopMatrix();
    
    light.disable();
    ofDisableLighting();
    cam.end();
    
    ofSetColor(255);
    ofDrawBitmapString(cam.getPosition(), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='w') {
        bWireframe = !bWireframe;
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

