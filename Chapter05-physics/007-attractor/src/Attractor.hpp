//
//  Attractor.hpp
//  attractor
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once

#include "ofMain.h"
#include "Thing.hpp"

class Attractor {
public:
    Attractor();
    
    ofPoint calcGravForce(Thing t);
    void draw();
    void clicked(int x, int y);
    void rollover(int x, int y);
    void stopDragging();
    void drag(int x, int y);
    
    float mass;    // Mass, tied to size
    float G;       // Gravitational Constant
    ofPoint loc;   // Location
    bool bDragging; // Is the object being dragged?
    bool bRollover; // Is the mouse over the ellipse?
    ofPoint dragoff;  // holds the offset for when object is clicked on
    
    
};
