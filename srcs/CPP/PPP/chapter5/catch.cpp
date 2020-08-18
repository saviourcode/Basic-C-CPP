#include "std_lib_facilities.h"

int main()
try {
    vector<int> v;
    for(int x;cin>>x;)
        v.push_back(x);
    for(int i=0;i<=v.size();++i)
        cout << "v[" << i << "] == " << v[i] << endl;

    cout << v[v.size()+1] << endl; //[] operator is overloaded for the error
    return 0;

} catch(runtime_error& e){
    cerr << "Oops! bad arguments to area()" << e.what() << endl;
    return 1;
}

