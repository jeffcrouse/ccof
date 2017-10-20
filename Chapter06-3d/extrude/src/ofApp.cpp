#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(24);
    ofBackground(0);
    
    bDrawWireframe = false;
    
    // Load the font
    string filename = "planet_kosmos.ttf";
    int fontSize = 90;
    bool bAntiAliased = false;
    bool bFullCharacterSet = true;
    bool makeContours = true;
    float simplifyAmt = 30; // uses ofPolyline::simplify
    font.loadFont(filename, fontSize, bAntiAliased, bFullCharacterSet, makeContours, simplifyAmt);
    font.setLineHeight(fontSize+10);
    
    
    
    // Get the bounding box of the text
    text = "Creative\nCoding\nParsons";
    bb = font.getStringBoundingBox(text, 0, 0);
    
    
    // Create a bunch of Letter objects
    vector<ofPath> letterPaths = font.getStringAsPoints(text);
    for(int i=0; i<letterPaths.size(); i++)
    {
        Letter l;
        l.setup(letterPaths[i], 40);
        letters.push_back(l);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::black);
    
    ofEnableDepthTest();
    ofPushMatrix();
    {
        ofTranslate((ofGetWidth()/2.0)-(bb.getWidth()/2.0), ofGetHeight()/2.0);
        ofRotateX(ofGetFrameNum() * 3);
        ofTranslate(0, -50);
        
        for(int i=0; i<letters.size(); i++)
        {
            ofSetColor(200, 0, 100);
            letters[i].front.draw();
            
            ofSetColor(50, 100, 100);
            letters[i].back.draw();
            
            if(bDrawWireframe)
            {
                ofSetColor(0);
                letters[i].front.drawWireframe();
                letters[i].back.drawWireframe();
            }
        }
    }
    ofPopMatrix();
    ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='w') {
        bDrawWireframe = !bDrawWireframe;
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
