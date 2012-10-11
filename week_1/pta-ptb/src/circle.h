/*
 *  circle.h
 *  pta-ptb
 *
 *  Created by Mani Nilchiani on 9/27/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CIRCLE_H
#define CIRCLE_H

#include "ofMain.h"

class circle {
	public:
		
		circle();
		void draw();
		void xenoToPoint(float catchY, float catchY);
		ofPoint pos;
		float catchUpSpeed; // take this pct of where I want to be, and 1-catchUpSpeed of my pos
	
};


#endif

