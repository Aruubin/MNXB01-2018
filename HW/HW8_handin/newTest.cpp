//Time spent on homework: approximately 3 hours.
//The homework was completed alone

#include <iostream>
#include "triangle.h"
#include "rectangle.h"
#include "square.h" //Uncomment these as you implement the classes
#include "circle.h"
using namespace std;

bool isBigEnough(shape& obj) {
	return obj.area() > 30. && obj.circumference() > 30.;
}

int main() {
	triangle tri(10., 5.);
	cout << "Triangle properties:" << endl << "Base " << tri.getBase() << endl << "Height " << tri.getHeight() << endl;
	cout << "Area " << tri.area() << endl << "Circumference " << tri.circumference() << endl;
	cout << "It is" << (isBigEnough(tri) ? "" : " NOT") << " big enough!" << endl << endl;
	// (isBigEnough(tri) ? "" : " NOT") is a ternary operator, very useful conditional experssion in C++. Its basic syntax is 
	// (condition) ? (if_true) : (if_false)
	// If "condition" is true, the second expression is executed ("if_true"), and if it is not true, the third is executed ("if_false").
	// It is basically the same as writing the following but much shorter
	/* if (condition)
    		if_true;
	   else
    		if_false;*/
	

	rectangle rec(10., 5.);
	cout << "Rectangle properties:" << endl << "Base " << rec.getBase() << endl << "Height " << rec.getHeight() << endl;
	cout << "Area " << rec.area() << endl << "Circumference " << rec.circumference() << endl;
	cout << "It is" << (isBigEnough(rec) ? "" : " NOT") << " big enough!" << endl << endl;
	
	//Uncomment these blocks as you implement the classes
	square sq(5.);
	sq.setSide(7.);
	cout << "Square properties:" << endl << "Side " << sq.getSide() << endl;
	cout << "Area " << sq.area() << endl << "Circumference " << sq.circumference() << endl;
	cout << "It is" << (isBigEnough(sq) ? "" : " NOT") << " big enough!" << endl << endl;

	circle circ(10.);
	circ.setRadius(5.);
	cout << "Circle properties:" << endl << "Radius " << circ.getRadius() << endl;
	cout << "Area " << circ.area() << endl << "Circumference " << circ.circumference() << endl;
	cout << "It is" << (isBigEnough(circ) ? "" : " NOT") << " big enough!" << endl << endl;
	
	return 0;
}

