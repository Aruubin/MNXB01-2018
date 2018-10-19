#include <iostream> //For cout
#include "triangle.h" //Both triangle.h and rectangle.h include shape.h
#include "rectangle.h" //I added #ifndef macros in shape.h, so it isn't doubly defined
using namespace std;

bool isBigEnough(shape& obj) { //A shape is big enough if its area is greater than 10
	return obj.area() > 10.;
}

int main() { //Create some shapes, print their area and see if they're big enough
	triangle tri(10., 10.);
	cout << "Triangle with area " << tri.area();
	if(isBigEnough(tri)) cout << " is big enough!" << endl;
	else cout << " is NOT big enough!" << endl;
	
	rectangle rec(5., 5.);
	cout << "Rectangle with area " << rec.area();
	if(isBigEnough(rec)) cout << " is big enough!" << endl;
	else cout << " is NOT big enough!" << endl;

	return 0;
}

