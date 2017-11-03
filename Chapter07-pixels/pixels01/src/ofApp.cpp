#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("pixels02");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    ofSetCylinderResolution(50, 4);
    ofSetConeResolution(50, 4);
    ofEnableDepthTest();
    
    theCount.load("count.png");
    
    offset.x = (ofGetWidth()/2.0) - (theCount.getWidth()/2.0);
    offset.y = (ofGetHeight()/2.0) - (theCount.getHeight()/2.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float deltaTime = ofGetLastFrameTime() * 0.5;
    for (auto& p : particles) {
        p.update(deltaTime);
    }
    
    particles.erase(remove_if(particles.begin(), particles.end(),
                              [](const PixelParticle& p)
                              { return p.pos.y > ofGetHeight(); }),
                            particles.end());
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(particles.size()==0)
        theCount.draw(offset);
    for (auto& p : particles) {
        p.draw();
    }
    
    ofSetColor(255);
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate()), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(particles.size()==0 && key==' ') {
        int size = 3;
        for(int y=0; y<theCount.getHeight(); y+=size) {
            for(int x=0; x<theCount.getWidth(); x+=size) {
                ofPoint pos;
                pos.set(x, y);
                pos += offset;
                
                PixelParticle p;
                p.setup(pos, theCount.getColor(x, y), size);
                particles.push_back(p);
            }
        }
    }
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
