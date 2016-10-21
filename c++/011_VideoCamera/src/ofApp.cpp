#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// set up alpha blending 
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);

	// initialize video camera
	camera.initGrabber(1280, 720);

	// allocate memory for frame buffer
	for (int i = 0; i < 100; i++) {
		image[i].allocate(1280, 720, OF_IMAGE_COLOR);
	}

	// set background to black
	ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){

	// update camera frame
	camera.update();

	// update frame buffer index
	index++;

	// keep frame buffer inbounds
	if (index > cnt) {
		index = 0;
	}

	// update image buffer with latest camera frame
	image[index].setFromPixels(camera.getPixels());

}

//--------------------------------------------------------------
void ofApp::draw(){

	// draw the camera frame directly
	//camera.draw(0, 0, 1920, 1080);

	// draw the frame buffer, up to and including the "cnt" value
	for (int i = 0; i <= cnt; i++) {
		// set the alpha channel before drawing the frame
		ofSetColor(255, alpha);
		image[i].draw(0, 0, ofGetWidth(), ofGetHeight());
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	// save the camera frame, not the image buffer 
	string filename = "output";
	filename += ofToString(ofGetElapsedTimeMillis());
	filename += ".jpg";
	image[index].save(filename);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

	// map alpha to the mouse's y position
	alpha = ofMap(y, 0, ofGetHeight() - 1, 0, 20, true);

	// map frame count to the mouse's x position
	cnt = ofMap(x, 0, ofGetWidth() - 1, 0, 99, true);

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
