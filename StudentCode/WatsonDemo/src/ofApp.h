#pragma once

#include "ofMain.h"
#include "sio_client.h"


class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

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
		
        void onTranscript(sio::event &);
        void onEmotion(sio::event &);
    
        string sentence;
        bool bClear=false;
        ofTrueTypeFont font;
        mutex lock;
        sio::client h;
        map<string, double> emotion;
        map<string, double> emotionEased;
        map<string, ofColor> colors;
};
