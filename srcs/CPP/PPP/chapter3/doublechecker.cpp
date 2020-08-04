#include "std_lib_facilities.h"

int main()
{
    int num_of_rep_words=0;
    string prev = " ";
    string current;

    while(cin >> current){
        ++num_of_rep_words;
        if(prev==current)
            cout << "Repeated word: " << current
                 << " at: " << num_of_rep_words << endl;
        prev = current;
    }

    return 0;
}