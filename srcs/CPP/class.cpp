#include <iostream>

using namespace std;

class person
{
    char name[3];
    int age;

    public:
        void getdata(void);
        void showdata(void);
};

void person :: getdata(void)
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
}

void person :: showdata(void)
{
    cout << "\nName: " << name;
    cout << "\nAge: " << age << "\n";
}

int main()
{
    person p;
    p.showdata();
    p.getdata();
    p.showdata();

    return 0;
}
