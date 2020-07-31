#include <iostream>

using namespace std;

class ABC;

class XYZ
{
    int data;
    public:
        void setvalue(int value)
        {
            data = value;
        }
        friend void add(XYZ,ABC);
};

class ABC
{
    int data;
    public:
        void setvalue(int value)
        {
            data = value;
        }
        friend void add(XYZ,ABC);
};

void add(XYZ obj1,ABC obj2)
{
    cout << "Sum of data values of XYZ and ABC objects " << obj1.data+obj2.data << endl;
}

int main(void)
{
    XYZ x;
    ABC a;
    x.setvalue(5);
    a.setvalue(50);
    add(x,a);
    return 0;
}