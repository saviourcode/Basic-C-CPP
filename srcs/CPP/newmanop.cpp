#include <iostream>
using namespace std;
ostream & symbol(ostream & output)
{
    return output << "\tRs";
}

int main(void)
{
    cout << "Hello" << symbol << 100 << " Bye" << endl;

    return 0;
}