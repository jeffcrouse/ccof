#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(36);
    ofBackground(200, 200, 200);
    
    gravity.y = 0.01;
    
    for(int i=0; i<10; i++) {
        repellers.push_back(new Repeller());
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ps.applyForce(gravity);
    ps.applyRepellers(repellers);
    ps.update();
    
    if(ps.particles.size() < 200)
        ps.addParticle();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ps.draw();
    for(int i=0; i<repellers.size(); i++) {
        repellers[i]->draw();
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
    for(int i=0; i<repellers.size(); i++) {
        repellers[i]->drag(mouseX, mouseY);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for(int i=0; i<repellers.size(); i++) {
        repellers[i]->clicked(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for(int i=0; i<repellers.size(); i++) {
        repellers[i]->stopDragging();
    }
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
