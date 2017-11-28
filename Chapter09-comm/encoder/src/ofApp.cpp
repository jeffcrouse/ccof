#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    serial.setup(0, 9600);
    
    pos.x = ofGetWidth() / 2.0;
    pos.y = ofGetHeight() - 20;
}


//--------------------------------------------------------------
void ofApp::update(){
    float now = ofGetElapsedTimef();
    float deltaTime = ofGetLastFrameTime();
    
    
    
    while(serial.available()) {
        char b = serial.readByte();
        if(b=='\n') {
            string line = ss.str();
            
            if(line=="Clicked") {
                ofLogNotice() << "Clicked";
                paused = !paused;
            } else if(line=="DoubleClicked") {
                ofLogNotice() << "DoubleClicked";
            } else {
                ofLogNotice() << "Encoder: " << line;
                if(!paused) pos.x += ofToInt(line);
                if(pos.x > ofGetWidth()+radius) pos.x = -radius;
                if(pos.x < -radius) pos.x = ofGetWidth()+radius;
            }
            ss.str("");
        } else {
            ss << b;
        }
    }
    
    if(paused) return;
    
    
    if(now > nextLaser) {
        Projectile p;
        p.setup(pos);
        lasers.push_back(p);
        nextLaser = now + 0.15;
    }
    
    if(now > nextEnemy) {
        float theta =  ofRandomf() * M_TWO_PI;
        float y = 10 + ((int)ofRandom(6) * 10);
        Enemy e;
        e.setup(0, 30, theta);
        enemies.push_back( e );
        nextEnemy = now + 2.0;
    }
    
    for(auto& p: lasers) {
        p.update(deltaTime);
    }
    
    lasers.erase(remove_if(lasers.begin(), lasers.end(), [](const Projectile& p) { return p.pos.y < 0; }), lasers.end());
    
    for(auto& e: enemies) {
        e.update(deltaTime, lasers);
    }
    
    enemies.erase(remove_if(enemies.begin(), enemies.end(), [](const Enemy& e) { return e.alpha < 0; }), enemies.end());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofDrawCircle(pos, 10);
    for(auto& p: lasers) {
        p.draw();
    }

    for(auto& e: enemies) {
        e.draw();
    }

    if(debug) {
        stringstream ss;
        for(auto& p: lasers) {
            ss << p.pos << endl;
        }
        ofDrawBitmapStringHighlight(ss.str(), 10, 20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='d') {
        debug = !debug;
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
