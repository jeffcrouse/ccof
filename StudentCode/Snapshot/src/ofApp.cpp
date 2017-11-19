#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1080, 480);
    ofSetWindowTitle("snapshot");
    ofBackground(0);

    
    cam.initGrabber(640, 480);
    snapshot.allocate(width, height, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(takeSnapshot) {
        // Get the pixels from the camera
        ofPixels& pixels = cam.getPixels();

        // Crop the pixels to the size we want
        // In this case, we're just taking a random 200x200 square from the image
        int x = ofRandom(0, pixels.getWidth()-width);
        int y = ofRandom(0, pixels.getHeight()-height);
        pixels.crop(x, y, width, height);
    
        // Set the cropped pixels into the "snapshot" ofImage
        snapshot.setFromPixels(pixels);
        takeSnapshot=false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.draw(0, 0);
    snapshot.draw(750, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==' ') {
        takeSnapshot=true;
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
