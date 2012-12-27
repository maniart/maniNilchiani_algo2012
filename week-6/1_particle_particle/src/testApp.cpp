#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	word.loadImage("bi.png");
	mySvg = new ofxSVG();
	mySvg->load("wind.svg");
	
	for (int y=0; y<16; y++) {
		cout << "Objects: " << mySvg->layers[0].objects[y]->getOutline().size() << endl;
		
	}
	for (int h = 0; h<mySvg->layers[0].objects[0]->getOutline().size(); h++) {
		myPolyLines.push_back(mySvg->layers[0].objects[0]->getOutline()[h]);
		cout << "number of polylines here: "<< myPolyLines.size() << endl;
	}
	
	ofPolyline temp = myPolyLines[1].getVertices();
	
	temp = temp.getResampledBySpacing(3);
	
	for (int o=0; o < temp.size(); o++) {
		myPts.push_back(temp.getVertices()[o]);
		cout << "myPts" << myPts.size() << endl;
	}
	
	
	
	for (int i = 0; i < 500; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		myParticle.img = &word;
		particles.push_back(myParticle);
	}
	numVtx = myPolyLines[1].getVertices().size();
	bRepel		= true;
	radius		= 40;
	strength	= 0.5f; 
	
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		
		int idToMoveTo = i % myPts.size();
		
		//particles[i].addAttractionForce(myPts[idToMoveTo].x+ 300, myPts[idToMoveTo].y + 300, 1000,0.5);
		
		//printf("-- %i --- %i \n", i, i % myPts.size());
		for (int k=0; k<myPts.size(); k++) {
			if (i % myPts.size() == k){
				cout << myPts[k].x << endl;
				particles[i].addAttractionForce(myPts[k].x+ 300,myPts[k].y + 300, 1000,0.5);
			}
		}
		
			
		particles[i].addRepulsionForce(mouseX, mouseY, 200, 1.4);
		
		for (int j = 0; j < i; j++){
			particles[i].addRepulsionForce(particles[j], 1, 0.1);
			//particles[i].addAttractionForce(particles[j], 20, 0.005);
		}
		//for (int j = 0; j < i; j++){
//			if (bRepel){
//				particles[i].addRepulsionForce(particles[j], radius, strength);
//			} else {
//				particles[i].addAttractionForce(particles[j], radius, strength);
//			}
//		}
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	ofSetColor(0,0,0, 100);
	ofNoFill();
	
	//mySvg->draw();
	//ofSetColor(0x000000);
	cout << "Area" << myPolyLines[1].getArea() << endl;
	for (int k=0; k<myPts.size() ; k++) {
		ofCircle(myPts[k].x, myPts[k].y, 1);
	}
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
		//ofCurve(particles[i].pos.x, particles[i].pos.y, particles[i+1].pos.x, particles[i+1].pos.y,particles[i+3].pos.x, particles[i+3].pos.y, particles[i+5].pos.x, particles[i+5].pos.y);
		/*
		 ofBeginShape();
		 ofVertex(particles[i].pos.x, particles[i].pos.y);
		 ofEndShape(true);
		 */
	}
	
	string reportString =	"(space) = reset\n(a/s) strength = " + ofToString(strength) + 
	"\n(z/x) radius = " + ofToString(radius) + 
	"\n(r) toggle mode = " + (bRepel ? "repelling" : "attracting");
	
	ofSetColor(40,40,0);
	ofRect(10,10,300,80);
	ofSetColor(255,255,255);
	ofDrawBitmapString(reportString, 30, 30);
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
		case 'a':
			strength += 0.02f;
			break;
		case 's':
			strength -= 0.02f;
			if (strength <= 0) strength = 0.02f;
			break;
		case 'z':
			radius += 5.0f;
			break;
		case 'x':
			radius -= 5.0f;
			if (radius <= 0) radius = 5.0f;
			break;
		case 'r':
			bRepel = !bRepel;
			break;
	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	particles.erase(particles.begin());
	particle myParticle;
	myParticle.img = &word;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
