#include "pts.h"

//-------------------------------------------------------------
pts::pts(){
	catchUpSpeed = .5;
	radius = 10;
	angle = 0;
	
}
//-------------------------------------------------------------
void pts::setup(){
	ofFill();
}
//-------------------------------------------------------------
void pts::xenoTo(float catchX, float catchY){
	pos.x = (1-catchUpSpeed)*pos.x + catchUpSpeed*catchX;
	pos.y = (1-catchUpSpeed)*pos.y + catchUpSpeed*catchY;
	float dx = pos.x - prevPos.x;
	float dy = pos.y - prevPos.y;
	
	angle = atan2(dy, dx);
	
	prevPos.x = pos.x;
	prevPos.y = pos.y;
}
//-------------------------------------------------------------
void pts::draw(){
	
	ofPushMatrix();
	ofTranslate(pos.x, pos.y, 0);
	ofRotateZ(angle * RAD_TO_DEG);
		ofSetColor(color.x, color.y, color.z);
		ofCircle(0,0, radius);
		ofSetColor(255, 255, 255);
		ofLine(radius*cos(PI), radius*sin(PI), radius*cos(0), radius*sin(PI));
		//ofRect(15,0,3,3);
	
	ofPopMatrix();
	
//	ofCircle(pos.x, pos.y, radius);
}
//-------------------------------------------------------------