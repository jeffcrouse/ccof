//
//  Repeller.hpp
//  repel
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once
#include "Particle.hpp"

class Repeller {
public:
    Repeller();
    void draw();
    
    void pushParticle(Particle* p);
    void clicked(int x, int y);
    void rollover(int x, int y);
    void stopDragging();
    void drag(int x, int y);
    
    float g;
    ofPoint loc;
    ofPoint oldloc;
    bool bDragging;
    bool bRollover;
    float r;
    
    
};

