//
//  Projectile.cpp
//  encoder
//
//  Created by Jeffrey Crouse on 11/28/17.
//

#include "Projectile.hpp"

// --------------------------------------------------
void Projectile::setup(ofPoint start) {
    pos = start;
    vel.set(0, -400);
}

// --------------------------------------------------
void Projectile::update(float deltaTime) {
    pos += vel * deltaTime;
}

// --------------------------------------------------
void Projectile::draw() {

    
    ofSetColor(255);
    ofDrawRectangle(pos.x - (w/2), pos.y - (h/2), w, h);
    
    ofSetColor(0);
    ofDrawCircle(pos, 2);
}
