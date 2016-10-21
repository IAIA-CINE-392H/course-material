#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(30);
	ofEnableDepthTest();

	// video camera dimensions
	int w = 1280;
	int h = 720;

	// open video camera
	video.setup(w, h);

	// configure plane mesh
	plane.set(w, h);			// plane dimensions (width and height)
	plane.setResolution(w, h);	// vertex count (columns and rows)

	// add a color to each vertex
	// loop through all vertices (width * height)
	for (int i = 0; i < w * h; i++) {
		// float color is a color normalized from 0-255 to 0-1
		plane.getMesh().addColor(ofFloatColor(0, 0, 0));
	}

	// flip camera y orientation
	camera.setVFlip(true);

	// set default extrude amount
	extrude = 500.0f;
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();

	if (video.isFrameNew()) {
		pixels = video.getPixels();

		int w = pixels.getWidth();
		int h = pixels.getHeight();

		// loop through all pixels and vertices
		for (int i = 0; i < w * h; i++) {

			// set color from pixels
			ofFloatColor color;
			color.set(pixels.getColor(i * 3).r / 255.0f,
					  pixels.getColor(i * 3).g / 255.0f,
					  pixels.getColor(i * 3).b / 255.0f );

			// get color brightness
			float brightness = color.getBrightness();

			// get mesh vertex
			ofVec3f vertex = plane.getMesh().getVertex(i);

			// add z amount based on brightness and extrude variable
			vertex.z = brightness * extrude;

			// set mesh vertex with new z value
			plane.getMesh().setVertex(i, vertex);

			// set mesh vertex color to pixel color
			plane.getMesh().setColor(i, color);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	camera.begin();
	plane.drawVertices(); // drawFaces() or drawWireframe()
	camera.end();
}