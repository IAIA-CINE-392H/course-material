#include "SoundUtils.h"

//--------------------------------------------------------------
float SoundUtils::keyPressed(int key){
    
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
        frequency = 261.63*2; // B
    }
    
    return frequency;
}