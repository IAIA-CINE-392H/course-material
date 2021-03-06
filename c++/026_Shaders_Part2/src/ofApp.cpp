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

	// allocate memory for fbo
	fbo1.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
	fbo2.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
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
	fbo1.begin(); 
	ofClear(0, 5);
	ofEnableDepthTest();

	// begin 3D camera
	camera.begin();

	// bind texture
	texture.bind();

	// shader begin
	shader.begin();

	// pass time value to shader
	shader.setUniform1f("time", ofGetElapsedTimef()/2);

	// pass second texture to shader
	shader.setUniformTexture("tex1", image.getTexture(), 1);

	// pass time value to shader
	shader.setUniform1f("mixAmount", 0.5);

	// draw sphere
	glPointSize(2);
	sphere.draw();

	// end shader
	shader.end();

	// unbind texture and camera
	texture.unbind();
	camera.end();

	// need to disable depth for fbo drawing
	ofDisableDepthTest();
	fbo1.end();

	ofSetColor(255, 255);

	// creates the trail effect:
	// draw fbo1 into fbo2
	fbo2.begin();
	fbo1.draw(0, 0, ofGetWidth(), ofGetHeight());
	fbo2.end();

	// draw fbo2 - final render
	fbo2.draw(0, 0, ofGetWidth(), ofGetHeight());
}