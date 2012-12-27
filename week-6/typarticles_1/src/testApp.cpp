#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(255, 255, 255, 255);
	bad.loadImage("bad.png");
	ma.loadImage("ma.png");
	ra.loadImage("ra.png");
	khahad.loadImage("khahad.png");
	bord.loadImage("bord.png");
	
	for (int i = 0; i < 1000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		if (i>800) {
			myParticle.img = &bad;
			 
		} else if(i>600){
			myParticle.img = &ma;
		} else if (i>400) {
			myParticle.img = &ra;
		} else if (i>200) {
			myParticle.img = &khahad;
		} else {
			myParticle.img = &bord;
		}
			
		
		particles.push_back(myParticle);
	}
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
		
		
		if (i>800) {
			particles[i].addAttractionForce(float(700),float(ofGetHeight()/2), 800, 0.5);
		} else if(i>600){
			particles[i].addAttractionForce(float(670),float(ofGetHeight()/2), 800, 0.5);
		} else if(i>400){
			particles[i].addAttractionForce(float(650),float(ofGetHeight()/2), 800, 0.5);
		} else if(i>200){
			particles[i].addAttractionForce(float(525),float(ofGetHeight()/2), 800, 0.5);
		} else{
			particles[i].addAttractionForce(float(490),float(ofGetHeight()/2), 800, 0.5);
		}
	
		particles[i].addRepulsionForce(mouseX, mouseY, 250, 10);
		
		for (int j = 0; j < i; j++){
			particles[i].addRepulsionForce(particles[j], 1, 0.1);
			particles[i].addAttractionForce(particles[j], 20, 0.005);
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
	ofSetColor(0,0,0, 20);
	ofNoFill();
	

	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
		ofCurve(particles[i].pos.x, particles[i].pos.y, particles[i+1].pos.x, particles[i+1].pos.y,particles[i+3].pos.x, particles[i+3].pos.y, particles[i+5].pos.x, particles[i+5].pos.y);
		/*
		 ofBeginShape();
		 ofVertex(particles[i].pos.x, particles[i].pos.y);
		 ofEndShape(true);
		 */
	}
	
	string reportString =	"(space) = reset\n(a/s) strength = " + ofToString(strength) + 
	"\n(z/x) radius = " + ofToString(radius) + 
	"\n(r) toggle mode = " + (bRepel ? "repelling" : "attracting");
	
	//ofSetColor(40,40,0);
	//ofRect(10,10,300,80);
	//ofSetColor(255,255,255);
	//ofDrawBitmapString(reportString, 30, 30);
	
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
	myParticle.img = &bad;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
