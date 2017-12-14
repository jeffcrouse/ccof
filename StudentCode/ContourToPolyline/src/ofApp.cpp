#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1920, 1080);
    ofSetWindowTitle("blob to polyline");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    
    cam.listDevices();
    cam.setDeviceID(0);
    cam.setVerbose(true);
    cam.setup(320,240);
    
    colorImg.allocate(320,240);
    grayImage.allocate(320,240);
    grayBg.allocate(320,240);
    grayDiff.allocate(320,240);
    
    scale = ofGetWidth() / 320.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    
    if(cam.isFrameNew()) {
        colorImg.setFromPixels(cam.getPixels());
        colorImg.mirror(false, true);
        
        grayImage = colorImg;
        
        if(learnBackground) {
            grayBg = grayImage;
            learnBackground = false;
        }
        
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(80);
        
        graySmoothed = grayDiff;
        graySmoothed.blur(11);
        graySmoothed.threshold(80);
        for(int i=0; i<2; i++)  graySmoothed.erode();
        for(int i=0; i<3; i++)  graySmoothed.dilate();
        
        // input, minArea, maxArea, nConsidered, bFindHoles, bUseApproximation
        contourFinder.findContours(graySmoothed, 20, (340*240)/3, 1, false);
        
        if(contourFinder.nBlobs > 0) {
            contour.clear();
            
            ofxCvBlob& blob = contourFinder.blobs[0];
            vector <ofPoint>& pts = blob.pts;
            for (int i = 0; i < pts.size(); i++){
                ofPoint p = pts[i];
                p *= scale;
                contour.addVertex(p);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    colorImg.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    contour.draw();
    
    ofDrawBitmapStringHighlight("fps="+ofToString(ofGetFrameRate()), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key==' ') {
        learnBackground = true;
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

