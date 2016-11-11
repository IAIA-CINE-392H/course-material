#pragma once

#include "ofxCv.h"
#include "ofxGui.h"

class ComputerVision : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	bool getPresenceDetected();
	bool getMotionDetected();

private:
	ofVideoGrabber cam;

	// background subtraction
	ofxCv::RunningBackground background;
	cv::Scalar presenceMean;

	// binary image
	ofImage thresholdImage;

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

	bool motionDetected;
	bool presenceDetected;

};
