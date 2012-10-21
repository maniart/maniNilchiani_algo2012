#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofSetCircleResolution(100);
	
	center.set(ofGetWidth()/2, ofGetHeight()/2);
	soundStream.listDevices();
	int bufferSize = 256;
	
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	
	bufferCounter=0;
	drawCounter=0;
	smoothedVol=0.0;
	scaledVol=0.0;
	
	//bool setup(ofBaseApp * app, int outChannels, int inChannels, int sampleRate, int bufferSize, int nBuffers);
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
	
	
}

//--------------------------------------------------------------
void testApp::update(){

	bg.r = ofMap(smoothedVol, 0.0, .17, 0.0, 255.0, true)*sin(ofGetElapsedTimef());
	bg.g = ofMap(smoothedVol, 0.0, .17, 0.0, 255.0, true)*sin(ofGetElapsedTimef()+PI/4);
	bg.b = ofMap(smoothedVol, 0.0, .17, 0.0, 255.0, true)*sin(ofGetElapsedTimef()+PI/2);
	ofBackground(bg);

	scaledVol = ofMap(smoothedVol, 0.0, .17, 0.0, 1.0, true);
	
	
}

//--------------------------------------------------------------
void testApp::draw(){


	ofEnableAlphaBlending();
	
	circleRadius = (scaledVol * 100.0f);
	// draw the average volume:
	ofPushStyle();
		ofFill();
		ofSetColor(255,255,255,50);
		ofPushMatrix();
			ofTranslate(center.x, center.y, 0);
			//draw the average volume
			ofCircle(0, 0, circleRadius);
			ofNoFill();
			ofSetColor(255,255,255,200);
			//draw right channel
			for (int i = 0; i < right.size(); i++){
				ofCircle(circleRadius*cos(0)+i, circleRadius*(sin(0)*10)-right[i]*100.0f,2);
				//ofLine(circleRadius*cos(PI/circleRadius)+i, circleRadius*(sin(PI/circleRadius))-right[i]*100.0f, circleRadius*cos(0)+(i-1), circleRadius*(sin(0))-right[i-1]*100.0f);
			}
			//draw left channel
			for (int i=0; i<left.size(); i++) {
				ofCircle(-(circleRadius)*cos(0)-i, -(circleRadius)*(sin(0)*10)-left[i]*100.0f,2);
			}
		ofPopMatrix();
	ofPopStyle();
	drawCounter++;
	ofDisableAlphaBlending();
	
}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){	
	
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;	
	
	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;
		
		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	
	//this is how we get the mean of rms :) 
	curVol /= (float)numCounted;
	
	// this is how we get the root of rms :) 
	curVol = sqrt( curVol );
	
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	
	bufferCounter++;
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
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