#include "std_lib_facilities.h"

int main()
{
    cout << "Enter a integer to check if it is even or odd: ";
    int num;
    cin >> num;
    if(num%2==0){
        cout << "The value " << num << " is an even number\n";
    }
    else{
        cout << "The value " << num << " is an odd number\n";
    }
}
