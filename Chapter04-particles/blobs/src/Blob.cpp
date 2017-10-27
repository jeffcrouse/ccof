//
//  Blob.cpp
//  blobs
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#include "Blob.hpp"

// ---------------------------------------------------------------
void Blob::setup(float x, float y) {
    pos.set(x, y);
    
    int nPoints = ofRandom(50, 200);
    int size = nPoints * .5;
    
    for(int i=0; i<nPoints; i++)
    {
        float theta = ofMap(i, 0, nPoints, 0, TWO_PI);
        float x = cos(theta) * size;
        float y = sin(theta) * size;
 
        baseShape.push_back(ofPoint(x, y));
    }
    
    noiseX.y = ofRandomf();
    noiseY.y = ofRandomf();
    color.setHsb(ofRandom(50, 100), 200, 100);
}

// ---------------------------------------------------------------
void Blob::update() {
    noiseX.x += 0.01;
    noiseY.x += 0.01;
    
    contour.resize(baseShape.size());
    
    
    for(int i=0; i<baseShape.size(); i++)
    {
        float offset = i / (float)baseShape.size();
        float x = ofNoise(noiseX.x + offset, noiseX.y) * 50;
        float y = ofNoise(noiseY.x + offset, noiseY.y) * 50;
        
        contour[i] = baseShape[i];
        contour[i].x += x;
        contour[i].y += y;
    }
}

// ---------------------------------------------------------------
void Blob::draw() {
    ofPushMatrix();
    ofTranslate(pos);
    
    ofSetColor(color);
    ofBeginShape();
    for(int i=0; i<contour.size(); i++)
    {
        ofCurveVertex(contour[i].x, contour[i].y);
    }
    ofEndShape(true);
    
    ofPopMatrix();
}
