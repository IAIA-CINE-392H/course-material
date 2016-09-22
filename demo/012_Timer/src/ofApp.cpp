#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	bPause = false;
	endTime = 5000;							// in milliseconds
	startTime = ofGetElapsedTimeMillis();	// get the start time
	mediaIndex = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (bPause == true) {
		startTime = ofGetElapsedTimeMillis() - pauseTimeOffset;
	}
	else {
		timer = ofGetElapsedTimeMillis() - startTime;
		if (timer >= endTime && !bTimerReached) {
			bTimerReached = true;
			ofMessage msg("Timer Reached");
			ofSendMessage(msg);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	string timerString = ofToString(timer / 1000.0);
	ofDrawBitmapString(timerString, 10, 10);

	if (mediaIndex == 0) {
		ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 100);
	}
	else if (mediaIndex == 1) {
		ofDrawRectangle(ofGetWidth() / 2, ofGetHeight() / 2, 100, 100);
	}
	else if (mediaIndex == 2) {
		// draw something else
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		bPause = !bPause;

		if (bPause == true) {
			pauseTimeOffset = ofGetElapsedTimeMillis() - startTime;
		}
	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	cout << "Got the message: " + msg.message << endl;

	mediaIndex++;

	if (mediaIndex == 1) {
		endTime = 10*1000; // 10 seconds
	}
	else if (mediaIndex == 2) {
		endTime = 20*1000; // 20 seconds
	}

	bTimerReached = false;
}
