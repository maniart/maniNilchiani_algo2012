/*
 *  circle.cpp
 *  emptyExample
 *
 *  Created by Mani Nilchiani on 9/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Circle.h"

//--------------------------------------
Circle::Circle(){
}
//--------------------------------------
void Circle::update(){
	
	radius = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 80, true);
	//radius = 10;
}
//--------------------------------------
void Circle::draw(){
	
	
	ofSetColor(255, 255, 255,100);
	ofCircle(centerPoint.x, centerPoint.y, radius);
	
}
