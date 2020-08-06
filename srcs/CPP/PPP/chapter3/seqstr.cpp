#include "std_lib_facilities.h"

int main()
{
    cout << "Enter three strings: ";
    string arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];

    for(int j=0;j<3;j++){
        for(int i=0;i<2;i++){
            if(arr[i]>arr[i+1]){
                string temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
}