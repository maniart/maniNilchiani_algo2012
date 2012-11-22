#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0, 1);
	for (int i=0; i<10; i++) {
		particle tmpParticle;
		particles.push_back(tmpParticle);
	}
	
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i=0; i<particles.size(); i++) {
		if (i%2 == 0) {
			particles[i].setInitialConditions(mouseX,mouseY,0,(10*i*cos(ofGetElapsedTimef()+PI/2)),(10*i*sin(ofGetElapsedTimef()+PI/4)), 140*cos(i*ofGetElapsedTimef()+PI/8));

		} else {
			particles[i].setInitialConditions(mouseX,mouseY,0,(10*i*cos(ofGetElapsedTimef()-PI/2)),(10*i*sin(ofGetElapsedTimef()-PI/4)), 140*cos(i*ofGetElapsedTimef()-PI/8));

		}

		//particles[i].setInitialConditions(mouseX,mouseY,0,(10*i*cos(ofGetElapsedTimef())),(10*i*sin(ofGetElapsedTimef()+PI/4)), 100*cos(i*ofGetElapsedTimef()));
		particles[i].resetForce();
		particles[i].update();
		
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofEnableAlphaBlending();
	for (int i=0; i<particles.size(); i++) {
		particles[i].trailColor.setHue(abs(cos(ofGetElapsedTimef()*.06)*255));
		particles[i].trailColor.setSaturation(255);
		particles[i].trailColor.setBrightness(255);
		ofSetColor(particles[i].trailColor,50);
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		particles[i].draw();
		if (i<particles.size()-1) {
			ofPushView();
				ofSetLineWidth(2);
				ofLine(particles[i].pos.x, particles[i].pos.y, particles[i].pos.z, particles[i+1].pos.x, particles[i+1].pos.y, particles[i+1].pos.z);
			ofPopView();
		}
	}
	ofDisableAlphaBlending();
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