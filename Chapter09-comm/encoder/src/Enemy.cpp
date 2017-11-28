//
//  Enemy.cpp
//  encoder
//
//  Created by Jeffrey Crouse on 11/28/17.
//

#include "Enemy.hpp"

// -----------------------------------------------------
void Enemy::setup(float x, float y, float t) {
    w = 20;
    h = 10;
    pos.set(x, y);
    theta = t;
}


// -----------------------------------------------------
void Enemy::update(float deltaTime, vector<Projectile>& projectiles) {
    if(dead) {
        alpha -= deltaTime * 300.0;
        explosion += deltaTime * 300.0;
    } else {
        pos.x = ofMap(cos(theta), -1, 1, 10, ofGetWidth()-10);
        theta += deltaTime / 2.0;
        bounds.setFromCenter(pos, w, h);
        
        for(auto& p : projectiles) {
            float dist = pos.distance(p.pos);
            if(dist < 10) dead = true;
        }
    }
}


// -----------------------------------------------------
void Enemy::draw() {
    ofSetColor(255, alpha);
    if(dead) {
        ofDrawCircle(pos, explosion);
    } else {
        ofDrawRectangle(bounds);
    }
}
