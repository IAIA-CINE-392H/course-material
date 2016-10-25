#version 150

// these are for the programmable pipeline system and are passed in
// by default from OpenFrameworks
uniform mat4 modelViewMatrix;           // model and view transforms
uniform mat4 projectionMatrix;          // camera projection transform
uniform mat4 textureMatrix;             // texture transform
uniform mat4 modelViewProjectionMatrix; // combination transform

in vec4 position;       // vertex position
in vec4 color;          // vertex color
in vec4 normal;         // vertex normal
in vec2 texcoord;       // texture coordinates (u,v)
// this is the end of the default functionality

// output texture corodinates to fragment shader
out vec2 varyingtexcoord;

void main()
{
	// texure coordinates
    varyingtexcoord = vec2(texcoord.x, texcoord.y);

    // vertex coordinates
    vec4 vertex = modelViewProjectionMatrix * position;

    // output vertex coordinates
    gl_Position = vertex;
}