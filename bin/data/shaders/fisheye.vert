#version 120

varying vec2 texCoordVarying;

uniform float time;
uniform float percentY;
uniform float percentX;


void main()
{

	gl_Position = ftransform();

    texCoordVarying = gl_MultiTexCoord0.xy;
}