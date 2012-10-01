#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	// how many drawings do we have?
	drawingCounter = 0;
	
	ofSetVerticalSync(true);
	ofBackground(255, 255, 255);
	
	// count the number of drawings, setup our drawings, and adding an instance of ofSoundPlayer for each drawing
	for (int i=0; i<tprVector.size() ; i++) {
		tprVector[i].tpr.setup();
		ofSoundPlayer tempPlayer;
		loopingSoundVector.push_back(tempPlayer);
	}
	
	// loading and playing all the sounds. One sound for one drawing.
	for (int i=0; loopingSoundVector.size(); i++) {
		loopingSoundVector[i].loadSound("drawbar_c4_a.aif");
		loopingSoundVector[i].setLoop(true);
		loopingSoundVector[i].play();
	}
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	
	// -------------------------- draw the line
	
	// draw all tpr's
	for (int i=0; i<tprVector.size(); i++) {
		tprVector[i].tpr.draw();
	}
	
	// -------------------------- draw the point at the current time for tprvector
	
	// calculating volume, pitch and pan for each ofSoundPlayer
	for (int i=0; i<tprVector.size(); i++) {
		if (tprVector[i].tpr.bHaveADrawing()) {
			float timeToCheck = ofGetElapsedTimef() - playbackStartTime;
			while (timeToCheck > tprVector[i].tpr.getDuration() && tprVector[i].tpr.getDuration() > 0) {
				timeToCheck -= tprVector[i].tpr.getDuration();
			}
			ofPoint tempPos = tprVector[i].tpr.getPositionForTime(timeToCheck);
			ofPoint tempVel = tprVector[i].tpr.getVelocityForTime(timeToCheck);
			tprVector[i].pos = tempPos;
			tprVector[i].vel = tempVel;
			float lengthOfVel = ofDist(0, 0, tprVector[i].vel.x, tprVector[i].vel.y);
			float tempVolume = ofMap(lengthOfVel, 0, 200, 0, 1, true);
			float tempPitch = ofMap(tprVector[i].pos.y, 0, float(ofGetHeight()), 2.5, .1, true);
			float tempPanning = ofMap(tprVector[i].pos.x, 0, float(ofGetWidth()), -1, 1, true);
			tprVector[i].vol = tempVolume;
			tprVector[i].pch = tempPitch;
			tprVector[i].panning = tempPanning;
			loopingSoundVector[i].setVolume(tprVector[i].vol);
			loopingSoundVector[i].setSpeed(tprVector[i].pch);
			loopingSoundVector[i].setPan(tprVector[i].panning);
			
			ofFill();
			ofSetColor(255,0,0);
			ofCircle(tprVector[i].pos.x, tprVector[i].pos.y, 2 + lengthOfVel/5.0);
			
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
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	tprVector[drawingCounter].tpr.addPoint(x,y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	// mouse pressd. add a new drawing to the page.
	
	tprProperties tempTpr;
	tprVector.push_back(tempTpr);
	tprVector[drawingCounter].tpr.startDrawing(x,y);
	drawingCounter++;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
	tprVector[drawingCounter].tpr.endDrawing();
	playbackStartTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}



