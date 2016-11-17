#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);

	ofBackground(0);
    ofSetCircleResolution(100);

	soundStream.printDeviceList();
	//soundStream.setDeviceID(2);
	
	soundStream.setup(this, 0, 1, 44100, 256, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	unique_lock<mutex> lock(audioMutex);

    // average volume history
    float sum = 0;
    for (auto v : volHistory){
        sum += v;
    }
    float average = sum / (float)volHistory.size();
    cout << average << endl;
    
	// set a threshold, do something if volume is loud enough!
	if (average > 0.5) {
		ofSetColor(255, 0, 0);
	}
	else {
		ofSetColor(255);
	}
	
	// map volume history to circle radius for visualization purpose
	float radius = ofMap(average, 0, 1, 0, 500);
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, radius);

    // clear volume history
    volHistory.clear();
}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer &inBuffer){
	unique_lock<mutex> lock(audioMutex);

	// convert from amplitude to volume (root mean square)
    float rms = inBuffer.getRMSAmplitude();
    
    // store running history
    volHistory.push_back(rms);
}
