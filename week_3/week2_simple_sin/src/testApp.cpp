#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofBackground(0, 0, 0, 1);
	ofSetColor(255, 255, 255);
	ofEnableAlphaBlending();
	ofSetCircleResolution(100);
	
	for (int i =0; i<100; i++) {
		Circle newCircle;
		newCircle.xShift = ofRandom(ofGetWidth());
		newCircle.yShift = ofRandom(ofGetHeight());
		myCircles.push_back(newCircle);
	}
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i=0; i<myCircles.size(); i++) {
		myCircles[i].update();
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	for (int i=0; i<myCircles.size(); i++) {
		myCircles[i].centerPoint.x = ofMap(sin(ofGetElapsedTimef()+PI), -1, 1, mouseX-myCircles[i].xShift, mouseX+myCircles[i].xShift, true);
		myCircles[i].centerPoint.y = ofMap(sin(ofGetElapsedTimef()+PI), -1, 1, mouseY-myCircles[i].yShift, mouseY+myCircles[i].yShift, true);
		
		myCircles[i].draw();
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