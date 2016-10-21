#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(30);

	// open video camera
	camera.initGrabber(1280, 720);

	// allocate pixel container to store camera's video frame
	pixels.allocate(1280, 720, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
	camera.update();

	// when doing camera or video pixel analysis, use "isFrameNew()" to avoid unnecessary processing
	if (camera.isFrameNew()) {

		// get pixels of current frame
		pixels = camera.getPixels();

		// get dimensions
		int w = pixels.getWidth();
		int h = pixels.getHeight();

		// create variable to store max brightness
		float maxBrightness = 0;

		// loop through all the pixels
		for (int x = 0; x < w; x++) {
			for (int y = 0; y < h; y++) {

				// get pixel color
				ofColor color = pixels.getColor(x, y);

				// get brightness or lightness of color 
				// brightness = highest color value in the red, green, or blue channels
				// lightness = the average of all three color values

				float brightness = color.getBrightness(); // also try: "getLightness()";

				// compare current brightness to max brightness 
				if (brightness > maxBrightness) {

					// update maxBrightness with new value
					maxBrightness = brightness;

					// set brightest point location
					brightestPoint.x = x;
					brightestPoint.y = y;
				}

			}
		}

		// print brightness pixel's color value
		cout << maxBrightness << endl;

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// draw camera's image
	ofSetColor(255);
	camera.draw(0, 0);

	// draw circle around brightness point
	ofNoFill();
	ofSetColor(255, 0, 0);
	ofDrawCircle(brightestPoint, 30);
}