#include <iostream>

using namespace std;

class item
{
    int number; //private by default
    int cost; //private by default
    public:
        void getdata(int a, float b); //prototype declaration to be defined
        //Function defined inside the class
        void putdata(void)
        {
            cout << "number: " << number << endl;
            cout << "cost: " << cost << endl;
        }
};
/* Member function definition */
void item::getdata(int a, float b) //Use membership label
{
    //private variables directly used
    number = a;
    cost = b;
}
/* Main Program */
int main(void)
{
    item x;

    cout << "\nObject X " << endl;

    x.getdata(100,299.95);
    x.putdata();

    item y;

    cout << "\nObject Y " << endl;

    y.getdata(200,175.50);
    y.putdata();

    return 0;
}

