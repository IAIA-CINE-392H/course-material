#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	connectArduino();
}

//--------------------------------------------------------------
void ofApp::update(){
	updateArduino();
}

//--------------------------------------------------------------
void ofApp::draw(){
}

//--------------------------------------------------------------
void ofApp::connectArduino() {
	arduino.connect(ARDUINO_PORT, 57600);
	bSetupArduino = false;	
}

//--------------------------------------------------------------
void ofApp::setupArduino() {
	arduino.sendDigitalPinMode(13, ARD_OUTPUT);
	//arduino.sendDigitalPinMode(8, ARD_INPUT);
	//arduino.sendAnalogPinReporting(0, ARD_ANALOG);
	bSetupArduino = true;
	cout << "arduino ready" << endl;
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
	if (bSetupArduino == false) {
		if (arduino.isArduinoReady()) {
			setupArduino();
		}
		return;
	}
	arduino.update();

	//int potValue = arduino.getAnalog(0);
	//cout << ofToString(potValue) << endl;

	//int button = arduino.getDigital(8);
	//cout << ofToString(button) << endl;	
}