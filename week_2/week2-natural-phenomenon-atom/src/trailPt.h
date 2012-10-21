#ifndef TRAILPT_H
#define TRAILPT_H

#include "ofMain.h"

class trailPt{
	public:
		trailPt();
		ofPoint pos;
		float catchUpSpeed;
		void update();
		void draw();
		void xenoTo(float catchX, float catchY);
	private:
	protected:
};

#endif