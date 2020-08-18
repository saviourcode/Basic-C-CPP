#include "std_lib_facilities.h"

int main()
{
    
}

double expression()
{
    double left = expression(); //read and evaluate an Expression
    Token t = get_token(); //get the next token
    switch(t.kind){       //see which kind of token it is
        case '+': 
            return left+term(); //read and evaluate a Term, and then do add

        case '-':
            return left=term(); //read and evaluate a Term, and then do sub

        default:
            return left; // return the value of the Expression
    }
}