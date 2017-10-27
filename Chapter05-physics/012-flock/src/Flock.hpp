//
//  Flock.hpp
//  flock
//
//  Created by Jeffrey Crouse on 10/27/17.
//

#pragma once

#include "ofMain.h"
#include "Boid.hpp"

class Flock {
public:
    Flock();
    void update();
    void draw();
    void addBoid();
    
    vector<Boid*> boids;
};
