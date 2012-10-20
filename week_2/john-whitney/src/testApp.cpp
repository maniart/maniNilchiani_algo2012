#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofBackground(0, 0, 0, 255);
	ofSetCircleResolution(100);
	// setting up initial positions
	xorig = ofGetWidth()/2;
	yorig = ofGetHeight()/2;
	isCurve = false;
	text.set(25, 35);
		
	
}

//--------------------------------------------------------------
ofPoint testApp::makePoint(float radius, float angle){
	
	
	float x = xorig + radius * cos(angle+sin(ofGetElapsedTimef()+PI/4));
	float y = yorig + radius * sin(angle+sin(ofGetElapsedTimef()));
	tempPoint.x = x;
	tempPoint.y = y;
	return tempPoint;
	
}
//--------------------------------------------------------------
float testApp::makeAngle(int index){
	angle = ofGetElapsedTimef() * (1 + index/2.0);
	return angle;
}
//--------------------------------------------------------------
float testApp::makeRadius(int index){
	radius = 10 + index*10;
	return radius;
}
//--------------------------------------------------------------
void testApp::update(){
	
	
	
}
//--------------------------------------------------------------
void testApp::draw(){
	ofLight();
	
	ofNoFill();
	//ofEnableLighting();
	for (int i=0; i<50; i++) {
		ofSetColor(ofMap(mouseX, 0, ofGetWidth(), 0, 255, true), ofMap(mouseY, 0, ofGetHeight(), 0, 255, true), ofMap(i, 0, 50, 0, 255, true));
		ofCircle(makePoint(makeRadius(i), makeAngle(i)).x, makePoint(makeRadius(i), makeAngle(i)).y, 3);
		if (isCurve) {
			ofBezier(makePoint(makeRadius(i), makeAngle(i)).x, makePoint(makeRadius(i), makeAngle(i)).y, makePoint(makeRadius(i-2), makeAngle(i-2)).x, makePoint(makeRadius(i-2), makeAngle(i-2)).y, makePoint(makeRadius(i+3), makeAngle(i+3)).x, makePoint(makeRadius(i+3), makeAngle(i+3)).y, makePoint(makeRadius(i+1), makeAngle(i+1)).x, makePoint(makeRadius(i+1), makeAngle(i+1)).y);
		} else {
			ofLine(makePoint(makeRadius(i), makeAngle(i)).x, makePoint(makeRadius(i), makeAngle(i)).y, makePoint(makeRadius(i+1), makeAngle(i+1)).x, makePoint(makeRadius(i+1), makeAngle(i+1)).y);

		}
		//makePoint(makeRadius(i), makeRadius(i));
		ofSetColor(0, 0, 0);
		ofFill();
		ofRect(15, 15, 175, 50);
		ofSetColor(255, 255, 255);
		ofDrawBitmapString(">Press 1 for Curves\n>Press 2 for Lines", text);
		ofNoFill();
	}	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
	switch (key) {
		case '1':
			isCurve = true;
			break;
		case '2':
			isCurve = false;
			break;
		default:
			break;
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