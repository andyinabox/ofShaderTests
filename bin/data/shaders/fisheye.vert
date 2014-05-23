#version 120

// varying means we can pass it through
// and manipulate it at different shader
// steps?
varying vec4 normal, light_dir, eye_vec, lookat;
varying vec2 texCoordVarying;

// hey, this isn't used either!
// const float PI =  3.14159265;

void main()
{
	// do i really need these? 
	// vec4 ambient, diffuse, specular;

	// wait, these aren't even used?
	// float NdotL, RdotV;

	// getting the normal vector? 
	normal = vec4(gl_NormalMatrix * gl_Normal, 0.0);
	
	// ok what's this? a vector from the center of the 
	// entire matrix to the current vertex?
	vec4 vVertex = gl_ModelViewMatrix * gl_Vertex;

	// i don't think i will need this
	light_dir = gl_LightSource[0].position - vVertex;
	
	// eye vector i guess, duh.
	eye_vec = -vVertex;

	// ah, ok so we're cloning the default position
	// for this vector
	vec4 temp_pos = ftransform();
	
	// so we want the distance from this
	// vector to the camera eye?
	float dist = length(eye_vec);

	// a vector looking at the current vertex?
	lookat = eye_vec - temp_pos;

	// ?
	vec4 dir = temp_pos - eye_vec;
	
	// ?
	vec4 center = normalize(-eye_vec);
	
	// ah ok so we are creating a projection
	vec4 proj = dot(temp_pos, normalize(-lookat)) * normalize(-lookat);
	
	// ?
	vec4 c = temp_pos - proj;
	
	// guessing this is the magnitude of our
	// fisheye effect
	float magnitude = .01;//1-acos(dot(normalize(-eye_vec), normalize(temp_pos)));

	// ?
	c = length(c) * magnitude * normalize(c);

	// ?
	vec4 dir2 = normalize(c-lookat);
	
	// ?
	dir2 = (dir2 * dist);
	
	// so obviously dir2 is where our final coords are coming from
	gl_Position.xyz = dir2.xyz;

	// still don't totally understand what the "w" is but
	// there's a reference here:
	// http://andrewharvey4.wordpress.com/2008/09/29/xyzw-in-opengldirect3d-homogeneous-coordinates/
	// obv we're not doing anythin with it
	gl_Position.w = ftransform().w;

	// -------
	// this stuff is copied from anothe example to try and get
	// my texture in there
	
	// thinking there might be something different I need
	// to do here
    vec2 texcoord = gl_MultiTexCoord0.xy;

    // here we move the texture coordinates
    texCoordVarying = texcoord;
}