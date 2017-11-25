#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Watson Demo");
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetDataPathRoot("../Resources/data/");
    
    colors["anger"] = ofColor::red;
    colors["disgust"] = ofColor::greenYellow;
    colors["fear"] = ofColor::lightYellow;
    colors["joy"] = ofColor::mediumPurple;
    colors["sadness"] = ofColor::blue;
    
    h.set_open_listener([]{
        ofLogNotice() << "open_listener";
    });
    h.set_close_listener([](sio::client::close_reason const& reason){
        ofLogNotice() << "close_listener";
    });
    h.set_fail_listener([]{
        ofLogNotice() << "fail_listener";
    });
    
    h.connect("http://127.0.0.1:3000");
    h.socket()->on("transcript", bind(&ofApp::onTranscript, this, std::placeholders::_1));
    h.socket()->on("emotion", bind(&ofApp::onEmotion, this, std::placeholders::_1));
    
    font.load("NewMedia Fett.ttf", 24);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (auto& emo : emotion) {
        string e = emo.first;
        
        if(emotionEased.find(e)==emotionEased.end()) {
            emotionEased[e]=0;
        }
        
        emotionEased[e] += (emotion[e]-emotionEased[e]) * 0.01;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    font.drawString(sentence, 20, 120);
    
    float x = 0;
    float y = 100;
    float height = 40;
    for (auto& emo : emotionEased) {
        string e = emo.first;
        float width = ofMap(emo.second, 0, 1, 0, ofGetWidth(), true);
        ofSetColor( colors[e] );
        ofDrawRectangle(x, y, width, height);
        y += height + 10;
    }
}


// -----------------------------------------------------------------------
void ofApp::onTranscript(sio::event &ev) {
    
    sio::message::list messages = ev.get_messages();
    if(messages.size() < 2) {
        ofLogWarning() << "expecting 2 messages";
        return;
    }
    if(messages[0]->get_flag() != sio::message::flag_string) {
        ofLogWarning() << "unrecognized message";
        return;
    }
    if(messages[1]->get_flag() != sio::message::flag_boolean) {
        ofLogWarning() << "unrecognized message";
        return;
    }
    
    if(bClear) {
        sentence = "";
        bClear = false;
    }
    
    string transcript = messages[0]->get_string();
    bool isFinal = messages[1]->get_bool();
    
    lock.lock();
    sentence = transcript;
    bClear = isFinal;
    lock.unlock();
}

// -----------------------------------------------------------------------
void ofApp::onEmotion(sio::event &ev) {
    sio::message::ptr msg = ev.get_message();
    if(msg->get_flag() != sio::message::flag_object) {
        ofLogWarning() << "unrecognized message";
        return;
    }
    
    lock.lock();
    map<string, sio::message::ptr> map = msg->get_map();
    for (auto& emo : map) {
        ofLogNotice() << emo.first << ": " << emo.second->get_double();
        emotion[emo.first] = emo.second->get_double();
    }
    lock.unlock();
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
