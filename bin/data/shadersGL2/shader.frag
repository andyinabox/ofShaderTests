#version 120

uniform sampler2DRect tex0;

varying vec2 texCoordVarying;

void main()
{
    vec4 txt = texture2DRect(tex0, texCoordVarying);
    
    vec4 color = vec4(txt.b, txt.r, txt.g, 255);
    
    gl_FragColor = color;
}