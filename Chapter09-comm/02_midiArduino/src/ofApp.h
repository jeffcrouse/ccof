#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "GradientParticle.hpp"
#include "ThresholdFilter.hpp"
#include "Light.hpp"


class ofApp : public ofBaseApp, public ofxMidiListener {

	public:
		void setup();
		void update();
		void draw();
        void exit();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void newMidiMessage(ofxMidiMessage& eventArgs);
    
        
        ofxMidiIn midiIn;
        vector<GradientParticle> particles;
        ThresholdFilter filter;
        ofSerial serial;
        Light lights[4];
};
