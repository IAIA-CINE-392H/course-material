#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
	ofVideoPlayer video;
	ofPixels pixels;

	void setup();
	void update();
	void draw();

	void dragEvent(ofDragInfo dragInfo);
};
