//Approximate time spent: 4h
//The work was done on my own

#include <iostream>

using namespace std;

int add(int a, int b) // passing to a function by value
{
// Modify so that the function returns sum of two integers
	int c=a+b;
	return c;
}

void increaseByOne(int *a, int *b) 
{
// Modify so that the function adds one to each value (a -> a+1, b -> b+1)
	*a=*a+1;
	*b=*b+1;
	return;
}

void swap(int &a, int &b)
{
// Modify so that the function swaps values a and b
	int temp=a;
	a=b;
	b=temp;
	return;
}

// Bonus points:
void convertToUpperCase(char *strPtr)
{
  // Modify so that the function converts lowercase letters to uppercase letters.  
  // You may find this helpful: http://www.cplusplus.com/reference/cctype/
} 

int main()
{

  int a = 3;
  int b = 5;

  cout << "add() function\n";
  cout << add(a,b) << endl; // 8

  cout << "increaseByOne() function\n";
  //call increaseByOne() function
  increaseByOne(&a,&b);
  cout << "a = " << a << "\tb = " << b << endl; // a  = 4 b = 6

  cout << "swap() function\n";
  swap(a,b);
  cout << "a = " << a << "\tb = " << b << endl; // b = 6 a = 4

  // bonus:
  char text[] = "mnxb01/nafy018 is the best course";
  convertToUpperCase(text);
  cout << text << endl; // MNXB01/NAFY018 IS THE BEST COURSE


  return 0;
}

