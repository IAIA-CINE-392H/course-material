#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);				// set background to black
	ofEnableLighting();				// enable lighting 
	ofEnableDepthTest();			// allow drawing order to be based on z-value
	light.setPosition(0, 0, 500);	// set the position of the light
	camera.setVFlip(true);			// flip the camera's vertical orientation
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	// capture scene with camera - places origin in the center
	camera.begin();
		light.enable();

		// 3d grid layout
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				for (int z = 0; z < 10; z++) {
					
					// change color based on x,y,z values
					ofSetColor(x * 20, y * 20, z * 20);
					
					// create transform matrix
					ofPushMatrix();						
					
					// create random numbers to animate the spheres
					float randX = ofRandom(-1.0, 1.0);
					float randY = ofRandom(-1.0, 1.0);
					float randZ = ofRandom(-1.0, 1.0);

					// position the spheres
					// multiply x,y,z by 50 for padding
					// add random animation
					ofTranslate(x * 50 + randX, y * 50 + randY, z * 50 + randZ);

					// draw spheres
					sphere.drawWireframe();
					
					// remove transform matrix (resets transformations)
					ofPopMatrix();						
				}
			}
		}
		
		light.disable();
	camera.end();
}