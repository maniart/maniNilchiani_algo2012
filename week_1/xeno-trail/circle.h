/*
 *  circle.h
 *  xeno-trail
 *
 *  Created by Mani Nilchiani on 10/13/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#include "ofMain.h"
#ifndef CIRLCE_H
#define CIRCLE_H

class circle{
	
	public:
	circle();
	void xenoTo(float catchX, float catchY);
	void draw();
	float catchUpSpeed;
	ofPoint pos;
	

};
#endif