#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
 
    for(int i=0; i<10; i++) {
        Thing t;
        things.push_back( t );
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < things.size(); i++) {          // For every Thing t[i]
        
        // Thing 1 = things[i]
        
        for(int j = 0; j < things.size(); j++)
        {
            if (i != j)
            {                                                    // Make sure we are not calculating gravtional pull on oneself
                ofPoint f = things[i].calcGravForce(&things[j]);   // Use the function we wrote above
                things[i].applyForce(f);                     // Add the force to the object to affect its acceleration
            }
        }
        
        
        things[i].update();                             // Implement the rest of the object's functionality
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<things.size(); i++) {
        things[i].draw();
    }
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
