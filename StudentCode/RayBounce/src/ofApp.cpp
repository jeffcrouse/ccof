#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    Obstacle o;
    o.setup(ofPoint(500,300), 150, 200);
    obstacles.push_back( o );
}

//--------------------------------------------------------------
void ofApp::update(){
    float now = ofGetElapsedTimef();
    if(now > nextRay) {
        float angle = ofRandom(30, 50);
        
        Ray r;
        r.setup(ofPoint(10,10), angle);
        rays.push_back(r);
        
        nextRay = now + rayDelay;
    }
    
    for(int i=0; i<rays.size(); i++) {
        rays[i].update(obstacles);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<rays.size(); i++) {
        obstacles[i].draw();
    }
    
    for(int i=0; i<rays.size(); i++) {
        rays[i].draw();
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
