/*
 *  circle.cpp
 *  multiple-xeno
 *
 *  Created by Mani Nilchiani on 10/13/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#include "circle.h"

circle::circle(){
	r = 5;
	//catchupSpeed = .03;
}
void circle::xenoToPoint(float catchX, float catchY){
	center.x = (catchupSpeed * catchX) + (1-catchupSpeed)*center.x;
	center.y = (catchupSpeed * catchY) + (1-catchupSpeed)*center.y;
}
void circle::draw(){
	ofNoFill();
	ofCircle(center.x, center.y, r);
}