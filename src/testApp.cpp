#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

	configLoaded = config.open("config.json");

	if(configLoaded) {
		cout << "config.json loaded:" << endl;
		cout << config.getRawString() << endl;

		// start not in full screen mode
		isFullScreen = false;

		// load the shader
		loadShader(0);

		// take er easy
		ofSetFrameRate(24);
	    
	    // setup the camera
	    int camWidth = config["camWidth"].asInt();
		int camHeight = config["camHeight"].asInt();
	    camera.setVerbose(false);
		camera.initGrabber(camWidth, camHeight);

	    // setup the plane
	    plane.set(ofGetWidth(), ofGetHeight(), 30, 30);
	    plane.mapTexCoords(0, 0, camWidth, camHeight);

	} else {
		// throw an error if loading fails
		throw std::runtime_error( "Failed to load config file" );
	}
}

//--------------------------------------------------------------
void testApp::update(){
    camera.update();
}

//--------------------------------------------------------------
void testApp::draw(){

	// this allows us to set up different
	// methods for different presets
	switch(preset) {
		default:
			defaultPreset();
			break;
	}
}

void testApp::defaultPreset() {
	// clean slate
    ofClear(0, 0, 0, 255);

    // establish our center
    float cx = ofGetWidth() / 2.0;
    float cy = ofGetHeight() / 2.0;

    // draw fps
    ofColor(255, 255, 255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), -(cx/2.0), -(cy/2.0));   

    // translate mouse positions to value from 0 to 1
    float percentX = mouseX / (float)ofGetWidth();
    percentX = ofClamp(percentX, 0, 1);
    float percentY = mouseY / (float)ofGetHeight();
    percentY = ofClamp(percentY, 0, 1);

    // go shader go!
    shader.begin();
    	// adding the camera input as a texture
	    shader.setUniformTexture("tex0", camera.getTextureReference(), 1);
	    // our clock
	    shader.setUniform1f("time", ofGetElapsedTimef());

	    // pass in mouse position
	    shader.setUniform1f("percentX", percentX);
	    shader.setUniform1f("percentY", percentY);

	    // center the gl coordinates
	    ofTranslate(cx, cy);    

	    // draw our canvas
	    plane.draw();

    shader.end();

}

void testApp::loadShader(int n) {
	// only take numbers that we have
	// shaders for
	if(n >= 0 && n < config["shaders"].size()) {
		preset = n;
		shader.load("shaders/"+config["shaders"][n].asString());
	}	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 32) {
        ofLog() << "toggling fullscreen mode";
        isFullScreen = !isFullScreen;
        ofSetFullscreen(isFullScreen);
        plane.setWidth(ofGetWidth());
        plane.setHeight(ofGetWidth());

	} else if (47 < key && key < 58) {

		// offsetting so that the
		// number keys translate to
		// correct int
		int n = key - 48;
		loadShader(n);

	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
