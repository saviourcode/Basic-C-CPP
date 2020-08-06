#include "std_lib_facilities.h"

int main()
{
    cout << "Enter the number(s) of Pennies: ";
    int pennies;
    cin >> pennies;

    cout << "Enter the number(s) of nickels: ";
    int nickels;
    cin >> nickels;

    cout << "Enter the number(s) of dimes: ";
    int dimes;
    cin >> dimes;

    cout << "Enter the number(s) of quarters: ";
    int quarters;
    cin >> quarters;

    cout << "Enter the number(s) of half dollars: ";
    int half_dollars;
    cin >> half_dollars;

    cout << "Enter the number(s) of dollars: ";
    int dollars;
    cin >> dollars;

    cout << "You have " << pennies << " pennies.\n"
         << "You have " << nickels << " nickels.\n"
         << "You have " << dimes << " dimes.\n"
         << "You have " << quarters << " quarters.\n"
         << "You have " << half_dollars << " half dollars.\n"
         << "You have " << dollars << " dollars.\n";

    int total = pennies + 5*nickels + 10*dimes + 25*quarters + 50*half_dollars + 100*dollars;

    cout << "The value of all of your coins is $" << total/100.0 << " dollars.\n";

    return 0;
}