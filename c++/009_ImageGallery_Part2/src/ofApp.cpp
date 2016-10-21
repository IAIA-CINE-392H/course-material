#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	i = 0; // default index for the image

	// list of image files
	imageFiles[0] = "MC_Kleiner_Panda.jpg";
	imageFiles[1] = "Iberian_Wolf_AdF_001.jpg";
	imageFiles[2] = "Jaguar_(Panthera_onca_palustris)_male_Rio_Negro_2.jpg";

	// load default image
	image.load(imageFiles[i]);

	// load arrow graphics
	rightArrow.load("right-arrow.png");
	leftArrow.load("left-arrow.png");

	// load font
	font.load("OpenSans-Regular.ttf", 25);

	// list of image titles, must be same order as image files
	titles[0] = "Red Panda";
	titles[1] = "Iberian Wolf";
	titles[2] = "Jaguar";
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// black background
	ofBackground(0, 0, 0);
	
	// relative positioning
	
	// image layout
	int h = ofGetHeight();								 // set to window height
	int w = image.getWidth() * h / image.getHeight();	 // maintain image proportion
	int x = ofGetWidth() * 0.5 - w * 0.5;				 // center image horizontally
	int y = ofGetHeight() * 0.5 - h * 0.5;				 // center image vertically
	image.draw(x, y, w, h);

	// left arrow layout
	w = leftArrow.getWidth();
	h = leftArrow.getHeight();
	x = 0;
	y = ofGetHeight() / 2;
	leftArrow.draw(x, y, w, h);	

	// right arrow layout
	w = rightArrow.getWidth();
	h = rightArrow.getHeight();
	x = ofGetWidth() - w;
	y = ofGetHeight() / 2;
	rightArrow.draw(x, y, w, h);

	// title border layout
	x = 0;
	y = ofGetHeight() - 70;
	w = ofGetWidth();
	h = 70;
	ofSetColor(0, 180);
	ofDrawRectangle(x, y, w, h);

	// title text layout
	x = 50;
	y = ofGetHeight() - 25;
	ofSetColor(255);
	font.drawString(titles[i], x, y);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	// check mouse x position
	if (x > ofGetWidth() - 50) {
		i++; // increment index

		// loop index
		if (i > 2) {
			i = 0;
		}
	}
	else if (x < 50) {
		i--; // decrement index

		// loop index
		if (i < 0) {
			i = 2;
		}
	}

	// load new image
	image.load(imageFiles[i]);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
