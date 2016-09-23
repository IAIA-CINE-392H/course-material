#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableLighting();				// enable lighting 
	ofEnableDepthTest();			// allow drawing order to be based on z-value
	light.setPosition(0, 0, 500);	// set the position of the light
}

//--------------------------------------------------------------
void ofApp::update(){
	ry++;  	// add one to rotation variable
}

//--------------------------------------------------------------
void ofApp::draw(){
	// start lighting
	light.enable(); 

	// transform functions (translate, rotate, scale)
	// the order you apply will create different results
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);	// position
	ofRotateY(ry);										// turn
	ofScale(2, 2, 2);									// size

	// draw a sphere using the global function
	ofDrawSphere(0, 0, 0, 100);

	// transformations are relative until you reset them
	ofTranslate(100, 100);

	// draw a box using the global function
	ofDrawBox(0, 0, 0, 100, 100, 100);

	// end lighting
	light.disable();

	// transformations are reset after every frame
}