#include<iostream>
using namespace std;
int main(){
 int **arr;
 arr=new int*[3];
 arr[0]=new int [4];
 arr[1]=new int [4];
 arr[2]=new int [5];
 arr[2][0]=20;
 cout << arr[2][0] << endl;
 delete arr[0];
 delete arr[1];
 delete arr[2];
 delete []arr;
 cout << arr[2][0];
}