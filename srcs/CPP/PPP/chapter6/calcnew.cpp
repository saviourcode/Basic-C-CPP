#include "std_lib_facilities.h"

int main()
{
    cout << "Please eneter expression (we can handle +,-,*, and .)\n";
    cout << "add an x to end expression (e.g., 1+2*3x): ";
    int lval=0;
    int rval;
    cin >> lval;
    if(!cin) error("No first operand");
    for(char op; cin >> op;){
        if(op!='x') cin >>rval;
        if(!cin) error("No second operand");
        switch(op){
            case '+':
                lval+=rval;
                break;
            case '-':
                lval-=rval;
                break;
            case '*':
                lval*=rval;
                break;
            case '/':
                lval/=rval;
                break;
            default:
                cout << "Result: " << lval << endl;
                keep_window_open();
                return 0;
        }
    }
    error("Bad expression");
}