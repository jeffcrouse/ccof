//
//  Star.hpp
//  stars
//
//  Created by Jeffrey Crouse on 9/22/17.
//

#pragma once
#include "ofMain.h"

class Star {
public:
    
    
    void drawMe();
    void updateMe(vector<Star>& balls);
    static void resolveCollision(Star& starA, Star& starB);
    
    float mass;
    int sides;
    float angle;
    vector<ofPoint> contour;
    ofVec2f position;
    ofVec2f velocity;
    float radius;
    float rotate_speed;
    float starishness;
    int r, b, g, a;
    int age;
    
};

