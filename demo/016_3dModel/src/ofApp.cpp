#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	// use normalised texture coordinates (a float value between 0 and 1) instead of pixel based coordinates
	// this is required by the model we are loading
	ofDisableArbTex();

	// set up lighting
	ofEnableLighting();
	ofSetSmoothLighting(true);			// high-quality lighting
	ofEnableSeparateSpecularLight();	// specular lighting is the bright, shiny spots that appear on smoother surfaces
	light.setPosition(500, 0, 500);

	// allow drawing order to be based on z-value
	ofEnableDepthTest();

	// flip the camera's vertical orientation
	// should generally do this as the default behaivor is counter intuitive
	camera.setVFlip(true);

	// load the model, a collada file
	model.loadModel("astroBoy_walk.dae", true);

	// loop and play animations
	// animations are done in a 3d modeling program
	model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
	model.playAllAnimations();
}

//--------------------------------------------------------------
void ofApp::update(){
	// get the next animation frame from the model
	model.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	
	// start camera
	camera.begin();
		light.enable();

		// move the model down a bit
		// the 3D artist, put the model's origin at his feet
		ofTranslate(0, 275, 0);
				
		/* Draw the model, try different drawing modes (faces, wireframe, vertices).
		   When drawing the vertices, you may want to set the point size.
		   Drawing the vertices is sometimes referred to as a "point cloud".
		   To change the point size, we have to use an OpenGL command "glPointSize".
		   OpenGL is the underlying graphics rendering language of openFrameworks. */

		model.drawFaces();
		
		//model.drawWireframe();

		//glPointSize(5);
		//model.drawVertices();

		light.disable();
	camera.end();
}