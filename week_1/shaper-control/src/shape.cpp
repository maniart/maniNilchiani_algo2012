#include "shape.h"

shape::shape(){
}
void shape::interpolateColor(float catchX, float catchY){
	shapeColor.setHue((catchup*catchY) + (1-catchup)*shapeColor.getHue());
	shapeColor.setSaturation((catchup*catchX) + (1-catchup)*shapeColor.getBrightness());
	shapeColor.setBrightness(100);
}
void shape::interpolateSize(float catchY){
	r = (1-catchup)*r + catchup*catchY;
}
void shape::draw(){
	ofSetColor(shapeColor);
	ofCircle(ofGetWidth()/2, ofGetHeight()/2, r);
	
	
}