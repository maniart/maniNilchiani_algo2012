/*
 *  circle.cpp
 *  pta-ptb
 *
 *  Created by Mani Nilchiani on 10/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "circle.h"
//-------------------------------------------------------------------------------------
circle::circle(){
	shaper = 5;
}
//-------------------------------------------------------------------------------------
void circle::draw(){
	ofNoFill();
	ofSetColor(circleColor);
	ofCircle(pos.x, pos.y, 10);
}
//-------------------------------------------------------------------------------------
void circle::interpolateByPct(float myPct){
	pct = powf(myPct, shaper);
	pos.x = (1-pct)*posa.x + (pct)*posb.x;
	pos.y = (1-pct)*posa.y + (pct)*posb.y;
	circleColor.r = (1-pct)*255 + (pct)*ofRandom(255);
	circleColor.g = (1-pct)*255 + (pct)*ofRandom(255);
	circleColor.b = (1-pct)*255 + (pct)*ofRandom(255);
}
