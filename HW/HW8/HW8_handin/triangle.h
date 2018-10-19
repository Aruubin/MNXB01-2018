#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h" //Include the class that we want to inherit from

class triangle : public shape { //Triangle inherits from shape, access levels unchanged
	public: 
	triangle(double base = 0., double height = 0.); //A ctor/dtor must still be provided
	~triangle();
	
	double area() { return base_*height_/2.; } //This function is specific to triangle
	
	double circumference() {return getBase() + getHeight() + sqrt(getBase()*getBase() + getHeight()*getHeight());}
};

#endif
