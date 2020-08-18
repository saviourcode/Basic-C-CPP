#include "std_lib_facilities.h"

int main()
{
    vector<int> v = {1,2,3,4,5,6};
    vector<string> str = {"Kant","Plato","Ker"};
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }
    for(int j=0;j<str.size();j++){
        cout << str[j] << endl;
    }
    return 0;
}
