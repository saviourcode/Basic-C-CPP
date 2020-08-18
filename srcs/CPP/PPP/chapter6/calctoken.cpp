#include "std_lib_facilities.h"

class Token{
    public:
        char kind;
        double value;
        Token(char k) :kind{k}, value{0.0} {}
        Token(char k,double v) :kind{k}, value{v} {}
};

vector<Token> tok;

Token get_token()
{
    Token tin{'0',0.0};

    char kind;
    double value;
    cin >> kind;
    if(!cin) error("Invalid Kind");
    tin.kind = kind;
    cin >> value;
    if(!cin) error("Invalid value");
    tin.value = value;

    return tin;
}

int main()
{
    cout << "Please enter the token and press CTRL+D when done" << endl;
    while(cin){
        Token t=get_token();
        tok.push_back(t);
    }
    for(Token t:tok){
        cout << t.kind << " " << t.value << endl;
    }

}
