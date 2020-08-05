#include "std_lib_facilities.h"

int main()
{
	double miles=0.0;
	double kilometers = 0.0;
	cout << "Enter the number of miles to convert: ";
	cin >> miles;

	kilometers = miles * (1/1.609);
	cout << "After conversion, the number of kilometers in " << miles << " miles: " << kilometers << endl;
	
	return 0;
}

