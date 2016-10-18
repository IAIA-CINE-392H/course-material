#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableAlphaBlending();
    ofSetFrameRate(30);
    
    bSetupArduino = false;
    
    // replace the string below with the serial port for your Arduino board
    // you can get this from the Arduino application or via command line
    // for OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices
    // for Windows, the port will usually be COM1, COM2, etc.
    // the second argument is the baud
    arduino.connect("COM3", 57600);
	
    // light off/on
    bLight = false;

    // sound file
    sound.load("01 - Suspiria.mp3", true);
    sound.setLoop(true);
    sound.play();

    // video file
	video.load("0707_Atomic_Bomb_Blast_Effects_00_00_51_00_dv50.mp4");
	video.setVolume(0.0);
	video.play();
}

//--------------------------------------------------------------
void ofApp::setupArduino() {
    cout << "arduino is ready" << endl;

	// set up arduino pins
    arduino.sendDigitalPinMode(13, ARD_OUTPUT);    // led light
    arduino.sendAnalogPinReporting(0, ARD_ANALOG); // potentiometer
    
    // arduino is now setup
    bSetupArduino = true;
}

//--------------------------------------------------------------
void ofApp::update(){

    // If Arduino is ready and not yet setup
	if (arduino.isArduinoReady() && bSetupArduino == false) {
		setupArduino();
	}
	else {
    
        // update arduino
		arduino.update();

        // switch light variable
        bLight = !bLight;
        
        // update light state on arduino pin 13
		if (bLight == false) {
			arduino.sendDigital(13, ARD_LOW);
		}
		else {
			arduino.sendDigital(13, ARD_HIGH);
		}

        // get potentiometer value on analog pin 0
		potValue = arduino.getAnalog(0);
		cout << ofToString(potValue) << endl;

        // remap for sound speed
		float speed = ofMap(potValue, 0, 1023, 0.0, 1.0);
		sound.setSpeed(speed);
        
        // remap for video speed
        speed = ofMap(potValue, 0, 1023, 0.0, 10.0);
        video.setSpeed(speed);
        
        // update video frame
        video.update();
    }

}


//--------------------------------------------------------------
void ofApp::draw(){
    // remap pot vale for circle size
	float size = ofMap(potValue, 0, 1023, 10, 0);

	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofSetColor(255, 255, 255, 25);
    
	for (int i = 0; i < 50000; i++) {
		ofDrawCircle(ofRandom(1920), ofRandom(1080), size);
	}

	ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetColor(255, 255, 255, 10);

	video.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
	if (key == OF_KEY_RIGHT) {
		arduino.sendDigital(13, ARD_HIGH);
	}
	else if (key == OF_KEY_LEFT) {
		arduino.sendDigital(13, ARD_LOW);
	}
}


//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	sound.load(dragInfo.files[0], true);
	sound.play();
	sound.setLoop(true);
}
