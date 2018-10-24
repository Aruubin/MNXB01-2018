#include "circle.h"

circle::circle(double radius) : shape(getBase(), getHeight()){
	setRadius(radius);
}

circle::~circle(){}
