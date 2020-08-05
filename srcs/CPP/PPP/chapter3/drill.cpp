#include "std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to: ";
	string first_name;
	cin >> first_name;
	cout << "Dear " << first_name << "," << endl;

	cout << "\tHow are you? I am fine. I miss you." << endl
             << "Be sure to indent the first line. Add a few more lines of your choosing-it's your letter." << endl;

	cout << "Enter the friend name: ";
	string friend_name;
	cin >> friend_name;

	cout << "Have you seen " << friend_name << " lately?" << endl;
       	char friend_sex='0';
	cout << "Enter the gender of the friend (m/f): ";
	cin >> friend_sex;
	if(friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me" << endl;
	else if(friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me" << endl;
	cout << "Enter the age of the recipient: ";
	int age=0;
	cin >> age;
	if(age <=0 || age >=110)
		simple_error("you're kidding!");
	else
		cout << "I hear you just had a birthday and you are " << age << " years old" << endl;
	if(age <12)
		cout << "Next year you will be " << age+1 << endl;
	else if(age ==17)
		cout << "Next year you will be age to vote as " << age+1 << endl;
	else if(age >70)
		cout << "I hope you are enjoying retirement" << endl;

	cout << "Yours sincerely" << "\n\n" << endl;
	cout << "Sourabh" << endl;	

	return 0;
}
