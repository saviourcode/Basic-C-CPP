#include <iostream>

using namespace std;

void swap(int & a,int & b) // a and b are reference variables
{
	int t = a;
	a = b;
	b = t;
}

int main(void)
{
	int a = 3, b = 4;
	cout << "Before Swapping: " << a << " " << b << endl;
	swap(a,b);
	cout << "After Swapping: " << a << " " << b << endl;
	return 0;
}