#include "ofApp.h"

void ofApp::setup() {
	computerVision.setup();
}

void ofApp::update() {
	computerVision.update();

	if (computerVision.getPresenceDetected() == true) {
		cout << "presence" << endl;
	}

	if (computerVision.getMotionDetected() == true) {
		cout << "motion" << endl;
	}
}

void ofApp::draw() {
	computerVision.draw();	// draw to debug
}