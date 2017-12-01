//
//  Light.cpp
//  Control02
//
//  Created by Jeffrey Crouse on 11/4/17.
//

#include "Light.hpp"

// ---------------------------------------------------------
void Light::setup(char _onCommand, char _offCommand, float _pos, ofSerial& _serial) {
    onCommand = _onCommand;
    offCommand = _offCommand;
    pos = _pos;
    serial = _serial;
}

// ---------------------------------------------------------
void Light::update() {
    bounds.x = ofGetWidth() * pos;
    bounds.y = 0;
    bounds.width = ofGetWidth() * .25;
    bounds.height = ofGetHeight();
    
    float now = ofGetElapsedTimef();
    if(bBlink && now > nextBlink) {
        toggle();
        nextBlink = now + (freq/2.0);
    }
}


// ---------------------------------------------------------
void Light::draw() {
    if(bOn) {
        ofSetColor(255, alpha);
        ofDrawRectangle(bounds);
    }
}

// ---------------------------------------------------------
void Light::blink(float _freq, float val) {
    freq = _freq;
    bBlink = true;
    float now = ofGetElapsedTimef();
    nextBlink = now + (freq/2.0);
}

// ---------------------------------------------------------
void Light::stop() {
    bBlink = false;
    off();
}

// ---------------------------------------------------------
void Light::on(int val=255) {
    alpha = ofMap(val, 0, 128, 0, 100);
    bOn = true;
    serial.writeByte(onCommand);
}

// ---------------------------------------------------------
void Light::off() {
    bOn = false;
    serial.writeByte(offCommand);
}

// ---------------------------------------------------------
void Light::toggle() {
    if(bOn) off();
    else on();
}
