#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// load and play video
	video.load("VIDEO FILE");
	video.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	// get video frame's pixel container
	pixels = video.getPixels();	
	
	// resize to full screen
	pixels.resize(ofGetWidth(), ofGetHeight());

	// get dimensions
	int w = pixels.getWidth();
	int h = pixels.getHeight();

	// scan horizontal pixel line
	for (int x=0; x<w; x++) {

		// get color from pixel row
		ofColor color = pixels.getColor(x, h/2);

		// draw a vertical line at this color
		ofSetColor(color);
		ofLine(x, 0, x, h); // parameters: first point to second point
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	string file = dragInfo.files[0];
	video.load(file);
	video.play();
}
