#include "std_lib_facilities.h"

int main()
{
    vector<int> nums(2);

    while(cin>>nums[0]>>nums[1]){
        if(nums[0]>nums[1]){
            cout << "The smaller value is: " << nums[1] << endl;
            cout << "The larger value is: " << nums[0] << endl;
        }
        else if(nums[0]<nums[1]){
            cout << "The smaller value is: " << nums[0] << endl;
            cout << "The larger value is: " << nums[1] << endl;
        }
        else if(nums[0]=nums[1]){
            cout << "The value is: " << nums[0] << endl;
            cout << "The value is: " << nums[1] << endl;
        }
    }
}