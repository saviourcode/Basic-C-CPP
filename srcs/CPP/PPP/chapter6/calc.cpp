#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter expression(we can handle + and -): ";

    int lval=0;
    int rval=0;
    char op;
    int res;

    cin >> lval >> op >> rval;

    if(op=='+')
        res=lval+rval;
    if(op=='-')
        res=lval-rval;
    cout << "Result: " << res << endl;

    keep_window_open();

    return 0;
}