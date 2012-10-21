#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofSetCircleResolution(100);
	ofBackground(0, 0, 0, 255);
	for (int i=0; i<30; i++) {
		electron tmpElectron;
		tmpElectron.ellipseFactor.set(ofRandom(10), ofRandom(10));
		electrons.push_back(tmpElectron);
	}
	
}

//--------------------------------------------------------------
void testApp::update(){	
	for (int i=0; i<electrons.size(); i++) {
		electrons[i].update();
	}	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	ofSetColor(255,255,255,255);
	ofCircle(ofGetWidth()/2,ofGetHeight()/2, 8);
	for (int i=0; i<electrons.size(); i++) {
		electrons[i].draw();
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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