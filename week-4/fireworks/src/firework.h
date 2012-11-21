#ifndef FIREWORK_H
#define FIREWORK_H
#include "ofMain.h"
#include "particle.h"

class firework{
	public:
		firework();
		void setInitialConditions(float px, float py, float vx, float vy);
		void addForce(float x, float y);
		void resetForce();
		void addDampingForce();
		void update();
		void draw();
		
		int ballRadius ,numParticles;
		float damping, timer, explodeNow;
		bool explode, done;
		ofVec2f pos, frc, vel;
		vector<particle> particles;
		ofColor fwColor;
	private:
	protected:

};
#endif
