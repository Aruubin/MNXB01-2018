#include "person.h"
#include <iostream>
#include <string>

using namespace std;

person::person(){}
person::~person(){}

int main(){
	person Tom;
	
	Tom.SetAge(11);
	Tom.SetShoeSize(28);
	
	Tom.Showprofile();
	
	return 0;
}
