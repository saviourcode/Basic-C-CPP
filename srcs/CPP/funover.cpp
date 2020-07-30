#include <iostream>
using namespace std;
//declaration of function prototypes

int area(int);
int area(int,int);
float area(float);

int main()
{
    cout << "Calling the area() function for computing the area of a square (side =5) - " << area(5) << endl;
    cout << "Calling the area() function for computing the area of a rectangle (length = 5, breadth = 10) - " << area(5,10) << endl;
    // Note the use of 'f' are the number.
    cout << "Calling the area() function for computing the area of a circle (radius = 5.5) - " << area(5.5f) << endl;

    return 0;
}

int area(int side)
{
    return (side*side);
}

int area(int length, int breadth)
{
    return (length*breadth);
}

float area(float radius)
{
    return (3.14*radius*radius);
}
