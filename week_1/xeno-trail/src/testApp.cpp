#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(0, 0, 0, 255);
	ofSetVerticalSync(true);
	for(int i=0; i<300; i++){
		circle newCircle;
		circles.push_back(newCircle);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	
	circles[0].xenoTo(mouseX,mouseY);
	for (int i=1; i<circles.size(); i++) {
		circles[i].xenoTo(circles[i-1].pos.x,circles[i-1].pos.y);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//ofSetColor(100, 255, 255);
	//circles[0].draw();
	//ofSetColor(0, 255, 100);
	ofSetLineWidth(3);
	ofEnableSmoothing();
	int i = 1;
	while (i<circles.size()-1) {
		ofSetColor(ofMap(mouseX, 0, ofGetWidth(), 0, 255, true), ofMap(mouseY, 0, ofGetHeight(), 0, 255, true), ofMap(i, 0, circles.size(), 0, 255, true));
		
		circles[i].draw();
		ofLine(circles[i].pos.x, circles[i].pos.y, circles[i+1].pos.x, circles[i+1].pos.y);
		i++;
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