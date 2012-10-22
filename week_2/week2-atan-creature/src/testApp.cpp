#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	prevPos.set(0,0);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetCircleResolution(100);
	ofBackground(255, 255, 255, 255);
	pt.setup();
	for(int i=0;i<40;i++){
		pts tmpPt;
		tmpPt.color.x = 20;
		tmpPt.color.y = 100;
		tmpPt.color.z = 50; 
		tmpPt.radius -= i*.9;
		myPts.push_back(tmpPt);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	//myFish.xenoTo(mouseX,mouseY);
	pt.xenoTo(mouseX, mouseY);
	pt.pos.x = pt.pos.x + floor((sin(ofGetElapsedTimef())));
	pt.pos.y = pt.pos.y + (cos(ofGetElapsedTimef())*4);
	
 	myPts[0].xenoTo(pt.pos.x,pt.pos.y-2*(pt.radius*sin(pt.angle)));
	for (int i=1; i<myPts.size(); i++) {
		myPts[i].xenoTo(myPts[i-1].pos.x,myPts[i-1].pos.y);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	pt.pos.y += cos(ofGetElapsedTimef());
	pt.pos *= sin(floor(ofGetElapsedTimef()))*.50;	
	for (int i=0; i<myPts.size(); i++) {
		myPts[i].draw();
		if (i>0) {
			ofSetLineWidth(2);
			ofSetColor(myPts[i].color.x, myPts[i].color.y, myPts[i].color.z);
			ofLine(myPts[i].pos.x, myPts[i].pos.y+myPts[i].radius*cos(0), myPts[i-1].pos.x, myPts[i-1].pos.y+myPts[i-1].radius*cos(0));
			ofLine(myPts[i].pos.x, myPts[i].pos.y-myPts[i].radius*cos(0), myPts[i-1].pos.x, myPts[i-1].pos.y-myPts[i-1].radius*cos(0));
			
		}
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