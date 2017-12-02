uniform sampler2DRect tex0;
uniform float time;
                              
float rand(vec2 co){
      return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
  }
                              
void main(void){
    vec2 c = gl_TexCoord[0].st;
    c.x += time;
    float rand = rand( c ) ;
    vec4 noise = vec4( rand, rand, rand, rand );
    gl_FragColor = texture2DRect(tex0, gl_TexCoord[0].st) + noise;
    //gl_FragColor = gl_Color;
}