#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(10);
    ofSetBackgroundColor(0);
    ofEnableAlphaBlending();
    
	soundStream.printDeviceList();
    
	// if you need to set the audio device id:
	//soundStream.setDeviceID(2);

    // memory
	sampleRate = 48000;
	bufferSize = 4096;
	buffers = 16;

    // channels
	inChannels = 0;  
	outChannels = 2;
    
    // put a bunch of sounds in the list
    sounds.assign(20*20, Sound(440, 0, 0, false));
    
    // image
    image.load("Chess_(6125322558).jpg"); //https://commons.wikimedia.org/wiki/File:Chess_(6125322558).jpg
    image.setImageType(OF_IMAGE_GRAYSCALE);
    image.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST); // turn off interpolation
    image.resize(20, 20); // downsample 20 x 20 pixels

    // pixel position
    pos.set(0,0);

    // sound stream
    soundStream.setup(this, outChannels, inChannels, sampleRate, bufferSize, buffers);
}

void ofApp::audioOut(ofSoundBuffer &outBuffer) {
    //cout << ofToString(outBuffer.getDurationMS()) << endl;

	// loop through pixels
    for (int i=0; i<20*20; i++){

        float step = sounds[i].freq / float(sampleRate) * TWO_PI;
        
        while (sounds[i].phase > TWO_PI) {
            sounds[i].phase -= TWO_PI;
        }
        
		// only loop through buffer is sound is going to play
        if (sounds[i].amp > 0 || sounds[i].fadeIn == true){

			// loop through buffer
            for (int j = 0; j < outBuffer.size(); j += outChannels) {
                                
                if (sounds[i].fadeIn == true){
                    sounds[i].amp += 0.001f; // fade in amount
          
                    if (sounds[i].amp >= 1.0f){
                        sounds[i].fadeIn = false;
                    }
                }
                else {
                    sounds[i].amp -= 0.0001f; // fade out amount
                }
                
                sounds[i].amp = ofClamp(sounds[i].amp, 0, 1);
                
                float sample = sin(sounds[i].phase);
                sounds[i].phase += step;
                
                outBuffer[j] += sample * 0.5 * sounds[i].amp;
                outBuffer[j+1] += sample * 0.5 * sounds[i].amp;
            }
            
        }
    }
    
}


//--------------------------------------------------------------
void ofApp::update(){

	// loop through the pixel position each frame
    if (pos.x < 19){
        pos.x++;
    }
    else {
        pos.x = 0;
        pos.y++;
    }
    
	// reset
    if (pos.y > 19){
        pos.x = 0;
        pos.y = 0;
    }    
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255);
    image.draw(0, 0, 1000, 1000);
    
    ofColor c = image.getColor(pos.x, pos.y);
    int b = c.getBrightness();
    
    int i = pos.x + (pos.y * 20); // calculate single index by x,y value

    sounds[i].freq = ofMap(b, 0, 255, 110, 440); // map frequency from pixel brightness
    sounds[i].amp = 0.0;
    sounds[i].fadeIn = true;
    
    ofSetColor(255, 0, 0, 128);
    ofDrawRectangle( (pos.x) * 50, (pos.y) * 50, 50, 50); // 1000/20 = 50
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
	// load new image
	string file = dragInfo.files[0];
	image.load(file);
	image.setImageType(OF_IMAGE_GRAYSCALE);
	image.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
	image.resize(20, 20);
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