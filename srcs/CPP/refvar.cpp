#include <iostream>

using namespace std;

void f(int & x) //refvar
{
    x+=10;
}

int main(void)
{
    int m =10;
    f(m); // Call by reference
    cout << m << '\n';
    return 0;
}