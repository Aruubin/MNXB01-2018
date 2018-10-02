#include <iostream>
using namespace std;

main(){
	int total=0;
	int i=1;
	while(i <=7){
		int temp;
		cin>>temp;
		total=total+temp;
		i=i+1;
	}
	int avg=total/i;
	cout<<avg;
}
