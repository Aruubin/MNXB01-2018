#include <iostream>
#include <string>
#include "person.h"
#ifndef student_H
#define student_H

using namespace std;

class student : public person{

public:

	student();
	~student();
	
	void SetGPA(double gpa){GPA=gpa;}
	double GetGPA(){return GPA;}
	
	void SetID(string ID){Student_ID=ID;}
	string GetID(){return Student_ID;}
	
	void Showprofile(){
		cout<< "Student ID: " << Student_ID <<"\n";
		cout<< "Age: " << GetAge() <<"\n";
		cout<< "Shoesize: " << GetShoeSize() << endl;
		cout<< "GPA: " << GPA <<"\n";
	}
	

private:
	double GPA;
	string Student_ID;
};
#endif
