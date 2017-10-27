//
//  Path.hpp
//  path
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once


#include "ofMain.h"

class Path {
public:
    // A Path is an vector of ofPoints
    vector<ofPoint> points;
    
    // A path has a radius, i.e how far is it ok for the boid to wander off
    float radius;
    
    bool debug;
    
    Path();
    void addPoint(float x, float y);
    void draw();
    
    
    static float mag(ofPoint* p) {
        return sqrt(p->x*p->x + p->y*p->y + p->z*p->z);
    }
    
    static ofPoint normalize(ofPoint* p) {
        float m = mag(p);
        if (m != 0 && m != 1) {
            *p/=m;
        }
    }
    
    static float dotproduct(ofPoint a, ofPoint b) {
        return a.x*b.x + a.y*b.y + a.z*b.z;
    }
    
};
