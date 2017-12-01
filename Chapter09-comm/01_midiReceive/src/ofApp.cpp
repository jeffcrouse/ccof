#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 800);
    ofSetWindowTitle("midiReceive");
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableSmoothing();

    
    filter.setup();
    
    
    midiIn.listPorts();
    midiIn.openPort();
    midiIn.ignoreTypes(false, false, false);
    midiIn.addListener(this);
    midiIn.setVerbose(true);
}

//--------------------------------------------------------------
bool RemoveIf(const GradientParticle& p) {
    return p.scale < 0.01;
}

//--------------------------------------------------------------
void ofApp::update(){
    for(auto& p: particles) {
        p.update();
    }
    
    auto iterator = remove_if(particles.begin(), particles.end(), RemoveIf);
    particles.erase(iterator, particles.end());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    filter.begin();
    for(auto& p: particles) {
        p.draw();
    }
    filter.end();
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage& msg) {
    
    
    int kick = 60;
    int snare = 62;
    int perc2 = 65;
    int hihat = 72;
    int groove = 69;
    
    GradientParticle p;
    
    if(msg.pitch==kick || msg.pitch==36 || msg.pitch==44) {
        p.setup(msg.velocity);
    }
    if(msg.pitch==snare || msg.pitch==38 || msg.pitch==46) {
        
        p.setup(msg.velocity);
    }
    if(msg.pitch==perc2 || msg.pitch==hihat || msg.pitch==40 || msg.pitch==48) {
        p.setup(msg.velocity);
    }
    
    if(msg.pitch==groove || msg.pitch==42 || msg.pitch==50) {
        p.setup(msg.velocity);
    }
    
    particles.push_back(p);
    
    
    
    stringstream text;
    text << "Received: " << msg.status;
    text << " channel: " << msg.channel;
    text << " pitch: " << msg.pitch;
    text << " velocity: " << msg.velocity;
    ofLogNotice() << text.str();
}

//--------------------------------------------------------------
void ofApp::exit() {
    
    // clean up
    midiIn.closePort();
    midiIn.removeListener(this);
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
