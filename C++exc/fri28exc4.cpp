#include <iostream>
using namespace std;

int main(){
	int a;
	cout<<"Enter number";
	cin>>a;
	
	int *b=&a;
	
	cout<<"The value of the pointer is "<<*b<<" and the memory adress is"<<b;
	return 0;
}
