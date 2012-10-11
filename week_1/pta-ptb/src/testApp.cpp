#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
	ofBackground(9, 0, 0, 255);
	for (int i=0; i<circles.size(); i++) {
		catchUpSpeeds.push_back(ofRandom(1));
		circles[i].pos.set(300,300);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i=0; i<circles.size(); i++) {
		circles[i].xenoToPoint(mouseX, mouseY);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255, 255, 255);
	for (int i=0; i<circles.size(); i++) {
		circles[i].draw();
	}
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