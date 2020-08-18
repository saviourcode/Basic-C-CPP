#include "std_lib_facilities.h"

int main()
{
    vector<string> words;
    vector<string> dislikes = {"broccolli","sourabh","choure"};
    for(string temp; cin >> temp;)
        words.push_back(temp);

    cout << "Numbers of words: " << words.size() << endl;

    sort(words);
    int flag = 0;
    for(int i=0;i<words.size();++i){
        if(i==0 || words[i-1]!=words[i]){
            for(string temp:dislikes){
                if(words[i]==temp){
                    flag=1;
                    //break;
                }
            }
            if(flag==1)
            {
                cout << "BLEEP" << endl;
                flag =0;
            }
            else
                cout << words[i] << endl;
        }
    }
}