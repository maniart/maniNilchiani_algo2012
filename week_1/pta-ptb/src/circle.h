/*
 *  circle.h
 *  pta-ptb
 *
 *  Created by Mani Nilchiani on 10/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CIRCLE_H
#define CIRCLE_H
#include "ofMain.h"

class circle{
	public:
	
		circle();
		void draw();
		void interpolateByPct(float myPct);
		
		ofPoint pos, posa, posb;
		float pct, shaper;
	
		ofColor circleColor;
};
#endif