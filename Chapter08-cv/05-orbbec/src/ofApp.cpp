#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetWindowShape(640*2, 768);
    ofSetVerticalSync(true);
    
    astra.setup();
    astra.enableRegistration(true);
    
    astra.initColorStream();
    astra.initDepthStream();
    
    gui.setup();
    gui.add( near.set("near", 30, 0, 8000) );
    gui.add( far.set("far", 1800, 0, 8000) );
    

    grayImage.allocate(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
    astra.setDepthClipping(near.get(), far.get());
    astra.update();
    
    if(astra.isFrameNew()) {

        grayImage.setFromPixels(astra.getDepthImage());
        grayImage.threshold(80);

        contourFinder.findContours(grayImage, 20, (640*480)/3, 10, true);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    astra.drawDepth(0, 0);
    astra.draw(640, 0);

    contourFinder.draw(640, 0);
    gui.draw();
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
