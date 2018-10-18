#include <iostream>
void increaseAgeByRef(int &myAge){
	//I want to increase my age by 1
	myAge = myAge+1;
}
void increaseAgeByPtr(int *myAge){
	//I want to increase my age by 1
	myAge = myAge+1;
}
void increaseAge(int myAge){
	//I want to increase my age by 1
	myAge = myAge+1;
}


int main()
{
	int myAge = 30;
	std::cout << myAge << std::endl;
	increaseAgeByRef(myAge); // Call increaseAge() to increase my age by 1
	std::cout << myAge << std::endl; //is this working?
	// call different functions here and print the output
	// check if the address of myAge the same in increaseAgeByRef(),
	//increaseAgeByPtr() and increaseAge() as it is in main()
return 0;
}
