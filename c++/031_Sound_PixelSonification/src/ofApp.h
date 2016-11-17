#pragma once

#include "ofMain.h"

// custom class to whole a single sound
class Sound {
    public:
        Sound(float f, float p, float a, bool b){
            freq = f;
            phase = p;
            amp = a;
            fadeIn = b;
        }
        float freq;
        float phase;
        float amp;
        bool fadeIn;
};

class ofApp : public ofBaseApp{
	public:
    
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
    
		// a list of sounds
        vector<Sound> sounds;

		// image for sonification
        ofImage image;
        ofPoint pos;  // current pixel position
    
		// converts keyboard character to frequency
		float getFrequency(int key);

        // oF template
		void setup();
		void update();
		void draw();

		void dragEvent(ofDragInfo dragInfo);
};
