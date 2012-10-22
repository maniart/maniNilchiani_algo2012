#ifndef PTS_H
#define PTS_H
#include "ofMain.h"
class pts{

	public:
	pts();
	void xenoTo(float catchX,float catchY);
	void draw();
	void setup();
	ofPoint pos, prevPos;
	float catchUpSpeed,radius, angle;
	ofVec3f color;
	private:
	protected:


};

#endif