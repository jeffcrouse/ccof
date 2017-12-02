#include "ofApp.h"

#define STRINGIFY(A) #A


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 960);
    ofSetWindowTitle("bokeh");
    ofSetFrameRate(60);
    ofBackground(100);
    
    cam.setup(640, 480);
    
    string fragmentShader = STRINGIFY(
        uniform sampler2DRect tex;
        uniform float max_radius;

        void main(void) {
          vec4 finalColor = vec4(0.0,0.0,0.0,1.0);
          float weight = 0.;
          int radius = int(max_radius);
          for(int x=radius*-1;x<radius;x++) {
              for(int y=radius*-1;y<radius;y++){
                  vec2 coord = gl_TexCoord[0].xy+vec2(x,y);
                  if(distance(coord, gl_TexCoord[0].xy) < float(radius)){
                      vec4 texel = texture2DRect(tex, coord);
                      float w = length(texel.rgb)+0.1;
                      weight+=w;
                      finalColor += texel*w;
                  }
              }
          }
          gl_FragColor = finalColor/weight;
        }
    );
    
    bokeh.unload();
    bokeh.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShader);
    bokeh.linkProgram();
    
    doShader=true;
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    float r = ofMap(mouseX, 0, ofGetWidth(), 0, 20);
    
    if(doShader) {
        bokeh.begin();
        bokeh.setUniformTexture("tex", cam, 0);
        bokeh.setUniform1f("max_radius", r);
    }
    cam.draw(0, 0, 1024, 768);
    if(doShader) {
        bokeh.end();
    }
    
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='s') {
        doShader=!doShader;
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
