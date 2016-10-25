// fragment shader
#version 150

uniform sampler2D tex0;     // this is how we receive the texture

in vec2 varyingtexcoord;    // input from the vertex shader
out vec4 outputColor;       // output for the color

void main()
{
    // texture coordinates from vertex shader
    vec4 texel0 = texture(tex0, varyingtexcoord);
    
    // output texel color
    outputColor = texel0;
}