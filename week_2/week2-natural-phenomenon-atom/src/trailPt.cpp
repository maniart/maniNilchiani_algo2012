#include "trailPt.h"

//-------------------------------------------------------------------
trailPt::trailPt(){
	catchUpSpeed = .9;
}
//-------------------------------------------------------------------
void trailPt::xenoTo(float catchX, float catchY){
	pos.x = catchX*catchUpSpeed + (1-catchUpSpeed)*pos.x;
	pos.y = catchY*catchUpSpeed + (1-catchUpSpeed)*pos.y;
}
//-------------------------------------------------------------------
void trailPt::draw(){
	ofCircle(pos.x, pos.y, 1);
}