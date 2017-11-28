//
//  Enemy.hpp
//  encoder
//
//  Created by Jeffrey Crouse on 11/28/17.
//

#pragma once
#include "ofMain.h"
#include "Projectile.hpp"


class Enemy {
public:
    void setup(float x, float y, float t);
    void update(float deltaTime, vector<Projectile>& projectiles);
    void draw();
    
    ofRectangle bounds;
    ofPoint pos;
    float w;
    float h;
    float theta;
    bool dead = false;
    float alpha = 255;
    float explosion = 0;
};
