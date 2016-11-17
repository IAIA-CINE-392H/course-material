#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
    
		// sound
		float frequency;	// ~pitch
		float amplitude;	// ~volume
		float phase;		// degree offset in radians

    
		// memory
		int	sampleRate;		// digital samples per second
		int bufferSize;		// samples per buffer
		int buffers;		// numbers of buffers (latency)

    
		// channels
		int inChannels;		// mic, line in channels
		int outChannels;	// speakers, line out channels

    
        // sound stream
        ofSoundStream soundStream;
        void audioOut(ofSoundBuffer &outBuffer);
    
    
        // modifiers
        float aMod;
        float fMod;


		// visualization buffer   
        ofSoundBuffer vizBuffer;
		mutex audioMutex;
		ofPolyline waveform;
		float rms; // root mean squared

    
        // converts keyboard character to frequency
        float getFrequency(int key);
    
    
        // oF template
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
        void mouseDragged(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
};

