#pragma once

#include "ofMain.h"

#define MODE_ANGLE 0
#define MODE_RADIUS 1
#define MODE_SIZE 2


class ofApp : public ofBaseApp{

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
		
        ofSerial serial;
        stringstream ss;
    
        ofColor color;
        float size = 20;
        float radius = 400;
        float angle = 0;
        int mode = MODE_ANGLE;
};
