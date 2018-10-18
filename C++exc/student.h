#include <iostream>
#include <string>

using namespace std;

class student {

public:

	student();
	~student();
	
	
	void SetAge(int age){Age=age;}
	int GetAge(){return Age;}
	
	void SetGPA(double gpa){GPA=gpa;}
	double GetGPA(){return GPA;}
	
	void SetID(string ID){Student_ID=ID;}
	string GetID(){return Student_ID;}
	
	void Showprofile(){
		cout<< "Student ID: " << Student_ID <<"\n";
		cout<< "Age: " << Age <<"\n";
		cout<< "GPA: " << GPA <<"\n";
	}
	

private:
	int Age;
	double GPA;
	string Student_ID;
};
