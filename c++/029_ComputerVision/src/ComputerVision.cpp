#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ComputerVision::setup() {
	ofBackground(0);
	cam.setup(640, 480);
    
	// imitate() will set up previous and diff
	// so they have the same size and type as cam
	imitate(previous, cam);
	imitate(diff, cam);

	motionDetected = false;
	presenceDetected = false;

    gui.setup();
	gui.setDefaultWidth(300);
	gui.setPosition(700, 0);
    gui.add(resetBackground.set("Reset Background", false));
    gui.add(learningTime.set("Background Learning Time", 50, 0, 200));
    gui.add(thresholdValue.set("Background Threshold Value", 30, 0, 255));
	gui.add(erodeValue.set("Erode", 1, 0, 10));
	gui.add(dilateValue.set("Dilate", 1, 0, 10));
	gui.add(minArea.set("Countour Min area", 10, 1, 100));
	gui.add(maxArea.set("Countour Max area", 200, 1, 500));
	gui.add(threshold.set("Contour Threshold", 128, 0, 255));
	gui.add(presenceThreshold.set("Presence Threshold", 50, 0, 300));
	gui.add(motionThreshold.set("Motion Threshold", 100, 0, 300));
}

void ComputerVision::update() {
	cam.update();
    if(resetBackground) {
        background.reset();
        resetBackground = false;
    }
	if(cam.isFrameNew()) {
        background.setLearningTime(learningTime);
        background.setThresholdValue(thresholdValue);
		background.setIgnoreForeground(true);
		background.update(cam, thresholdImage);
		thresholdImage.update();
 
		presenceMean = mean(toCv(thresholdImage));

		// take the absolute difference of prev and cam and save it inside diff
		absdiff(thresholdImage, previous, diff); // detect motion
		diff.update(); // update for drawing

		// like ofSetPixels, but more concise and cross-toolkit
		copy(thresholdImage, previous);

		diffMean = mean(toCv(diff));
		diffMean *= Scalar(50); // arbituary scale number

		// clean up filters for binary images
		erode(thresholdImage, int(erodeValue));   // clean up noise
		dilate(thresholdImage, int(dilateValue)); // fill in holes

		// update threshold for drawing purposes
		thresholdImage.update();

		// countour finding
		contourFinder.setMinAreaRadius(minArea);
		contourFinder.setMaxAreaRadius(maxArea);
		contourFinder.setThreshold(threshold);
		contourFinder.findContours(thresholdImage); // use thresholdImage not difference for contour

		if (presenceMean[0] > presenceThreshold) {
			presenceDetected = true;
		}
		else {
			presenceDetected = false;
		}

		if (diffMean[0] > motionThreshold) {
			motionDetected = true;
		}
		else {
			motionDetected = false;
		}

	}
}

void ComputerVision::draw() {
	ofSetColor(255);

	//cam.draw(0, 0);
	if (thresholdImage.isAllocated()) {
		//diff.draw(640, 0);
		thresholdImage.draw(0, 0);
		contourFinder.draw();
	}

    gui.draw();

	string s = "presence value: " + ofToString(presenceMean[0]);
	ofDrawBitmapString(s, 700, 300);

	if (presenceDetected) {
		s = "presence detected";
		ofSetColor(255, 0, 0);
		ofDrawBitmapString(s, 900, 300);
		ofSetColor(255);
	}

	s = "motion value: " + ofToString(diffMean[0]);
	ofDrawBitmapString(s, 700, 325);

	if (motionDetected) {
		s = "motion detected";
		ofSetColor(255, 0, 0);
		ofDrawBitmapString(s, 900, 325);
		ofSetColor(255);
	}
}

bool ComputerVision::getPresenceDetected() {
	return presenceDetected;
}

bool ComputerVision::getMotionDetected() {
	return motionDetected;
}
