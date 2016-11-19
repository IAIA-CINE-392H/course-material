#pragma once

#include "ofMain.h"
#include "ofxLibwebsockets.h"

#define NUM_MESSAGES 30 // how many past messages we want to keep

class ofApp : public ofBaseApp {

public:

	// web socket server
	ofxLibwebsockets::Server server;
	bool bSetup;

	//queue of rec'd messages
	vector<string> messages;

	//string to send to clients
	string toSend;

	// websocket methods
	void onConnect(ofxLibwebsockets::Event& args);
	void onOpen(ofxLibwebsockets::Event& args);
	void onClose(ofxLibwebsockets::Event& args);
	void onIdle(ofxLibwebsockets::Event& args);
	void onMessage(ofxLibwebsockets::Event& args);
	void onBroadcast(ofxLibwebsockets::Event& args);
	
	// test graphic
	ofSpherePrimitive sphere;
	ofImage image;
	int rotate = 0;

	// oF template
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);

};
