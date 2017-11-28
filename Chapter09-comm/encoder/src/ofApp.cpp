#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    serial.setup(0, 9600);
    
    pos.x = ofGetWidth() / 2.0;
    pos.y = ofGetHeight() - 20;
}


//--------------------------------------------------------------
void ofApp::update(){
    
    while(serial.available()) {
        char b = serial.readByte();
        if(b=='\n') {
            string line = ss.str();
            
            if(line=="Clicked") {
                ofLogNotice() << "Clicked";
            } else if(line=="DoubleClicked") {
                ofLogNotice() << "DoubleClicked";
            } else {
                ofLogNotice() << "Encoder: " << line;
                pos.x += ofToInt(line);
                if(pos.x > ofGetWidth()+radius) pos.x = -radius;
                if(pos.x < -radius) pos.x = ofGetWidth()+radius;
            }
            ss.str("");
        } else {
            ss << b;
        }
    }
    
    float now = ofGetElapsedTimef();
    if(now > nextLaser) {
        Projectile p;
        p.setup(pos);
        lasers.push_back(p);
        nextLaser = now + 0.5;
    }
    
    float deltaTime = ofGetLastFrameTime();
    for(auto& p: lasers) {
        p.update(deltaTime);
    }
    
    auto removeif = [](const Projectile& p) { return p.pos.y < 0; };
    auto iterator = remove_if(lasers.begin(), lasers.end(), removeif);
    lasers.erase(iterator, lasers.end());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(pos, 10);
    for(auto& p: lasers) {
        p.draw();
    }

    stringstream ss;
    for(auto& p: lasers) {
        ss << p.pos << endl;
    }
    ofDrawBitmapStringHighlight(ss.str(), 10, 20);
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
