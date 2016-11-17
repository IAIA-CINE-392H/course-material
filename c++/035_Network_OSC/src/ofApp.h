#pragma once

#include "ofMain.h"
#include "ofxGpuParticles.h"
#include "ofxOsc.h"

#define _PROGRAMMABLE_RENDERER
#define PORT 12345

class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

private:
    // set any update uniforms in this function
    void onParticlesUpdate(ofShader& shader);
    
    ofxGpuParticles particles;
    ofEasyCam cam;
	ofxOscReceiver receiver;

	float px, py;
};
