//
//  MetaBallFilter.hpp
//  MetaBalls
//
//  Created by Jeffrey Crouse on 10/31/17.
//

#pragma once
#include "ofMain.h"

#define STRINGIFY(A) #A

class MetaBallFilter {
public:
    
    bool setup();
    void begin();
    void end();
    
private:
    ofFbo renderTex;
    ofFbo metaballTex;
    ofFbo realMetaballTex;
    ofShader shader;
    
    float threshold;
};
