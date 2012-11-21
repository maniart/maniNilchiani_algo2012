#ifndef PARTICLE_H
#define PARTICLE_H
#include "ofMain.h"
class particle{
	public:
		
		particle();
		void setInitialConditions(float px, float py, float vx, float vy);
		void addForce(float x, float y);
		void addDampingForce();
		void resetForce();
		void update();
		void draw();
	
		ofVec2f pos, vel, frc;
		float damping;
		int trailSize;
		vector <ofPoint> trail;
		
	private:
	protected:

};

#endif


