#include "std_lib_facilities.h"

int main()
{
    vector<double> temps; //Temperature vector

    for(double temp;cin>>temp;) //read into temp
        temps.push_back(temp); //put temp into vector

    for(double x:temps)
        cout << x << endl;
}