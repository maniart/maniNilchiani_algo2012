/*
 *  electron.cpp
 *  emptyExample
 *
 *  Created by Mani Nilchiani on 10/21/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#include "ofMain.h"
#include "electron.h"

//-----------------------------------------------
electron::electron(){
	ellipseFactor.x = 0;
	ellipseFactor.y = 0;
	center.x = ofGetWidth()/2;
	center.y = ofGetHeight()/2;
	distFromCtr = rand() % 100 + 200;
	pos.x = ofGetWidth()/2 + distFromCtr*cos(0);
	pos.y = ofGetWidth()/2 + distFromCtr*sin(0);
	for (int i=0; i<100; i++) {
		trailPt tmpTrail;
		tmpTrail.pos.x = pos.x;
		tmpTrail.pos.y = pos.y;
		trail.push_back(tmpTrail);
	}
}
//-----------------------------------------------
void electron::update(){
	angle += .05;
	pos.x = center.x + (distFromCtr*cos(ellipseFactor.x+angle));
	pos.y = center.y + (distFromCtr*sin(ellipseFactor.y+angle));
	trail[0].xenoTo(pos.x,pos.y);
	for (int i=1; i<trail.size(); i++) {
		trail[i].xenoTo(trail[i-1].pos.x,trail[i-1].pos.y);
	}
}
//-----------------------------------------------
void electron::draw(){
	ofSetColor(255, 255, 255);
	ofNoFill();
	ofCircle(pos.x, pos.y, 3);
	ofFill();
	for (int i=0; i<trail.size(); i++) {
		ofSetColor(color);
		color.setBrightness(ofMap(i, 0, trail.size(), 0, 255, true));
		trail[i].draw();
		
	}
}

