#include "ofApp.h"

ofPolyline path;
float pct;      // pct is the "percentage" of the distance along the star path, normalized (0-1)

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("star path");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    // Here we are making a star shape, just like we did in class.
    // But instead of drawing it, we are saving the verticies into an object
    // called an ofPolyline, that will let us move things along the resulting path
    ofPoint center;
    center.x = ofGetWidth() / 2.0;
    center.y = ofGetHeight() / 2.0;
    
    float outerRadius = 300;
    float innerRadius = 100;
    bool inner = false;
    for(int i=0; i<=360; i+=360/10)
    {
        float r = inner ? innerRadius : outerRadius;
        float x = center.x + cos(ofDegToRad(i)) * r;
        float y = center.y + sin(ofDegToRad(i)) * r;
        path.addVertex(x, y);
        inner = !inner;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Here we are increasing the
    pct += 0.005; // this controls the speed
    
    // If pct gets higher than 1, reset it to 0
    if(pct > 1)
    {
        pct = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //path.draw(); // you can draw the star path if you want
    ofSetColor(100, 100, 255);
    
    // use the getPointAtPercent function to get an ofPoint along the path
    // as an argument, we give it the percentage that we are slowly incrementing
    ofPoint p = path.getPointAtPercent(pct);
    ofDrawCircle(p, 20);

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
