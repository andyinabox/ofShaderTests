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

    // fbo.allocate(camWidth, camHeight);
    plane.set(800, 600, 30, 30);
    plane.mapTexCoords(0, 0, camWidth, camHeight);
}

//--------------------------------------------------------------
void testApp::update(){
    camera.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofClear(0, 0, 0,255);

    float cx = ofGetWidth() / 2.0;
    float cy = ofGetHeight() / 2.0;

    ofDrawBitmapString(ofToString(ofGetFrameRate()), -(cx/2.0), -(cy/2.0));   


    float percentX = mouseX / (float)ofGetWidth();
    percentX = ofClamp(percentX, 0, 1);
    float percentY = mouseY / (float)ofGetHeight();
    percentY = ofClamp(percentY, 0, 1);


    
    // fbo.begin();
    shader.begin();
    shader.setUniformTexture("tex0", camera.getTextureReference(), 1);
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform1f("percentX", percentX);
    shader.setUniform1f("percentY", percentY);


    // camera.draw(0,0);

    ofTranslate(cx, cy);    
    ofColor(255, 255, 255);

    // the mouse/touch Y position changes the rotation of the plane.
    // float rotation = ofMap(percentY, 0, 1, -60, 60, true) + 60;
    // ofRotate(rotation, 1, 0, 0);

    plane.draw();

    shader.end();
    // fbo.end();

    // fbo.draw(0,0);
 



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
