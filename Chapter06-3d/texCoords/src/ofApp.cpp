#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableNormalizedTexCoords();
    
    moon.load("moon.jpg");
    mars.load("planet.jpg");
    
    vector<ofVec3f> verts;
    vector<ofVec2f> texCoords;
    
    
    /**
     We are going to populate 2 vectors with points that make up 'nSlices' triangles
     Each time through the for loop, we add 3 points to verts and 3 points to texCoords
     Think of cutting out a slice from the picture for each triangle in the circle
     */
    int nSlices = 30;
    float angle = 0;
    float x, y;
    for(int i=0; i<nSlices; i++)
    {
        // Add a triangle point at the center
        verts.push_back( ofPoint(0, 0) );
        texCoords.push_back( ofPoint(0.5, 0.5) );
        
        
        // Add triangle point at angle
        x = cos(angle);
        y = sin(angle);
        verts.push_back(ofPoint(x, y));
        x = 0.5 + cos(angle) * 0.5;
        y = 0.5 + sin(angle) * 0.5;
        texCoords.push_back(ofPoint(x, y));
        
        
        // increment the angle
        angle += (M_TWO_PI / (float)nSlices);
        
        
        // Add the third point of the triangle
        x = cos(angle);
        y = sin(angle);
        verts.push_back(ofPoint(x, y));
        x = 0.5 + cos(angle) * 0.5;
        y = 0.5 + sin(angle) * 0.5;
        texCoords.push_back(ofPoint(x, y));
    }
    
    
    unitCircleWithTexCoords.addVertices(verts);
    unitCircleWithTexCoords.addTexCoords(texCoords);
}

//--------------------------------------------------------------
void ofApp::update(){
    moonPos.x = (ofGetWidth()/2.0) + cos(ofGetFrameNum()/20.0) * 400;
    moonPos.y = (ofGetHeight()/2.0) + sin(ofGetFrameNum()/20.0) * 300;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::black);
    ofSetColor(255);
    
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    ofScale(200, 200);
    mars.bind();
    unitCircleWithTexCoords.draw();
    mars.unbind();
    if(bDrawWireframe) unitCircleWithTexCoords.drawWireframe();
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofTranslate(moonPos);
    ofScale(80, 80);
    moon.bind();
    unitCircleWithTexCoords.draw();
    moon.unbind();
    if(bDrawWireframe) unitCircleWithTexCoords.drawWireframe();
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    bDrawWireframe = !bDrawWireframe;
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
