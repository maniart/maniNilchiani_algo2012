#include "firework.h"
firework::firework(){
	setInitialConditions(ofGetWidth()/2, (ofGetHeight()+ballRadius), ofRandom(-1.3,1.3), ofRandom(6.5,7.5));
	damping = ofRandom(.95,.99);
	explode = false;
	done = false;
	ballRadius = 2;
	timer = 0;
	explodeNow = ofRandom(50,170);
	explodeNow = round(explodeNow);
	numParticles = 100;
	fwColor.set(ofRandom(100,255),ofRandom(100,255),ofRandom(100,255));

}
//------------------------------------------------------------------------------------------------
void firework::setInitialConditions(float px, float py, float vx, float vy){
	vel.set(vx,vy);
	pos.set(px,py);
}
//------------------------------------------------------------------------------------------------
void firework::addForce(float x, float y){
	frc.x += x;
	frc.y += y;
}
//------------------------------------------------------------------------------------------------
void firework::resetForce(){
	frc.set(0,0);
}
//------------------------------------------------------------------------------------------------
void firework::addDampingForce(){
	frc.x -= vel.x*damping;
	frc.y -= vel.y*damping;
}
//------------------------------------------------------------------------------------------------
void firework::update(){
	vel += frc;
	pos += vel;
	timer ++;
}
//------------------------------------------------------------------------------------------------
void firework::draw(){
	ofEnableAlphaBlending();
	ofSetLineWidth(2);
	ofFill();
	ofNoFill();
	ofSetColor(255,255,100);
	if (explode == true) {
		cout << explodeNow << endl;
		ofSetColor(fwColor,0);
		ofCircle(pos.x, pos.y, ballRadius);
		ofSetColor(fwColor,100);
		vel = 0;
		resetForce();
		while (particles.size()<numParticles) {
			for (int i=0; i<numParticles; i++) {
				particle tmpPrt;
				tmpPrt.setInitialConditions(pos.x,pos.y,ofRandom(-5,5),ofRandom(-5,5));
				particles.push_back(tmpPrt);
			}
		}	
		for (int i=0; i<particles.size(); i++) {
			particles[i].update();
			particles[i].addDampingForce();
			particles[i].resetForce();
			particles[i].addForce(0,.04);
			particles[i].draw();
		}
	} else {
		ofSetColor(fwColor,100);
		ofCircle(pos.x, pos.y, ballRadius);
	}
	ofDisableAlphaBlending();
}
//------------------------------------------------------------------------------------------------



