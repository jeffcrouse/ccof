//
//  Light.hpp
//  Control02
//
//  Created by Jeffrey Crouse on 11/4/17.
//

#pragma once
#include "ofMain.h"


class Light {
public:
    void setup(char _onCommand, char _offCommand, float _pos, ofSerial& _serial);
    void update();
    void draw();
    void blink(float _freq, float val);
    void stop();
    void on(int vel);
    void off();
    void toggle();
    
    
    float alpha;
    float freq;
    bool bOn = false;
    bool bBlink = false;
    ofSerial serial;
    ofRectangle bounds;
    float pos;
    char onCommand;
    char offCommand;
    
    float nextBlink;
};
