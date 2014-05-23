#version 120

uniform sampler2DRect tex0;
uniform float percentY;

varying vec2 texCoordVarying;

void main()
{
    vec4 txt = texture2DRect(tex0, texCoordVarying);
    
    float r = txt.r - (percentY*txt.r);
    float g = (percentY*txt.g);
    float b = txt.b;
    vec4 color = vec4(r, g, b, 255);
    
    gl_FragColor = color;
}