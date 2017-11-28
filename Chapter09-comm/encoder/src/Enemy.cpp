//
//  Enemy.cpp
//  encoder
//
//  Created by Jeffrey Crouse on 11/28/17.
//

#include "Enemy.hpp"

// -----------------------------------------------------
void Enemy::setup(float x, float y, float n) {
    w = 10;
    h = 10;
    pos.set(x, y);
    noiseIndex = n;
}


// -----------------------------------------------------
void Enemy::update() {
    
    bounds.setFromCenter(pos, w, h);
}


// -----------------------------------------------------
void Enemy::draw() {
    ofDrawRectangle(bounds);
}
