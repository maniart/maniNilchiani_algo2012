#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0, 255);
	
	for (int i=0; i<1000; i++) {
		circle myCircle;
		myCircle.posa.x = 0;
		myCircle.posa.y = 100;
		myCircle.posb.x = ofGetWidth();
		myCircle.posb.y = 100;
		circles.push_back(myCircle);
		myCircle.interpolateByPct(0);
		pcts.push_back(ofRandom(.1));
	}
	
	
	clickCounter = 0;
	
	text.set(100, 100);
}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i=0; i<pcts.size(); i++) {
		pcts[i]+= .01;
		if (pcts[i]>1) pcts[i]=0;
		circles[i].interpolateByPct(pcts[i]);
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){

	for (int i=0; i<circles.size(); i++) {
		circles[i].draw();
	}

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	
	if (key == OF_KEY_UP) {
		for (int i=0; i<pcts.size(); i++) {
			pcts[i] += .1;
		}
	} else if (key == OF_KEY_DOWN) {
		for (int i=0; i<pcts.size(); i++) {
			pcts[i] -= .1;
		}
	} 
	
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
	
	clickCounter++;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

	if (clickCounter%2 == 0) {
		for (int i=0; i<circles.size(); i++) {
			circles[i].posb.x = x;
			circles[i].posb.y = y;
		}
		
	} else {
		for (int i=0; i<circles.size(); i++) {
			circles[i].posa.x = x;
			circles[i].posa.y = y;
		}
	}

	
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