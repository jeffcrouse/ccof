#include "ofApp.h"


class Particle
{
public:
    
    void initialize(float x, float y) {
        radius = ofRandom(10, 20);
        born = ofGetElapsedTimef();
        pos.set(x, y);
        vel.set(ofRandom(-10, 10), ofRandom(-10, 10));
        color.setHsb(ofRandom(255), 200, 200);
    }
    void updateMe() {
        pos += vel;
        
        // bounce off walls
        if(pos.x > ofGetWidth()-radius) {
            pos.x = ofGetWidth()-radius;
            vel.x *= -1;
        }
        if(pos.x < radius) {
            pos.x = radius;
            vel.x *= -1;
        }
        if(pos.y > ofGetHeight()-radius) {
            pos.y = ofGetHeight()-radius;
            vel.y *= -1;
        }
        if(pos.y < radius) {
            pos.y = radius;
            vel.y *= -1;
        }
        
        float age = ofGetElapsedTimef() - born;
        color.a = ofMap(age, 0, 5, 255, 0);
    }
    void drawMe() {
        ofSetColor(color);
        ofDrawCircle(pos, radius);
    }
    
    ofPoint pos;
    ofPoint vel;
    ofColor color;
    float radius;
    float born;
};




vector<Particle> particles;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("classes");
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<particles.size(); i++)
    {
        particles[i].updateMe();
        
        if(particles[i].color.a < 10) {
            particles.erase( particles.begin() + i );
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<particles.size(); i++)
    {
        particles[i].drawMe();
    }
    
    ofSetColor(0);
    ofDrawBitmapString("particles="+ofToString(particles.size()), 10, 20);
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
    
    Particle p;
    p.initialize(x, y);
    particles.push_back(p);
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

