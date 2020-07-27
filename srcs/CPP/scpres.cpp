#include <iostream>

using namespace std;

int m = 10; //Global m

int main(void)
{
    int m = 20; // m redeclared, local to main

    {
        int k = m;
        int m = 30; //m declarad again
                    // local to inner block
        cout << "we are in inner block \n";
        cout << "k = " << k << endl;
        cout << "m = " << m << endl;
        cout << "::m = " << ::m << endl;
    }

    cout << "\nwe are in outer block \n";
    cout << "m = " << m << endl;
    cout << "::m = " << ::m << endl;

    return 0;
}