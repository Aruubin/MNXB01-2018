#include "shape.h"

shape::shape(double base, double height) {
	setBase(base); //Let's call these functions rather than duplicate the code
	setHeight(height);
}

shape::~shape() { }
