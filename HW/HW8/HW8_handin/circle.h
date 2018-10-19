#ifndef CIRCLE_H
#define CIRCLE_H

#include <math.h>

#include "shape.h"

class circle : public shape {
	public:
	circle(double radius = 0.);
	~circle();
	
	void setRadius(double rad){radius=rad;}
	double getRadius(){return radius;}
	
	double area(){return M_PI*radius*radius;}
	
	double circumference(){return 2*M_PI*radius;}
		
	private:
	double radius;
	
};


#endif
