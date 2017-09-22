#include "ofApp.h"

vector<ofPoint> pos;
vector<ofPoint> vel;
vector<ofColor> color;
vector<float> radius;
vector<float> born;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("vectors");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<pos.size(); i++)
    {
        pos[i] += vel[i];
        
        // bounce off walls
        if(pos[i].x > ofGetWidth()-radius[i]) {
            pos[i].x = ofGetWidth()-radius[i];
            vel[i].x *= -1;
        }
        if(pos[i].x < radius[i]) {
            pos[i].x = radius[i];
            vel[i].x *= -1;
        }
        if(pos[i].y > ofGetHeight()-radius[i]) {
            pos[i].y = ofGetHeight()-radius[i];
            vel[i].y *= -1;
        }
        if(pos[i].y < radius[i]) {
            pos[i].y = radius[i];
            vel[i].y *= -1;
        }
        
        float age = ofGetElapsedTimef() - born[i];
        color[i].a = ofMap(age, 0, 5, 255, 0);
        
        if(color[i].a < 10)
        {
            radius.erase(radius.begin() + i);
            pos.erase(pos.begin()+i);
            vel.erase(vel.begin()+i);
            color.erase(color.begin()+i);
            born.erase(born.begin()+i);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<pos.size(); i++)
    {
        ofSetColor(color[i]);
        ofDrawCircle(pos[i], radius[i]);
    }
    
    ofSetColor(0);
    ofDrawBitmapString("particles="+ofToString(pos.size()), 10, 20);
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
    radius.push_back( ofRandom(10, 20) );
    pos.push_back( ofPoint(x, y) );
    vel.push_back( ofPoint(ofRandom(-10, 10), ofRandom(-10, 10)) );
    color.push_back( ofColor::fromHsb(ofRandom(255), 200, 200) );
    born.push_back( ofGetElapsedTimef() );
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
