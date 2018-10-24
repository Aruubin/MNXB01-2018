#include "triangle.h"

triangle::triangle(double base, double height) : shape(base, height) {
	//The first (and in this case only) thing to do is initialize the parent object
}

triangle::~triangle() {
	//At the end of this destructor, the parent destructor is called automatically
}
