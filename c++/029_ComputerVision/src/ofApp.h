#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	ofVideoGrabber cam;

	// background subtraction
	ofxCv::RunningBackground background;
	cv::Scalar presenceMean;

	// binary image
	ofImage thresholded;

	// frame differencing
	ofPixels previous;
	ofImage diff;
	cv::Scalar diffMean; 	// a scalar is like an ofVec4f but normally used for storing color information

	// object tracking
	ofxCv::ContourFinder contourFinder;

    ofxPanel gui;

	// background
    ofParameter<bool> resetBackground;
    ofParameter<float> learningTime, thresholdValue;

	// contour
	ofParameter<float> minArea, maxArea, threshold;

	// clean up binary image
	ofParameter<int> erodeValue;
	ofParameter<int> dilateValue;

	// motion
	ofParameter<float> motionThreshold;

	// presence
	ofParameter<float> presenceThreshold;

};
