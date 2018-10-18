#include <iostream>
using namespace std;

int main(){
	int *p1, *p2;
	p1 = new int;
	*p1=42;
	p2=p1;
	cout<<"*p1 =="<<*p1<<endl;
	cout<<"*p2 =="<<*p2<<endl;
	*p2=20;
	cout<<"*p1 =="<<*p1<<endl;
	cout<<"*p2 =="<<*p2<<endl;
	p1=new int;
	*p1=100;
	cout<<"*p1 =="<<*p1<<endl;
	cout<<"*p2 =="<<*p2<<endl;
	return 0;
}
