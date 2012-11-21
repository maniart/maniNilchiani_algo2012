#include "particle.h"
particle::particle(){
	trailSize = 80;
	damping= .02;
	//setInitialConditions(ofGetWidth()/2, ofGetHeight()/2, ofRandom(-5,5), ofRandom(-5,5));
}
//------------------------------------------------------------------------------------------------
void particle::setInitialConditions(float px, float py, float vx, float vy){
	vel.set(vx,vy);
	pos.set(px,py);
}
//------------------------------------------------------------------------------------------------
void particle::addForce(float x, float y){
	frc.x += x;
	frc.y += y;
}
//------------------------------------------------------------------------------------------------
void particle::resetForce(){
	frc.set(0,0);
}
//------------------------------------------------------------------------------------------------
void particle::addDampingForce(){
	frc.x -= vel.x*damping;
	frc.y -= vel.y*damping;
}
//------------------------------------------------------------------------------------------------
void particle::update(){
	vel += frc;
	pos += vel;
	ofPoint tmpTrail;
	tmpTrail.set(pos.x, pos.y);
	trail.push_back(tmpTrail);
	if(trail.size()>trailSize){
		trail.erase(trail.begin());
	}
	//for (int i=0; i<trail.size(); i++) {
//		if (trail[i].y > ofGetHeight()) {
//			trail.erase(trail.begin());
//		}
//	}
}
//------------------------------------------------------------------------------------------------
void particle::draw(){
	ofCircle(pos.x, pos.y, 2);
	ofNoFill();
	ofBeginShape();
		for (int i=0; i<trail.size(); i++) {
			ofVertex(trail[i].x, trail[i].y);
		}
	ofEndShape();
}
//------------------------------------------------------------------------------------------------


