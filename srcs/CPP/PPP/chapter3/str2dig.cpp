#include "std_lib_facilities.h"

int main()
{
    while(1){
        cout << "Enter a str to convert to digit: ";
        string str;
        cin >> str;
        if(str=="zero")
            cout << '0' << endl;
        else if(str=="one")
            cout << '1' << endl;
        else if(str=="two")
            cout << '2' << endl;
        else if(str=="three")
            cout << '3' << endl;
        else if(str=="four")
            cout << '4' << endl;
        else
            cout << "Sorry, I don't understand it" << endl;
    }
}