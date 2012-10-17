#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0, 0, 0, 255);
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetCircleResolution(100);
	
	text.set(25, 35);
	
	showShape = false;
	showNet = true;
	
	for (int i=0; i<100; i++) {
		shape myShape;
		shapes.push_back(myShape);
		catchups.push_back(ofRandom(.5));
		radii.push_back(ofRandom(ofGetHeight()));
	}
	for (int i=0; i<shapes.size(); i++) {
		shapes[i].catchup = catchups[i];
		shapes[i].r = ofRandom(ofGetHeight());
		
	}
	
}

//--------------------------------------------------------------
void testApp::update(){
	float myX = ofMap(mouseX, 0, ofGetWidth(), 0, 255, true);
	float myY = ofMap(mouseY, 0, ofGetHeight(), 0, 255, true);
	
	for (int i=0; i<shapes.size(); i++) {
		shapes[i].interpolateColor(myX, myY);
		shapes[i].interpolateSize(mouseY);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	for (int i=0; i<shapes.size(); i++){
		
		if (showShape) {
			ofNoFill();
			shapes[i].draw();
		} else if (showNet) {
			ofFill();
			ofCircle(ofGetWidth()/2+shapes[i].r*sin(shapes[i].r/500*ofGetElapsedTimef()), ofGetHeight()/2+shapes[i].r*cos(shapes[i].r/500*ofGetElapsedTimef()), shapes[i].r/70);
			ofSetColor(255*abs(sin(ofGetElapsedTimef())), 255*abs(sin(ofGetElapsedTimef())), 255*abs(sin(ofGetElapsedTimef()+PI/4)));
			ofNoFill();
			//ofLine(ofGetWidth()/2+shapes[i+1].r*sin(shapes[i+1].r/500*ofGetElapsedTimef()), ofGetHeight()/2+shapes[i+1].r*cos(shapes[i+1].r/500*ofGetElapsedTimef()), ofGetWidth()/2+shapes[i+2].r*sin(shapes[i+2].r/500*ofGetElapsedTimef()), ofGetHeight()/2+shapes[i+2].r*cos(shapes[i+2].r/500*ofGetElapsedTimef()));
			ofCurve(ofGetWidth()/2+shapes[i-1].r*sin(shapes[i-1].r/500*ofGetElapsedTimef()), ofGetHeight()/2+shapes[i-1].r*cos(shapes[i-1].r/500*ofGetElapsedTimef()), ofGetWidth()/2+shapes[i].r*sin(shapes[i].r/500*ofGetElapsedTimef()), ofGetHeight()/2+shapes[i].r*cos(shapes[i].r/500*ofGetElapsedTimef()),ofGetWidth()/2+shapes[i+1].r*sin(shapes[i+1].r/500*ofGetElapsedTimef()), ofGetHeight()/2+shapes[i+1].r*cos(shapes[i+1].r/500*ofGetElapsedTimef()),ofGetWidth()/2+shapes[i+2].r*sin(shapes[i+2].r/500*ofGetElapsedTimef()), ofGetHeight()/2+shapes[i+2].r*cos(shapes[i+2].r/500*ofGetElapsedTimef()));

		} 
		
		
	}
	ofSetColor(0, 0, 0);
	ofFill();
	ofRect(15, 15, 175, 50);
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(">Press 1 for Circles\n>Press 2 for Web", text);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

	switch (key) {
		case '1':
			showShape = true;
			break;
		case '2':
			showShape = false;
			showNet = true;
			break;
		case '3':
			showShape = true;
			showNet = true;
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