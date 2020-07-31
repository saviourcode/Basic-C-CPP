#include <iostream>

using namespace std;

class sample
{
    int a;
    int b;
    public:
        void setvalue()
        {
            a = 25;b=40;
        }
        friend float mean(sample);
};

float mean(sample s)
{
    return float(s.a+s.b)/2.0;
}

int main(void)
{
    sample x;
    x.setvalue();
    cout << mean(x);
    return 0;
}