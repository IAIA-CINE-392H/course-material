#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(30);
	ofEnableAlphaBlending();

	// load image
	image.load("IMAGE FILE");
	image.resize(ofGetWidth(), ofGetHeight());

	// allocate texture
	texture.allocate(image.getPixels());
}

//--------------------------------------------------------------
void ofApp::update(){
	// if image is not allocated then return
	if (image.isAllocated() == false) {
		return;
	}

	// get image pixels
	pixels = image.getPixels();

	// get dimensions
	int w = pixels.getWidth();
	int h = pixels.getHeight();

	// loop through every pixel
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {

			// get color of pixel
			ofColor color = pixels.getColor(x, y);

			/* do pixel processing here */
			
			// 1. Set color values directly
			// color.r = 0;
			// color.g = 90;
			// color.b = 125;

			// 2. Swap color channels
			// color.r = color.b;
			// color.g = color.g;
			// color.b = color.r;

			// 3. Invert color values
			// color = color.getInverted();

			// 4. Invert color values using ofMap
			// color.r = ofMap(color.r, 0, 255, 255, 0);
			// color.g = ofMap(color.g, 0, 255, 255, 0);
			// color.b = ofMap(color.b, 0, 255, 255, 0);

			// 5. Set input and output (Photoshop's Levels)
			//color.r = ofMap(color.r, 0, 255, 50, 175);
			//color.g = ofMap(color.g, 0, 255, 50, 175);
			//color.b = ofMap(color.b, 0, 255, 50, 175);

			// 6. Create two color image based on brightness
			float brightness = color.getBrightness();

			if (brightness > 127) {
				color.r = 0;
				color.g = 90;
				color.b = 125;
			} 
			else {
				color.r = 150;
				color.g = 12;
				color.b = 0;
			}

			// update pixel with new color values
			pixels.setColor(x, y, color);
		}
	}

	// load pixel to texture
	texture.loadData(pixels);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255);
	texture.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	image.resize(w, h);
	texture.allocate(image.getPixels());
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
	image.load(dragInfo.files[0]);
	image.resize(ofGetWidth(), ofGetHeight());
	texture.allocate(image.getPixels());
}
