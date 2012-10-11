/*
 *  circle.cpp
 *  pta-ptb
 *
 *  Created by Mani Nilchiani on 9/27/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "circle.h"

circle::circle(){
	catchUpSpeed = .03f;
}
void circle::draw(){
	ofFill();
	ofCircle(pos.x, pos.y, 50);
}
void circle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) + pos.y;
}