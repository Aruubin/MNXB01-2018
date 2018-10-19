#include "student.h"
#include "teacher.h"
#include <iostream>
#include <string>

using namespace std;

student::student() : person(){}
student::~student(){}

teacher::teacher() : person(){}
teacher::~teacher(){}

person::person(){}
person::~person(){}

int main(){

	student Carl;
	
	Carl.SetAge(57);
	Carl.SetGPA(3.8);
	Carl.SetID("706carl");
	Carl.SetShoeSize(43);
	
	cout<<"Age of Carl: \n";
	cout<<Carl.GetAge();
	cout<<"\n GPA of Carl: \n";
	cout<<Carl.GetGPA();
	cout<<"\n Student ID of Carl: \n";
	cout<<Carl.GetID();
	cout<<"\n";
	
	Carl.Showprofile();
	cout<<endl;
	
	
	
	student Emma;
	Emma.SetAge(22);
	Emma.SetGPA(3.1);
	Emma.SetID("704emma");
	Emma.SetShoeSize(39);
	
	cout<<"Age of Emma: \n";
	cout<<Emma.GetAge();
	cout<<"\n GPA of Emma: \n";
	cout<<Emma.GetGPA();
	cout<<"\n Student ID of Emma: \n";
	cout<<Emma.GetID();
	cout<<"\n";
	
	Emma.Showprofile();
	cout<<endl;

	teacher Rolf;
	Rolf.SetAge(62);
	Rolf.SetShoeSize(47);
	Rolf.SetSubject("Biology");
	
	cout<<"Profile for teacher Rolf: \n";
	Rolf.Showprofile();
}
