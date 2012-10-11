/*
 *  circle.h
 *  emptyExample
 *
 *  Created by Mani Nilchiani on 9/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#pragma once
#include "ofMain.h"

class Circle{
	
public:
	
	Circle();
	void update();
	void draw();
	float radius;
	float modulator;
	float carrier;
	float xShift, yShift;
	ofPoint centerPoint;
	
};