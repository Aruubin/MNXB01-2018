#include "student.h"
#include <iostream>
#include <string>

using namespace std;

student::student(){}
student::~student(){}

int main(){

	student Carl;
	
	Carl.SetAge(57);
	Carl.SetGPA(3.8);
	Carl.SetID("706carl");
	
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
	
	cout<<"Age of Emma: \n";
	cout<<Emma.GetAge();
	cout<<"\n GPA of Emma: \n";
	cout<<Emma.GetGPA();
	cout<<"\n Student ID of Emma: \n";
	cout<<Emma.GetID();
	cout<<"\n";
	
	Emma.Showprofile();

}
