#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("cv01");
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
        contourFinder.findContours(graySmoothed, 20, (340*240)/3, 10, false);
        
        for (int i = 0; i < contourFinder.nBlobs; i++){
            ofxCvBlob& blob = contourFinder.blobs[i];
            vector <ofPoint>& pts = blob.pts;
            for(int j=0; j<pts.size(); j++) {
                ofPoint pos = pts[j] * 4;

                Sparkle s;
                s.setup(pos);
                sparkles.push_back(s);
            }
        }
    }
    
    float deltaTime = ofGetLastFrameTime();
    for (auto& s : sparkles) {
        s.update(deltaTime);
    }
    
    auto iterator = remove_if(sparkles.begin(), sparkles.end(), [](Sparkle& s)
                              { return s.outOfBounds(); } );
    sparkles.erase(iterator, sparkles.end());
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    colorImg.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    
    ofNoFill();
    for (int i = 0; i < contourFinder.nBlobs; i++){
        ofxCvBlob& blob = contourFinder.blobs[i];
        vector <ofPoint>& pts = blob.pts;
        
        ofBeginShape();
        for (int j = 0; j < pts.size(); j++){
            ofPoint pt = pts[j] * 4;
            ofVertex(pt);
        }
        ofEndShape();
    }
    
    for (auto& s : sparkles) {
        s.draw();
    }
    
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
