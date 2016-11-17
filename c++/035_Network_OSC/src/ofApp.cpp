#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(0);
    ofSetFrameRate(60);
    
    // 1,000,000 particles
    unsigned w = 1000;
    unsigned h = 1000;
    
    particles.init(w, h);
    
    if (ofIsGLProgrammableRenderer()) particles.loadShaders("shaders330/update", "shaders330/draw");
    else particles.loadShaders("shaders120/update", "shaders120/draw");
    
    // initial positions
    // use new to allocate 4,000,000 floats on the heap rather than
    // the stack
    float* particlePosns = new float[w * h * 4];
    for (unsigned y = 0; y < h; ++y)
    {
        for (unsigned x = 0; x < w; ++x)
        {
            unsigned idx = y * w + x;
            particlePosns[idx * 4] = 400.f * x / (float)w - 200.f; // particle x
            particlePosns[idx * 4 + 1] = 400.f * y / (float)h - 200.f; // particle y
            particlePosns[idx * 4 + 2] = 0.f; // particle z
            particlePosns[idx * 4 + 3] = 0.f; // dummy
        }
    }
    particles.loadDataTexture(ofxGpuParticles::POSITION, particlePosns);
    delete[] particlePosns;
    
    // initial velocities
    particles.zeroDataTexture(ofxGpuParticles::VELOCITY);
    
    // listen for update event to set additonal update uniforms
    ofAddListener(particles.updateEvent, this, &ofApp::onParticlesUpdate);


	// OSC
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);

	px = 0;
	py = 0;
}

//--------------------------------------------------------------
void ofApp::update()
{
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));

	// OSC
	while (receiver.hasWaitingMessages()) {
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(m);

		string msg_string;
		msg_string = m.getAddress();

		//cout << msg_string << endl;

		// check for mouse moved message
		if (m.getAddress() == "/multi/1") {
			// both the arguments are int32's
			px = m.getArgAsFloat(0);
			py = m.getArgAsFloat(1);
		}

	}

	// particles
    particles.update();
}

// set any update uniforms in this function
void ofApp::onParticlesUpdate(ofShader& shader)
{
    //ofVec3f mouse(ofGetMouseX() - .5f * ofGetWidth(), .5f * ofGetHeight() - ofGetMouseY() , 0.f);

	float x = ofMap(px, 0, 1, 0, ofGetWidth());
	float y = ofMap(py, 0, 1, 0, ofGetHeight());

	x -= .5f * ofGetWidth();
	y = .5f * ofGetHeight() - y;

	ofVec3f mouse(x, y, 0.f);

    shader.setUniform3fv("mouse", mouse.getPtr());
    shader.setUniform1f("elapsed", ofGetLastFrameTime());
    shader.setUniform1f("radiusSquared", 200.f * 200.f);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    cam.begin();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    particles.draw();
    ofDisableBlendMode();
    cam.end();

	float x = ofMap(px, 0, 1, 0, ofGetWidth());
	float y = ofMap(py, 0, 1, 0, ofGetHeight());

	ofDrawCircle(x, y, 10);
}