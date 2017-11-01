//
//  Ray.cpp
//  RayBounce
//
//  Created by Jeffrey Crouse on 10/30/17.
//

#include "Ray.hpp"

// Returns 1 if the lines intersect, otherwise 0. In addition, if the lines
// intersect the intersection point may be stored in the floats i_x and i_y.
bool get_line_intersection(Obstacle& o, ofPoint p2, ofPoint p3) {
    ofPoint p0 = o.start;
    ofPoint p1 = o.end;
    ofPoint s1 = p1 - p0;
    ofPoint s2 = p3 - p2;
    
    float s, t;
    s = (-s1.y * (p0.x - p2.x) + s1.x * (p0.y - p2.y)) / (-s2.x * s1.y + s1.x * s2.y);
    t = ( s2.x * (p0.y - p2.y) - s2.y * (p0.x - p2.x)) / (-s2.x * s1.y + s1.x * s2.y);
    
    return (s >= 0 && s <= 1 && t >= 0 && t <= 1);
}


// --------------------------------------------------------
void Ray::setup(ofPoint startPos, float _angle) {
    pos = startPos;
    angle = _angle;
    vel = ofRandom(10, 30);
    c.set(0);
}

// --------------------------------------------------------
void Ray::update(vector<Obstacle>& obstacles) {
    
    ofPoint newPos;
    newPos.x = pos.x + cos(ofDegToRad(angle)) * vel;
    newPos.y = pos.y + sin(ofDegToRad(angle)) * vel;
    
    for(int i=0; i<obstacles.size(); i++) {
        ofPoint hit;
        if(get_line_intersection(obstacles[i], pos, newPos)) {
            
            angle = 180 - obstacles[i].angle;
            
            newPos.x = pos.x + cos(ofDegToRad(angle)) * vel;
            newPos.y = pos.y + sin(ofDegToRad(angle)) * vel;
            c.set(255, 0, 0);
        }
    }
    
    pos  = newPos;
}



// --------------------------------------------------------
void Ray::draw() {
    ofSetColor(c);
    ofDrawCircle(pos, 5);
}

// --------------------------------------------------------
bool Ray::isDone() {
    
}
