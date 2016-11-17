#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){	 
	ofSetVerticalSync(true);
	ofBackground(0);
    ofEnableDepthTest();

	// the fft needs to be smoothed out, so we create an array of floats
	fftSmoothed = new float[nBands];
	for (int i = 0; i < nBands; i++){
		fftSmoothed[i] = 0;
	}

	// load sound
	sound.load("jdee_beat.mp3");
	sound.setLoop(true);
	sound.play();
	
	// open video camera
	video.setup(1280, 720);

	// set up mesh to match video camera
	plane.set(1280 * 10, 720 * 10, 10, 10);
    plane.mapTexCoordsFromTexture(video.getTexture());

	// set up camera orientation
	camera.setVFlip(true);
	camera.setFarClip(100000.f);
}


//--------------------------------------------------------------
void ofApp::update(){
	// get the fft, and put in into a "smoothed" array,
	// by taking maximums, as peaks and then smoothing downward
	float * val = ofSoundGetSpectrum(nBands);
	
	for (int i = 0; i<nBands; i++){	
		// let the smoothed value sink to zero
		fftSmoothed[i] *= 0.97f;
		// take the max, either the smoothed or the incoming:
		fftSmoothed[i] = max(fftSmoothed[i], val[i]);
	}
    
    video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	camera.begin();

	// draw the fft
	int x, y, z, w, h, d;

	ofPushMatrix();
	ofTranslate(-3000, 0, -3000);

	for (int i = 0;i < nBands; i++) {
		x = i*100;
		y = 0;
		z = -1000;

		w = 50;
		h = -(fftSmoothed[i] * 500);
		d = 50;
		ofDrawBox(x, y, z, w, h, d);
	}
	ofPopMatrix();

    // get references to mesh and vertices
    auto &m = plane.getMesh();
    auto &v = m.getVertices();
    
	// loop through mesh vertices and modify z value from FFT
    for (int i=0; i<v.size(); i++){
        v[i].z = fftSmoothed[i] * 1000;
    }
    
    ofRotateX(90);
   
    video.bind(); // apply video texure
    
	glPointSize(15); // change point size
    glLineWidth(3);  // change line size

    plane.drawWireframe(); // draw lines
    plane.drawVertices();  // draw points
    
    video.unbind();
    
    camera.end();
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	// drag in a sound file to load
	string file = dragInfo.files[0];
	sound.load(file);
	sound.setLoop(true);
	sound.play();
}

