#ifndef DUST_H
#define DUST_H
#include "ofMain.h"
class dust{
public:
	
	dust();
	void setInitialConditions(float px, float py, float vx, float vy);
	void addForce(float x, float y);
	void addDampingForce();
	void resetForce();
	void update();
	void draw();
	
	ofVec2f pos, vel, frc;
	float damping;
	
private:
protected:
	
};

#endif


