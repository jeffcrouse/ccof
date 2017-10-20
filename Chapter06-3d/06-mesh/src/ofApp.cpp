#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("mesh");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    ofEnableDepthTest();
    ofSetSmoothLighting(true);
    
    
    myMesh.load("teapot.ply");
    //myMesh.enableNormals();
    
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

    cam.begin();
    ofEnableLighting();
    light.enable();
    
    ofPushMatrix();
    ofScale(20, 20, 20);
    
    if(bDrawWireframe)
        myMesh.drawWireframe();
    else
        myMesh.draw();
    
    light.disable();
    ofDisableLighting();
    ofPopMatrix();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='w') {
        bDrawWireframe = !bDrawWireframe;
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
