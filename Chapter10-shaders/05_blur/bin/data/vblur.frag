uniform sampler2DRect src_tex_unit0;
uniform float amt;
                                      
void main(void) {
    vec2 st = gl_TexCoord[0].st;
    vec4 color;
    color += 1.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 4.0));
    color += 2.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 3.0));
    color += 3.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 2.0));
    color += 4.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * 1.0));
    color += 5.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt) );
    color += 4.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -1.0));
    color += 3.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -2.0));
    color += 2.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -3.0));
    color += 1.0 * texture2DRect(src_tex_unit0, st + vec2(0.0, amt * -4.0));
    color /= 25.0;
    gl_FragColor = color;
}