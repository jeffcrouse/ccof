#include "ofApp.h"


class Particle {
public:
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
        particles[i].pos += particles[i].vel;
        
        // bounce off walls
        if(particles[i].pos.x > ofGetWidth()-particles[i].radius) {
            particles[i].pos.x = ofGetWidth()-particles[i].radius;
            particles[i].vel.x *= -1;
        }
        if(particles[i].pos.x < particles[i].radius) {
            particles[i].pos.x = particles[i].radius;
            particles[i].vel.x *= -1;
        }
        if(particles[i].pos.y > ofGetHeight()-particles[i].radius) {
            particles[i].pos.y = ofGetHeight()-particles[i].radius;
            particles[i].vel.y *= -1;
        }
        if(particles[i].pos.y < particles[i].radius) {
            particles[i].pos.y = particles[i].radius;
            particles[i].vel.y *= -1;
        }
        
        float age = ofGetElapsedTimef() - particles[i].born;
        particles[i].color.a = ofMap(age, 0, 5, 255, 0);
        
        if(particles[i].color.a < 10)
        {
            particles.erase( particles.begin() + i );
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<particles.size(); i++)
    {
        ofSetColor(particles[i].color);
        ofDrawCircle(particles[i].pos, particles[i].radius);
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
    p.radius = ofRandom(10, 20);
    p.born = ofGetElapsedTimef();
    
    p.pos = ofPoint(x, y);
    //p.pos.set(x, y); // this is better syntax -- does the same thing
    p.vel = ofPoint(ofRandom(-10, 10), ofRandom(-10, 10));
    //p.vel.set(ofRandom(-10, 10), ofRandom(-10, 10)); // this is better syntax -- does the same thing
    p.color = ofColor::fromHsb(ofRandom(255), 200, 200);
    //p.color.setHsb(ofRandom(255), 200, 200); // this is better syntax -- does the same thing
    
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
