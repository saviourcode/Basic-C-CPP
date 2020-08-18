#include "std_lib_facilities.h"

int main()
try {
    cin << "success\n";
    keep_window_open();
    return 0;
} catch(exception& e){
    cerr << "error: " << e.what() << endl;
    keep_window_open();
    return 1;
}