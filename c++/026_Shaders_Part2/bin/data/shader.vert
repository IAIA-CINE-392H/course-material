#version 150

// these are for the programmable pipeline system and are passed in
// by default from OpenFrameworks
uniform mat4 modelViewMatrix;           // model and view transform
uniform mat4 projectionMatrix;          // camera projection transform
uniform mat4 textureMatrix;             // texture transform
uniform mat4 modelViewProjectionMatrix; // combination transform

in vec4 position;       // vertex position
in vec4 color;          // vertex color
in vec4 normal;         // vertex normal
in vec2 texcoord;       // texture coordinates (u,v)
// this is the end of the default functionality

out vec2 varyingtexcoord;

uniform float time;

void main()
{
	// texure coordinates
    //varyingtexcoord =  vec2(texcoord.x, texcoord.y);
    
    vec4 texc = textureMatrix * vec4(texcoord.x,texcoord.y,0,1);
	varyingtexcoord = texc.xy;

	// vertex coordinates
    float dx = sin(time + (position.x / 100.0)) * 100;
    float dy = cos(time + (position.y / 100.0)) * 100;

    vec4 vertex = modelViewProjectionMatrix * position;
    vertex.x += dx;
   	vertex.y += dy;

    gl_Position = vertex;
}

