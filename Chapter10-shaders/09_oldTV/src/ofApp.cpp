#include "ofApp.h"
#define STRINGIFY(A) #A


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("oldTV");
    ofSetFrameRate(60);
    ofBackground(100);
    
    cam.initGrabber(640, 480);
    
    string fragmentShader = STRINGIFY(
        uniform float time;
        uniform sampler2DRect tex0;

        uniform float brightness;
        uniform float rows;

        void main(void){
            vec2 st = gl_TexCoord[0].st;
            vec2 uv = 0.5 + (1.0/st-0.5)*( (1.0-brightness) + brightness*sin(0.2*time) );

            vec3 col;

            col.r = texture2DRect(tex0, vec2(st.x+0.003,st.y)).r;
            col.g = texture2DRect(tex0, vec2(st.x+0.000,st.y)).g;
            col.b = texture2DRect(tex0, vec2(st.x-0.003,st.y)).b;

            col = clamp(col * 0.5 + 0.5 * col * col * 1.2,0.0,1.0);

            col *= 0.5 + 0.5 * 16.0 * uv.x * uv.y * (1.0-uv.x) * (1.0-uv.y);

            col *= vec3(0.8,1.0,0.7);

            col *= 0.9 + 0.1 * sin(10.0 * time + st.y * rows);

            col *= 0.97 + 0.03 * sin(110.0 * time);

            gl_FragColor = vec4(col,1.0);
        }
    );
    
    oldTV.unload();
    oldTV.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShader);
    oldTV.linkProgram();
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    float brightness = ofMap(mouseY, 0, ofGetHeight(), 1, 0);
    float rows = ofMap(mouseX, 0, ofGetWidth(), 5, 15);
    
    oldTV.begin();
    oldTV.setUniform1f("time", ofGetElapsedTimef());
    oldTV.setUniform1f("brightness", brightness);
    oldTV.setUniform1f("rows", rows);
    cam.draw(0, 0, 1024, 768);
    oldTV.end();
    
    
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 20);
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
