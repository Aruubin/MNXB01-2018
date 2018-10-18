#include <iostream>

using namespace std;

int main(){
	int a=5, b=10;
	int *p1;
	int *p2;
	p1=&a;
	cout<< "p1=&a: " << p1 << "=" << &a << endl;
	p2=&b;
	cout<< "p2=&b: " << p2 << "=" << &b << endl;
	*p1=10;
	cout<< "*p1=a: " << *p1 << "=" << a << endl;
	p1=p2;
	cout<< "p1=p2: " << p1 << "=" << p2 << endl;
	*p1=20;
	cout<< "\n*p1 " << *p1 << "\np1 " << p1 << endl;
	cout<< "\np2 " << p2 << "\n*p2 " << *p2 << endl;
	cout<< "\na " << a << "\nb " << b << endl;
	cout<< "\n&a " << &a << "\n&b " << &b << endl;
}
