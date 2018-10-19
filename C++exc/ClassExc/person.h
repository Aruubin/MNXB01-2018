#include <iostream>
#include <string>
#ifndef person_H
#define person_H
using namespace std;


class person{

public:

	person();
	~person();
	
	void SetAge(int age){Age=age;}
	int GetAge(){return Age;}
	
	void SetShoeSize(double size){ShoeSize=size;}
	double GetShoeSize(){return ShoeSize;}
	
	void Showprofile(){
		cout<<"Age: "<<GetAge()<<endl;
		cout<<"Shoesize: "<<ShoeSize<<endl;
	}
	
private:
	int Age;
	double ShoeSize;
};
#endif
