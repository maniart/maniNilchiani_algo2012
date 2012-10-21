#ifndef ELECTRON_H
#define ELECTRON_H

#include "ofMain.h"
#include "trailPt.h"
class electron{
	
public:
	electron();
		float angle,distFromCtr;
		vector <trailPt> trail;
		ofPoint pos, center;
		ofVec2f ellipseFactor;
		ofColor color;
		void draw();
		void update();
	private:
	protected:
};
#endif
