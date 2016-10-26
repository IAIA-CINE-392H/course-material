#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	ofEnableAlphaBlending();
	ofEnableAntiAliasing();
	ofSetVerticalSync(true);

	// use normalized texture coordinates
	ofDisableArbTex();
	
	// load image file
	image.load("IMAGE FILE PATH");
    
	// set up sphere
	plane.set(1024, 768);
	plane.mapTexCoordsFromTexture(image.getTexture());
	plane.getTexCoords().normalize();

    // update texture from pixels
    texture = image.getTexture();
    
	// fix up axis
	camera.setVFlip(true);

	// load shader file
	shader.load("shader");
}

//--------------------------------------------------------------
void ofApp::update() {
	// create a texture transformation matrix
	ofMatrix4x4 matrix = texture.getTextureMatrix();
	matrix.translate(0, 0, 0);
	matrix.scale(1, 1, 1);
	texture.setTextureMatrix(matrix);

	// set texture wrap mode to repeat
	texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);

	// disable depth test
	ofEnableDepthTest();

	// begin 3D camera
	camera.begin();

	// bind texture
	texture.bind();

	// shader begin
	shader.begin();

	// pass float value to shader - example shader not setup to receive
	//shader.setUniform1f("time", ofGetElapsedTimef()/2);

	// pass additional texture to shader - example shader not setup to receive
	//shader.setUniformTexture("tex1", image.getTextureReference(), 1);

	// draw plane
	plane.draw();

	// end shader
	shader.end();

	// unbind texture
	texture.unbind();
    
    // end 3D camera
	camera.end();

	// disable depth test
	ofDisableDepthTest();
}