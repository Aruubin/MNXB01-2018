#ifndef SHAPE_H
#define SHAPE_H

#include <cmath> //For fabs

class shape { //This class has the common characteristics of triangles and rectangles
	public: 
	shape(double base = 0., double height = 0.);
	virtual ~shape();
	virtual double area() = 0;
	virtual double circumference() = 0;
	double getBase() { return base_; } //Simple functions can be defined here in the header - any complex ones should go to .cpp!
	double getHeight() { return height_; }
	void setBase(double base) { base_ = fabs(base); }
	void setHeight(double height) { height_ = fabs(height); }
	
	protected: //Protected members can be accessed by this and whatever inherits from this
	double base_;
	double height_;
};

#endif
