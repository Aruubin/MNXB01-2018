#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class square : public rectangle {
	public:
	square(double side = 0.);
	~square();
	
	void setSide(double sid){side=sid;}
	double getSide(){return side;}
	
	double area(){return side*side;}
	
	double circumference(){return side*4;}
		
	private:
	double side;	
};

#endif
