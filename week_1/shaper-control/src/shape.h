#ifndef SHAPE_H
#define SHAPE_H
#include "ofMain.h"

class shape {
	public:
	
	shape();
	
	void draw();
	void interpolateColor(float catchX, float catchY);
	void interpolateSize(float catchY);
	//void fun();
	ofColor shapeColor;
	float catchup, r;
	
	
};
#endif
