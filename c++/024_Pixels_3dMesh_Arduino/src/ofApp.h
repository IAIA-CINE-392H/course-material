#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		ofArduino arduino;
		bool bSetupArduino;
		void setupArduino();

		bool bLight;		// LED light status
		int button;		// button value
		int potValue;		// potentiometer value

		ofVideoGrabber video;
		ofPixels pixels;

		ofEasyCam camera;
		ofPlanePrimitive plane;

		float extrude; 		// 3d mesh extrusion amount

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
