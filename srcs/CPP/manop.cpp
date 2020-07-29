#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
    int Basic = 950, Allowance = 95, Total = 1045;
    float avg = 7.56711;

    cout << setw(10) << "Basic" << setw(10) << Basic << endl
         << setw(10) << "Allowance" << setw(10) << Allowance << endl
         << setw(10) << "Total" << setw(10) << Total << endl
         << setw(10) << "w/Prec" << setw(10) << avg << endl
         << setw(10) << "Prec" << setw(10) << fixed << setprecision(2) << avg << endl;

    return 0;
}