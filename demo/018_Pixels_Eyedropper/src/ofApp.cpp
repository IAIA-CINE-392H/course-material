#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	//ofSetVerticalSync(true);  // sync to monitor refresh rate
	ofSetFrameRate(30);			// set frame rate manually
	
	// load image
	image.load("IMAGE FILE");
	image.resize(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 255);
	
	// draw image
	image.draw(0, 0, ofGetWidth(), ofGetHeight());

	// get current mouse position
	int mx = ofGetMouseX();
	int my = ofGetMouseY();

	// create mouse position string
	string sMouse = "Mouse Position: " + ofToString(mx) + " " + ofToString(my);

	// draw mouse position string
	ofDrawBitmapString(sMouse, 50, 50);

	// get pixel color under mouse position
	ofColor color = image.getColor(mx, my);

	// create color string
	string sColor = "Pixel Color: " + ofToString(int(color.r)) + " " + ofToString(int(color.g)) +
		" " + ofToString(int(color.b));

	// draw color string
	ofDrawBitmapString(sColor, 50, 100);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	image.resize(w,h);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
	image.load(dragInfo.files[0]);
	image.resize(ofGetWidth(), ofGetHeight());
}
