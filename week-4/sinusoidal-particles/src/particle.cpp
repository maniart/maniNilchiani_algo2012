#include "particle.h"
particle::particle(){
	trailSize = 200;
	setInitialConditions(ofGetWidth()/2, ofGetHeight()/2, 0 , 0, 0, 0);
}
//------------------------------------------------------------------------------------------------
void particle::setInitialConditions(float px, float py, float pz, float vx, float vy, float vz){
	vel.set(vx,vy,vz);
	pos.set(px,py,pz);

}
//------------------------------------------------------------------------------------------------
void particle::addForce(float x, float y, float z){
	frc.x += x;
	frc.y += y;
	frc.z += z;
}
//------------------------------------------------------------------------------------------------
void particle::resetForce(){
	frc.set(0,0,0);
}
//------------------------------------------------------------------------------------------------
void particle::addDampingForce(){
	frc.x -= vel.x*damping;
	frc.y -= vel.y*damping;
	frc.z -= vel.z*damping;
}
//------------------------------------------------------------------------------------------------
void particle::update(){
	vel += frc;
	pos += vel;
	ofPoint tmpTrail;
	tmpTrail.set(pos.x, pos.y, pos.z);
	trail.push_back(tmpTrail);
	if (trail.size() > trailSize) {
		trail.erase(trail.begin());
	}
}
//------------------------------------------------------------------------------------------------
void particle::draw(){
	ofCircle(pos.x, pos.y,pos.z, 9);
	ofNoFill();
	ofSetLineWidth(2);
	ofBeginShape();
		for (int i=0; i<trail.size(); i++) {
			ofVertex(trail[i].x, trail[i].y, trail[i].z);
			if (i<=(trail.size()-8)) {
					ofLine(trail[i].x, trail[i].y, trail[i].z,trail[i+8].x, trail[i+8].y, trail[i+8].z);
			}
		}
	ofEndShape(false);
	
}
//------------------------------------------------------------------------------------------------


