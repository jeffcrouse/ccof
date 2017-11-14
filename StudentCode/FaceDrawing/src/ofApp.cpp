#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(320, 240);
    finder.setup("haarcascade_frontalface_default.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    finder.findHaarObjects(cam.getPixels());
    if(finder.blobs.size()>0) {
        ofPoint pt = finder.blobs[0].boundingRect.getCenter();
        if(pt.distance(lastPoint) > 2) {
            trail.push_back( pt );
            lastPoint = pt;
        }
    }
    
    if(trail.size() > 300) {
        trail.erase(trail.begin());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofPushMatrix();
    ofScale(3, 3);
    
    ofSetColor(255, 100);
    cam.draw(0, 0);
    
    ofSetColor(100);
    for(int i=0; i<trail.size(); i++) {
        ofDrawCircle(trail[i], 3);
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key==' ') {
        trail.clear();
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
