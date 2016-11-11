#pragma once

#include "ComputerVision.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	ComputerVision computerVision;
};
