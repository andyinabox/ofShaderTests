#version 120

varying vec4 normal, light_dir, eye_vec;

uniform sampler2DRect tex0;
varying vec2 texCoordVarying;

void main()
{

	// i'm mainly transforming a flat textured
	// pane right now, so not as concerned about
	// all this lighting stuff

	// vec4 ambient, diffuse, specular;
	// float NdotL, RdotV;
	// vec4 N = normalize(normal);
	// vec4 L = normalize(light_dir);
	// NdotL = dot(N, L);
	// //RdotV = max(dot(R, V), 0.0);
	// gl_FragColor = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
	// if(NdotL > 0.0)
	// {
	// 	ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
	// 	diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;
	// 	specular = gl_FrontMaterial.specular * gl_LightSource[0].specular;
	// 	vec4 E = normalize(eye_vec);
	// 	vec4 R = reflect(-L, N);
	// 	gl_FragColor +=  (NdotL * diffuse) +
	// 			specular * pow(max(dot(R, E), 0.0), gl_FrontMaterial.shininess);
	// }
	
	gl_FragColor = texture2DRect(tex0, texCoordVarying);
}