#include <iostream>
using namespace std;


int main() {
	int first, second, larger;
	cout<<"enter first number\n";
	cin>>first;
	cout<<"enter second number\n";
	cin>>second;
	larger=second;
	
	if(first>second){
		larger=first;
	}
	cout<<"The larger number is "<<larger<<endl;
}
