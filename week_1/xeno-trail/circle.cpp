/*
 *  circle.cpp
 *  xeno-trail
 *
 *  Created by Mani Nilchiani on 10/13/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "circle.h"

circle::circle(){
	catchUpSpeed = .15;
	pos.x = ofGetWidth()/2;
	pos.y = ofGetHeight()/2;
}
void circle::xenoTo(float catchX, float catchY){
	pos.x = (1-catchUpSpeed)*pos.x + (catchUpSpeed*catchX);
	pos.y = (1-catchUpSpeed)*pos.y + (catchUpSpeed*catchY);
}
void circle::draw(){
	ofCircle(pos.x, pos.y,2);
}
