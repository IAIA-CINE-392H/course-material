#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(30);
	ofEnableAlphaBlending();

	// load image
	image.load("IMAGE FILE");
	image.resize(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	// if image is not allocated then return
	if (image.isAllocated() == false) {
		return;
	}

	// get image dimensions
	int w = image.getWidth();
	int h = image.getHeight();

	// draw 50,000 circles
	for (int i = 0; i < 50000; i++) {

		// get random position
		int x = ofRandom(w-1);
		int y = ofRandom(h-1);

		// get image color at radom position
		ofColor color = image.getColor(x,y);

		// set color with alpha
		ofSetColor(color.r, color.g, color.b, 125);

		// draw circles with radius of 5 
		ofDrawCircle(x, y, 5);
	}
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	image.resize(w, h);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
	image.load(dragInfo.files[0]);
	image.resize(ofGetWidth(), ofGetHeight());
}
