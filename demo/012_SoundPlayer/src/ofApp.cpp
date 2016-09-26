#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// load sound files - must in the bin/data folder
	s1085.load("1085.mp3");
	beat.load("beat.wav");
	synth.load("synth.wav");
	violet.load("violet.mp3");
	mohawk.load("Track01.ogg");

	// play this sound on load
	mohawk.play();

	// loop the synth sound
	synth.setLoop(true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// stop these sounds on key pressed
	s1085.stop();
	beat.stop();
	synth.stop();
	violet.stop();

	// use the keys to play different sounds
	if (key == 'q') {
		s1085.play();
	}
	else if (key == 'w') {
		beat.setSpeed(0.5); // half speed
		beat.play();
	}
	else if (key == 'e') {
		synth.play();
	}
	else if (key == 'r') {
		violet.play();
	}
	else if (key == 't') {
		beat.setSpeed(2.0); // twice as fast
		beat.play();
	}
	else if (key == 'y') {
		mohawk.setPosition(0.1); // skip to position in percentage
	}
	else if (key == 'u') {
		mohawk.setPosition(0.2); // skip to position in percentage
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	// use the mouse drag to scrub through the Mohawk sound file
	float percent = ofMap(x, 0, ofGetWidth()-1, 0.0, 1.0);
	mohawk.setPosition(percent);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	// drag a sound file into the program's windows to load and play
	string file = dragInfo.files[0];
	sound.load(file);
	sound.play();
}
