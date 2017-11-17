//
//  ThresholdFilter.hpp
//  Control02
//
//  Created by Jeffrey Crouse on 11/5/17.
//

#pragma once
#include "ofMain.h"

#define STRINGIFY(A) #A

class ThresholdFilter {
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
