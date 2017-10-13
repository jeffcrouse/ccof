#include "ofApp.h"

vector<ofPoint> pos;
vector<float> x_start;
vector<ofPoint> speed;
vector<float> radius;
vector<ofColor> color;


ofPoint popper;
float popperRadius;

float nextBubble;
float bubbleDelay = 0.1;


//--------------------------------------------------------------
void ofApp::setup(){

    nextBubble = ofGetElapsedTimef()+bubbleDelay;
    
    popper.x = ofGetWidth() / 2.0;
    popper.y = ofGetHeight() / 2.0;
    popperRadius = 20;
}

//--------------------------------------------------------------
void ofApp::update(){
    float now = ofGetElapsedTimef();
    
    // make a new bubbble
    if(now > nextBubble)
    {
        float r = ofRandom(20, 50);
        radius.push_back( r );
        pos.push_back(ofPoint(0, ofGetWindowHeight()+r));
        x_start.push_back(ofRandomWidth());
        speed.push_back(ofPoint(ofRandom(2, 5), ofRandom(-4, -2)));
        
        ofColor c;
        c.r = ofRandom(0, 10);
        c.g = ofRandom(100, 200);
        c.b = ofRandom(200, 255);
        c.a = ofRandom(100, 200);
        color.push_back(c);
        
        nextBubble = now + bubbleDelay;
    }
    
    
    // Update all of the bubbles
    // Loop backwards so that we can delete if we need to
    for(int i=pos.size()-1; i>=0; i--)
    {
        pos[i].x = x_start[i] + cos(ofGetElapsedTimef() * speed[i].x) * radius[i];
        pos[i].y += speed[i].y;

        // Delete the bubble if it hits the popper, or if it goes above the top of the window
        if(pos[i].distance(popper) < popperRadius+radius[i] || pos[i].y < -radius[i]) {
            pos.erase(pos.begin()+i);
            speed.erase(speed.begin()+i);
            radius.erase(radius.begin()+i);
            color.erase(color.begin()+i);
            x_start.erase(x_start.begin()+i);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<pos.size(); i++) {
        ofSetColor(color[i]);
        ofDrawCircle(pos[i], radius[i]);
    }
    

    ofSetColor(0);
    ofDrawCircle(popper, popperRadius);
    
    ofDrawBitmapString(ofToString(pos.size()), 10, 20);
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
