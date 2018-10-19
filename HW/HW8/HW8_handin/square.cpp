#include "square.h"

square::square(double side) : rectangle(getBase(), getHeight()){
	setSide(side);
}

square::~square(){}
