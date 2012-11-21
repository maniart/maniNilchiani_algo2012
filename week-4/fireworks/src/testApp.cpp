#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	txtPt.set(20,20);
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0, 1);
	for (int i=0; i<10; i++) {
		firework tmpFw;
		fireworks.push_back(tmpFw);
	}
	for (int i=0; i<1000; i++) {
		ofPoint tmpPt;
		tmpPt.set(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
		starPos.push_back(tmpPt);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i=0; i<fireworks.size(); i++) {
		fireworks[i].update();
		fireworks[i].addDampingForce();
		fireworks[i].resetForce();
		fireworks[i].addForce(0,.04);
		if (fireworks[i].pos.y >= ofGetHeight()) {
			fireworks.erase(fireworks.begin()+i);
		}
		if (fireworks[i].timer == fireworks[i].explodeNow) {
			fireworks[i].explode = true;
			cout << "timer is: " << fireworks[i].timer << "Explosion will happen at: " << fireworks[i].explodeNow << endl;
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	for (int i=0; i<fireworks.size(); i++) {
		fireworks[i].draw();
	}
	for (int i=0; i<starPos.size(); i++) {
		ofFill();
		//ofSetColor(sin(ofGetElapsedTimef())*255);
		ofSetColor(255,50);
		ofCircle(starPos[i].x,starPos[i].y,1);
	}
	ofSetHexColor(0Xff0033);
	ofDrawBitmapString("Click anywhere to make fireworks", txtPt);
	
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

	while (fireworks.size() > 0) {
		fireworks.erase(fireworks.begin());
	}
	for (int i=0; i<10; i++) {
		firework tmpFw;
		fireworks.push_back(tmpFw);
	}
	for (int i=0; i<fireworks.size(); i++) {
		fireworks[i].resetForce();
		fireworks[i].addDampingForce();
		fireworks[i].addForce(0,.04);
		fireworks[i].update();
	}
	for (int i=0; i<fireworks.size(); i++) {
		//if (fireworks[i].pos.y == ofGetHeight()/2) {
//			cout << "kaboom for firework number" << i << fireworks[i].explodeThreshold <<  endl;
//		}
		fireworks[i].draw();
	}
	
	
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