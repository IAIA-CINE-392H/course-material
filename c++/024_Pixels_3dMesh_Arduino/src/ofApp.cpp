#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(30);
	ofEnableDepthTest();

	// video camera and 3d mesh
	int w = 1280;
	int h = 720;

	video.setup(w, h);

	plane.set(w, h);
	plane.setResolution(w, h);

	for (int i = 0; i < w * h; i++) {
		plane.getMesh().addColor(ofFloatColor(0, 0, 0));
	}

	// default 3d extrusion amount
	extrude = 500.0f;

	// arduino
	bSetupArduino = false;
	bLight = false;
	arduino.connect("COM5", 57600);
}

void ofApp::setupArduino() {	
	// arduino pins
	arduino.sendDigitalPinMode(13, ARD_OUTPUT);
	arduino.sendDigitalPinMode(8, ARD_INPUT);
	arduino.sendAnalogPinReporting(0, ARD_ANALOG);

	// arduino ready
	bSetupArduino = true;
	cout << "arduino ready" << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
	// check if arduino is connected
	if (bSetupArduino == false) {
		if (arduino.isArduinoReady()) {
			setupArduino();
		}
		return;
	}
	
	// update arduino
	arduino.update();

	// blink led
	if (bLight == false) {
		arduino.sendDigital(13, ARD_LOW);
		bLight = true;
	}
	else {
		arduino.sendDigital(13, ARD_HIGH);
		bLight = false;
	}

	// button
	button = arduino.getDigital(8);
	//cout << ofToString(button) << endl;

	// pot
	potValue = arduino.getAnalog(0);
	cout << potValue << endl;


	// update extrude amount from potValue
	extrude = ofMap(potValue, 0, 1023, 0, 500);


	// update mesh from video
	video.update();

	if (video.isFrameNew()) {

		pixels = video.getPixels();

		int w = pixels.getWidth();
		int h = pixels.getHeight();

		for (int i = 0; i < w*h; i++) {
			ofFloatColor color;

			color.set(pixels.getColor(i * 3).r / 255.0f,
					  pixels.getColor(i * 3).g / 255.0f,
					  pixels.getColor(i * 3).b / 255.0f );

			float brightness = color.getBrightness();
			ofVec3f vertex = plane.getMesh().getVertex(i);

			vertex.z = brightness * extrude;

			plane.getMesh().setVertex(i, vertex);
			plane.getMesh().setColor(i, color);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	// draw normal or 3d version based on button state
	if (button == 0) {
		video.draw(0, 0, 1280, 720);
	}
	else if (button == 1) {
		camera.begin();
		plane.drawVertices();
		camera.end();
	}
}
