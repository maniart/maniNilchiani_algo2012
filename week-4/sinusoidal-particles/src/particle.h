#ifndef PARTICLE_H
#define PARTICLE_H
#include "ofMain.h"
class particle{
	public:
		
		particle();
		void setInitialConditions(float px, float py, float pz, float vx, float vy,float vz);
		void addForce(float x, float y, float z);
		void addDampingForce();
		void resetForce();
		void update();
		void draw();
	
		ofVec3f pos, vel, frc;

		float damping;
		int trailSize, dustSize;
		ofColor trailColor;
		vector <ofPoint> trail;
		
	private:
	protected:

};

#endif


