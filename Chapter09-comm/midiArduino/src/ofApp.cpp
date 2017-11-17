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
    
    
    serial.setup(0, 9600); //open the first device
    
    lights[0].setup('a', 'e', 0, serial);
    lights[1].setup('b', 'f', 0.25, serial);
    lights[2].setup('c', 'g', 0.5, serial);
    lights[3].setup('d', 'h', 0.75, serial);
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
    for(int i=0; i<4; i++) {
        lights[i].update();
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
    
    if(msg.pitch==kick) {
        if(msg.status==144) lights[0].on(msg.velocity);
        if(msg.status==128) lights[0].off();
        
        p.setup(msg.velocity);
    }
    if(msg.pitch==snare) {
        if(msg.status==144) lights[1].on(msg.velocity);
        if(msg.status==128) lights[1].off();
        
        p.setup(msg.velocity);
    }
    if(msg.pitch==perc2 || msg.pitch==hihat) {
        if(msg.status==144) lights[2].on(msg.velocity);
        if(msg.status==128) lights[2].off();
        
        p.setup(msg.velocity);
    }
    
    if(msg.pitch==groove) {
        if(msg.status==144) lights[3].blink(0.05, msg.velocity);
        if(msg.status==128) lights[3].stop();
        
        
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
