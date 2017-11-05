#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    pizza.load("pizza_small.png");
    size.x = 10;
    size.y = 2;
    
    speed.x = 0.005;
    speed.y = 0.001;
    
    waveSize = 200;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofTranslate(-pizza.getWidth()/2.0, -pizza.getHeight()/2.0);
    //pizza.draw(0, 0);
    for(int y=0; y<pizza.getHeight(); y+=size.y) {
        for(int x=0; x<pizza.getWidth(); x+=size.x) {
            
            ofSetColor(pizza.getColor(x, y));
            
            ofPoint n;
            n.x = x / (float)pizza.getWidth();
            n.y = y / (float)pizza.getHeight();
            
            float z = ofSignedNoise(n+offset) * waveSize;
            
            ofDrawRectangle(x, y, z, size.x, size.y);
        }
    }
    cam.end();
    
    offset += speed;
    
    ofSetColor(255);
    string message = "fps=" + ofToString(ofGetFrameRate()) + "\n";
    message += "speed.x = " + ofToString(speed.x) + " (x/X to adjust)\n";
    message += "speed.y = " + ofToString(speed.y) + " (y/Y to adjust)\n";
    message += "size.x = " + ofToString(size.x) + " (n/N to adjust)\n";
    message += "size.y = " + ofToString(size.y) + " (o/O to adjust)\n";
    message += "waveSize = " + ofToString(waveSize) + " (w/W to adjust)\n";
    ofDrawBitmapString(message, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='x') {
        speed.x -= 0.001;
    }
    if(key=='X') {
        speed.x += 0.001;
    }
    if(key=='y') {
        speed.y += 0.001;
    }
    if(key=='Y') {
        speed.y += 0.001;
    }
    
    if(key=='n' && size.x>2) {
        size.x -= 2;
    }
    if(key=='N') {
        size.x += 2;
    }
    if(key=='o' && size.y >2) {
        size.y -= 2;
    }
    if(key=='O') {
        size.y += 2;
    }
    
    if(key=='w') {
        waveSize -= 10;
    }
    if(key=='W') {
        waveSize += 10;
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
