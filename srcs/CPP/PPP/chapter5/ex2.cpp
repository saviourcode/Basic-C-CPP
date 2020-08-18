#include "std_lib_facilities.h"

double ctok(double c)
{
    int k = c + 273.15;
    if(k<0)
        error("Please enter a temperature greater than -273.15");
    return k;
}

int main()
{
    double c =0;
    cin >> c;

    if(!cin)
        error("Please enter a valid number");

    double k = ctok(c);

    cout << k << endl;

    return 0;
}