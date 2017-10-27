//
//  ParticleSystem.hpp
//  fountain
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Repeller.hpp"

class ParticleSystem {
public:
    ParticleSystem();
    
    void applyForce(ofPoint force);
    void applyRepeller(Repeller r);
    void update();
    void draw();
    void addParticle(float x, float y);
    bool dead();
    
    vector<Particle> particles;
    ofPoint origin;
    
    
};
