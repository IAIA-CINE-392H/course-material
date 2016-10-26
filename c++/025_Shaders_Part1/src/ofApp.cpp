#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	ofEnableAlphaBlending();
	ofEnableAntiAliasing();
	ofSetVerticalSync(true);

	// use normalized texture coordinates
	ofDisableArbTex();
	
	// set up video camera
	video.setup(1280, 768);
	
	// load image file
	image.load("google-maps-times-square.jpg");

	// set up sphere
	sphere.set(400, 50);
	sphere.mapTexCoordsFromTexture(video.getTexture());
	sphere.getTexCoords().normalize();

	// fix up orientation
	camera.setVFlip(true);

	// load shader file
	shader.load("shader");
}

//--------------------------------------------------------------
void ofApp::update() {
	// update video frame
	video.update();

	// update texture to current video frame
	texture = video.getTexture();

	// create a texture transformation matrix
	ofMatrix4x4 matrix = texture.getTextureMatrix();
	matrix.translate(0, 0, 0);
	matrix.scale(1, 1, 1);
	texture.setTextureMatrix(matrix);

	// set texture wrap mode
	texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);

	// begin drawing scene
	ofEnableDepthTest();

	// begin 3D camera
	camera.begin();

	// bind texture
	texture.bind();

	// shader begin
	shader.begin();

	// pass time value to shader
	shader.setUniform1f("time", ofGetElapsedTimef()/2);

	// draw sphere
	//glPointSize(2);
	sphere.draw();

	// end shader
	shader.end();

	// unbind texture and camera
	texture.unbind();
	camera.end();

	// need to disable depth for fbo drawing
	ofDisableDepthTest();
}