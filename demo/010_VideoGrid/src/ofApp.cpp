#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	for (int i = 0; i < NUMBER_OF_VIDEOS; i++) {
		video[i].load("97250.mp4");
		video[i].setPosition(ofRandom(1.0));
		video[i].play();
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < NUMBER_OF_VIDEOS; i++) {
		video[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);

	for (int x = 0; x < COLUMNS; x++) {
		for (int y = 0; y < ROWS; y++) {

			int i = x * ROWS + y;

			int w = video[i].getWidth() * videoScale;
			int h = video[i].getHeight() * videoScale;

			rectangle[i].set(x*w, y*h, w, h);
			video[i].draw(x*w, y*h, w, h);

		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 32){
		paused = !paused;
	}
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

	// mouse only active if currently not paused by space bar
	if (paused == false){

		// pause the video when mouse hovers over it 
		ofPoint mousePoint(x, y);

		for (int i = 0; i < NUMBER_OF_VIDEOS; i++) {
			if (rectangle[i].inside(mousePoint) == true) {
				video[i].setPaused(true);
			}
			else {
				video[i].setPaused(false);
			}
		}
	
	}

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
