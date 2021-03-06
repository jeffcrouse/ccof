#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1024, 768);
    ofSetWindowTitle("flow01");
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    
    cam.initGrabber(640, 480);
    
    //    int width, int height,
    //    double pyramidScale,
    //    int pyramidLevels,
    //    int windowSize,
    //    int iterationsPerLevel,
    //    int expansionArea,
    //    double expansionSigma,
    //    bool flowFeedback,
    //    bool gaussianFiltering
    flowSolver.setup(640, 480, 0.35, 5, 10, 1, 3, 2.25, false, false);
    
    for(int i=0; i < 200; i++) {
        Spinner s;
        s.setup();
        spinners.push_back( s );
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        flowSolver.update(cam);
        for(auto& s : spinners) {
            ofPoint flow = flowSolver.getVelAtPixel(s.pos.x, s.pos.y);
            s.rotVel += flow;
        }
    }

    for(int i=0; i<spinners.size(); i++) {
        spinners[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofScale(2, 2);
    ofSetColor(255, 255, 255);
    cam.draw(0, 0, cam.getWidth(), cam.getHeight());
    
    // width,  height, lineScale, res
    //flowSolver.drawColored(cam.getWidth(), cam.getHeight(), 10, 10);
    
    for(int i=0; i<spinners.size(); i++) {
        spinners[i].draw();
    }
    ofPopMatrix();
    
    
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 20);
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
