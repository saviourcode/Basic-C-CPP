#include <iostream>

using namespace std;

int main(void)
{
    int *arr;
    int size;

    cout <<"Please enter the size of array to create"<<endl;

    cin >> size;

    cout << "Creating the required array of size: " << size << endl;

    arr = new int[size];

    cout << "Dynamic allocation of memory for array is successful" << endl;

    delete arr;

    return 0;

}