#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("pixels04");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    ofSetCylinderResolution(50, 4);
    ofSetConeResolution(50, 4);
    ofEnableDepthTest();
    
    webcam.initGrabber(640, 480);

    mesh = ofMesh::plane(640, 480, 64, 48);
    for(int i=0; i<mesh.getNumVertices(); i++) {
        mesh.addColor(ofFloatColor());
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    webcam.update();

    int i = 0;
    for(int y=0; y<webcam.getHeight(); y+=10) {
        for(int x=0; x<webcam.getWidth(); x+=10) {
            
            ofColor c = webcam.getPixels().getColor(x, y);
            if(invert) c.invert();
            
            int _c;
            if(depthDriver=='h') _c = c.getHue();
            if(depthDriver=='s') _c = c.getSaturation();
            if(depthDriver=='b') _c = c.getBrightness();
            
            float z = ofMap(_c, 0, 255, 100, -100);
        
            float _z = mesh.getVertices()[i+0].z;
            mesh.getVertices()[i].z = ofLerp(_z, z, ofGetLastFrameTime()*2);
            mesh.getColors()[i].set(c);

            i++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofPushMatrix();
    ofRotateX(180); // For some reason, ofEasyCam flips everything upside down, so we fix that.

    mesh.drawWireframe();
    ofPopMatrix();
    cam.end();
    
    ofSetColor(255);
    string message = "fps: " + ofToString(ofGetFrameRate()) + "\n";
    message += "Press 'i' to invert.\n";
    message += "Press 'h', 's', or 'b' to change the depth driver.\n";
    ofDrawBitmapString(message, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='i') {
        invert = !invert;
    }
    if(key=='h' || key=='s' || key=='b') {
        depthDriver = key;
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
