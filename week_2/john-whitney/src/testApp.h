#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	

		bool isCurve;
		ofPoint makePoint(float angle, float radius);
		float	makeAngle(int index);
		float	makeRadius(int index); 
		float angle,radius,tempRadius, tempAngle,xorig, yorig;
		ofPoint tempPoint;
		ofPoint text;
		vector<float> radii;
		vector<float> angles;
		vector<ofPoint> points;
	
};
