#include <iostream>
#include <string>
#include "person.h"
#ifndef teacher_H
#define teacher_H


class teacher:public person{

public:

	teacher();
	~teacher();
	
	void SetSubject(string subject){Subject=subject;}
	string GetSubject(){return Subject;}
	
	void Showprofile(){
		cout<< "Subject: " << Subject <<"\n";
		cout<< "Age: " << GetAge() <<"\n";
		cout<< "Shoesize: " << GetShoeSize() <<"\n";
	}
	

private:
	string Subject;
};
#endif
