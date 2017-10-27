//
//  ParticleSystem.hpp
//  repel
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
    void applyRepellers(vector<Repeller*> repellers);
    void update();
    void draw();
    void addParticle();
    bool dead();
    
    vector<Particle> particles;
    ofPoint origin;
    
    
};
