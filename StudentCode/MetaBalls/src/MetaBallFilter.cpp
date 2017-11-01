//
//  MetaBallFilter.cpp
//  MetaBalls
//
//  Created by Jeffrey Crouse on 10/31/17.
//

#include "MetaBallFilter.hpp"

// ----------------------------------------------------------------------
bool MetaBallFilter::setup(){
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    renderTex.allocate(w ,h, GL_RGBA);
    metaballTex.allocate(w, h, GL_RGBA);
    realMetaballTex.allocate(w, h, GL_RGBA, 8);
    
    threshold = 0.50;

    string fragmentShader = STRINGIFY(
        uniform sampler2DRect texture;
        uniform float red;
        uniform float green;
        uniform float blue;

        void main() {
            vec4 tex = texture2DRect ( texture, gl_TexCoord[0].st );
            if (tex.r + tex.g + tex.b != 3.0) {
                tex.r = red;
                tex.g = green;
                tex.b = blue;
            }
            gl_FragColor = vec4(tex.r , tex.g, tex.b, 1.0);
        }
    );
    
    string vertexShader = STRINGIFY(
        void main(){
            gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
            gl_PointSize = 0.0;
            gl_TexCoord[0] = gl_MultiTexCoord0;
            gl_FrontColor = gl_Color;
        }
    );
    
    shader.unload();
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragmentShader);
    shader.setupShaderFromSource(GL_VERTEX_SHADER, vertexShader);
    if(ofIsGLProgrammableRenderer()){
        shader.bindDefaults();
    }
    return shader.linkProgram();
}

// ----------------------------------------------------------------------
void MetaBallFilter::begin(){
    renderTex.begin();
    ofClear(0,0,0);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glEnable(GL_BLEND);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
}

// ----------------------------------------------------------------------
void MetaBallFilter::end(){
    glPopAttrib();
    renderTex.end();
    
    metaballTex.begin();
    
    ofClear(255);
    ofPushStyle();
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, threshold);
    ofSetColor(0);
    renderTex.draw(0,0);
    glDisable(GL_ALPHA_TEST);
    ofPopStyle();
    
    metaballTex.end();
    
    realMetaballTex.begin();
    ofTexture &t = metaballTex.getTextureReference();
    
    t.bind();
    shader.begin();
    
    shader.setUniform1f("red", 0);
    shader.setUniform1f("green", 0);
    shader.setUniform1f("blue", 0);
    
    t.draw(0, 0);
    shader.end();
    t.unbind();
    realMetaballTex.end();
    
    realMetaballTex.draw(0, 0);
}
