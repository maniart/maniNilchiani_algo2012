#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	newCircleAdded = false;
	
	upKeyCounter = 0;
	nums = 10;
	
	text.set(20, 30);
	ofSetVerticalSync(true);
	
	
	for (int i=0; i<nums; i++) {
		circle myCircle;
		circles.push_back(myCircle);
		circles[i].center.x = ofGetWidth()/2;
		circles[i].center.y = ofGetHeight()/2;
		circles[i].catchupSpeed = ofRandom(.2);
		
	}
	
}
//--------------------------------------------------------------
void testApp::addCircle(){
	circle newCircle;
	newCircle.center.x = ofGetWidth()/2;
	newCircle.center.y = ofGetHeight()/2;
	ofFill();
	ofSetColor(255, 255, 255);
	ofCircle(ofGetHeight()/2, ofGetWidth()/2, abs(100*sin(ofGetElapsedTimef())));
	newCircle.catchupSpeed = ofRandom(.2);
	circles.insert(circles.end(),newCircle);
	
}
//--------------------------------------------------------------
void testApp::eraseCircle(){
	circles.erase(circles.end());
}
//--------------------------------------------------------------
void testApp::update(){
	ofBackground(50*abs(sin(.2*(ofGetElapsedTimef()-PI/4))), 100*abs(sin(.2*ofGetElapsedTimef())), 100*(abs(.2*sin(ofGetElapsedTimef()+PI/4))), 255);
	if (newCircleAdded==true) {
		nums++;
		addCircle();
		//newCircleAdded = false;
	}
	
	for (int i=0; i<nums; i++) {
		circles[i].xenoToPoint(mouseX, mouseY);
	}
	if (circleErased==true) {
		
		while (nums > 10) {
			nums--;
			eraseCircle();
		}
		circleErased=false;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255);
	
	for (int i=0; i<nums; i++) {
		circles[i].draw();
		if (i > 0) {
			ofLine(circles[i].center.x, circles[i].center.y, circles[i-1].center.x, circles[i-1].center.y);
		
		}
	}

	//ofSetColor(255, 255, 255, 200);
	ofRect(15, 15, 270, 50);
	ofSetColor(255, 255, 255,255);
	ofDrawBitmapString(">UP KEY X 1 = add circles.\n>UP KEY X 2 twice = stop adding.\n>DOWN KEY = delete all but ten.", text);
	ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
	switch (key) {
		case OF_KEY_UP:
			upKeyCounter++;
			break;
		case OF_KEY_DOWN:
			circleErased = true;
			break;
	}
	
	
	if (upKeyCounter % 2 == 1) {
		newCircleAdded = true;
	} else {
		newCircleAdded = false;
	}
	
	

	
	
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