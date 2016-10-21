#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class ofApp : public ofBaseApp{

	public:

		/* 3d model loader - works with collada files.
		   This is an "addon" or extension of openFrameworks.
		   Use the addon dropdown menu in the project generator to include it. */
		ofxAssimpModelLoader model;	
		
		// camera and light
		ofEasyCam camera;
		ofLight	light;

		void setup();
		void update();
		void draw();		
};
