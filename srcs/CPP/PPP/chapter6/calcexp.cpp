#include "std_lib_facilities.h"

class Token{
    public:
        char kind;
        double value;
        Token(char k) :kind{k},value{0.0} {} //construct from one value
        Token(char k,double v) :kind{k}, value{v} {} //construct from two values
};

int main()
{
    //Token init from construct
    Token t4{'+'};
    Token t5{'8',11.5};
    //Error: Token t6; because no construct match for it.
}