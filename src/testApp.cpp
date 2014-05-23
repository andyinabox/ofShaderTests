#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
// #ifdef TARGET_OPENGLES
// 	shader.load("shadersES2/shader");
// #else
// 	if(ofIsGLProgrammableRenderer()){
	// 	shader.load("shadersGL3/shader");
	// }else{
		shader.load("shadersGL2/shader");
// 	}
// #endif
// 

	ofSetFrameRate(30);
    
    int camWidth = 320;
	int camHeight = 240;

    camera.setVerbose(false);
	camera.initGrabber(camWidth, camHeight);

    fbo.allocate(camWidth, camHeight);
}

//--------------------------------------------------------------
void testApp::update(){
    camera.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofClear(0, 0, 0,255);
    
    // fbo.begin();
    shader.begin();
    // shader.setUniformTexture("tex0", camera.getTextureReference(), 1);
    camera.draw(0,0);
    shader.end();
    // fbo.end();

    // fbo.draw(0,0);

    ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, 20);   

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
