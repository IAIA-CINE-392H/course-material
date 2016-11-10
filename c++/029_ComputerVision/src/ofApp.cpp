#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
	ofBackground(0);
	cam.setup(640, 480);
    
	// imitate() will set up previous and diff
	// so they have the same size and type as cam
	imitate(previous, cam);
	imitate(diff, cam);

    gui.setup();
	gui.setDefaultWidth(300);
	gui.setPosition(700, 0);
    gui.add(resetBackground.set("Reset Background", false));
    gui.add(learningTime.set("Background Learning Time", 50, 0, 200));
    gui.add(thresholdValue.set("Badkground Threshold Value", 30, 0, 255));
	gui.add(erodeValue.set("Erode", 1, 0, 10));
	gui.add(dilateValue.set("Dilate", 1, 0, 10));
	gui.add(minArea.set("Countour Min area", 10, 1, 100));
	gui.add(maxArea.set("Countour Max area", 200, 1, 500));
	gui.add(threshold.set("Contour Threshold", 128, 0, 255));
	gui.add(presenceThreshold.set("Presence Threshold", 50, 0, 300));
	gui.add(motionThreshold.set("Motion Threshold", 100, 0, 300));
}

void ofApp::update() {
	cam.update();
    if(resetBackground) {
        background.reset();
        resetBackground = false;
    }
	if(cam.isFrameNew()) {
        background.setLearningTime(learningTime);
        background.setThresholdValue(thresholdValue);
		background.setIgnoreForeground(true);
		background.update(cam, thresholded);
		thresholded.update();
 
		presenceMean = mean(toCv(thresholded));

		// take the absolute difference of prev and cam and save it inside diff
		absdiff(thresholded, previous, diff); // detect motion
		diff.update(); // update for drawing

		// like ofSetPixels, but more concise and cross-toolkit
		copy(thresholded, previous);

		diffMean = mean(toCv(diff));
		diffMean *= Scalar(50); // arbituary scale number

		// clean up filters for binary images
		erode(thresholded, int(erodeValue));  // clean up noise
		dilate(thresholded, int(dilateValue)); // fill in holes

		// update threshold for drawing purposes
		thresholded.update();

		// countour finding
		contourFinder.setMinAreaRadius(minArea);
		contourFinder.setMaxAreaRadius(maxArea);
		contourFinder.setThreshold(threshold);
		contourFinder.findContours(thresholded); // use thresholded not difference for contour
	}
}

void ofApp::draw() {
	ofSetColor(255);

	//cam.draw(0, 0);
	if (thresholded.isAllocated()) {
		//diff.draw(640, 0);
		thresholded.draw(0, 0);
		contourFinder.draw();
	}

    gui.draw();

	string s = "presence value: " + ofToString(presenceMean[0]);
	ofDrawBitmapString(s, 700, 300);

	if (presenceMean[0] > presenceThreshold) {
		s = "presence detected";
		ofSetColor(255, 0, 0);
		ofDrawBitmapString(s, 900, 300);
		ofSetColor(255);
	}

	s = "motion value: " + ofToString(diffMean[0]);
	ofDrawBitmapString(s, 700, 325);

	if (diffMean[0] > motionThreshold) {
		s = "motion detected";
		ofSetColor(255, 0, 0);
		ofDrawBitmapString(s, 900, 325);
		ofSetColor(255);
	}
}