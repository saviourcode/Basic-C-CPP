#include <iostream>

using namespace std;

int & max(int & x,int & y)
{
    if(x>y)
        return x;
    else
        return y;
}

int main(void)
{
    int a = 1, b = 2;
    max(a,b) = -1;
    cout << "a=" << a << " b=" << b << endl;
    return 0;
}