#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    a.loc.x = ofGetWidth()/2;
    a.loc.y = ofGetHeight()/2;
    
    for(int i=0; i<10; i++) {
        Thing t;
        things.push_back( t );
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<things.size(); i++) {
        // Calculate a force exerted by "attractor" on "thing"
        ofPoint f = a.calcGravForce(things[i]);
        // Apply that force to the thing
        things[i].applyForce(f);
        // Update the positions of both objects
        things[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    a.draw();
    for(int i=0; i<things.size(); i++) {
        things[i].draw();
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
    a.rollover(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    a.drag(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    a.clicked(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    a.stopDragging();
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
