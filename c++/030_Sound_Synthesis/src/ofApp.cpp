#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    
	soundStream.printDeviceList();
    
	// if you need to set the audio device id:
	//soundStream.setDeviceID(2);

	// sound
	frequency = 440;
	amplitude = 0.0;
	phase = 0;

	// memory
	sampleRate = 48000;
	bufferSize = 512;
	buffers = 4;

    // channels
	inChannels = 0;
	outChannels = 2;

	// sound stream
    soundStream.setup(this, outChannels, inChannels, sampleRate, bufferSize, buffers);
    
    // modifiers
    fMod = aMod = 0;
    
	// allocate the a buffer for visualization
    vizBuffer.allocate(bufferSize, outChannels);
}

void ofApp::audioOut(ofSoundBuffer &outBuffer) {
    //cout << ofToString(outBuffer.getDurationMS()) << endl;
    
    float f = float(frequency) + fMod;
    f = ofClamp(f, 20, 20000); // clamp frequency between 20Hz - 20kHz
    
	// calculate step of sine was
	float step = f / float(sampleRate) * TWO_PI; 
    
    // keep the number low, otherwise the sin function gets weird
	while (phase > TWO_PI) {
		phase -= TWO_PI;
	}

	// loop through the buffer two at a time
	// we are working with stereo and the date is interleaved (left, right, left, right, etc)
	for (int i = 0; i < outBuffer.size(); i += outChannels) {
        float sample = sin(phase);  // set the sample value
    
        phase += step; // increase phase (degree)
        amplitude += aMod;
		amplitude = ofClamp(amplitude, 0, 0.75); // clamp sound between 0.0 - 0.75
                
		outBuffer[i] = sample * amplitude;			// left channel
		outBuffer[i + 1] = sample * amplitude;		// right channel
	}
    
	// audio is on a seperate thread, so we need to lock shared data (vizBuffer)
	unique_lock<mutex> lock(audioMutex);
	vizBuffer = outBuffer;
}


//--------------------------------------------------------------
void ofApp::update(){
	waveform.clear();

	unique_lock<mutex> lock(audioMutex);

	// draw visualization buffer
	// loop through frames instead to show alternative 
	for (size_t i = 0; i < vizBuffer.getNumFrames(); i++) {
		float sample = vizBuffer.getSample(i, 0);
		float x = ofMap(i, 0, vizBuffer.getNumFrames(), 0, ofGetWidth());
		float y = ofMap(sample, -1, 1, 0, ofGetHeight());
		waveform.addVertex(x, y);
	}

	// get root mean square (volume)
	rms = vizBuffer.getRMSAmplitude();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	ofSetLineWidth(1 + (rms * 30.)); // scale by 30 for display
	waveform.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	// fade in
    if (aMod < 0){
        aMod *= -1;
    }
	aMod = 0.0001;
	
	// keyboard "z" - "," acts as musical keyboard
    frequency = getFrequency(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	// fade out
    if (aMod > 0){
        aMod *= -1;
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	// frequency modulation
    fMod = ofMap(x, 0, ofGetWidth(), -500, 500, true);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	// reset frequency modulation
    fMod = 0.f;
}

//--------------------------------------------------------------
float ofApp::getFrequency(int key) {
	float frequency = 440.0;

	if (key == 'z') {
		frequency = 261.63; // C
	}
	else if (key == 'x') {
		frequency = 293.67; // D
	}
	else if (key == 'c') {
		frequency = 329.63; // E
	}
	else if (key == 'v') {
		frequency = 349.23; // F
	}
	else if (key == 'b') {
		frequency = 392.00; // G
	}
	else if (key == 'n') {
		frequency = 440.00; // A
	}
	else if (key == 'm') {
		frequency = 493.88; // B
	}
	else if (key == ',') {
		frequency = 261.63 * 2; // C
	}

	return frequency;
}