#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// load images from disk - must be in data folder
	image.load("MC_Kleiner_Panda.jpg");
	rightArrow.load("right-arrow.png");
	leftArrow.load("left-arrow.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// black background
	ofBackground(0, 0, 0);
	
	// relative positioning
	int h = ofGetHeight();						// set to window height
	int w = image.getWidth() * h / image.getHeight();	 	// maintain image proportion
	int x = ofGetWidth() * 0.5 - w * 0.5;				// center image horizontally
	int y = ofGetHeight() * 0.5 - h * 0.5;				// center image vertically
	image.draw(x, y, w, h);

	// absolute positioning
	leftArrow.draw(10, 538, 50, 50);		
	rightArrow.draw(1833, 538, 50, 50);
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
