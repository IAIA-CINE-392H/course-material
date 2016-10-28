// fragment shader
#version 150

// this is how we receive the texture
uniform sampler2D tex0;
uniform sampler2D tex1;

in vec2 varyingtexcoord;
out vec4 outputColor;

uniform float mixAmount;

void main()
{
    vec4 texel0 = texture(tex0, varyingtexcoord);
    vec4 texel1 = texture(tex1, varyingtexcoord);
    
    // mix textures
    vec4 m = mix(texel0, texel1, mixAmount);
    outputColor = m;

    // standard output
    //outputColor = texture(tex0, varyingtexcoord);
}