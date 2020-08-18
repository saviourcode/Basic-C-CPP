#include "std_lib_facilities.h"

int area(int,int);
int framed_area(int,int);

int main()
{
    int s1 = framed_area(7,1);
    cout << s1 << endl;
}

int area(int length, int width)
{
    if(length<=0||width <=0) return -1;
    return length*width;
}

int framed_area(int x,int y)
{
    constexpr int frame_width = 2;

    if(x-frame_width<=0||y-frame_width<=0)
        error("non-positive area() argument called by framed_area()");

    return area(x-frame_width,y-frame_width);
}
