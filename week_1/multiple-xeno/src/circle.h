/*
 *  circle.h
 *  multiple-xeno
 *
 *  Created by Mani Nilchiani on 10/13/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CIRCLE_H
#define CIRCLE
#include "ofMain.h"

class circle{
	public:
	
	circle();
	
	void xenoToPoint(float catchX, float catchY);
	void draw();
	
	float r, catchupSpeed;
	ofPoint center;
};
#endif
