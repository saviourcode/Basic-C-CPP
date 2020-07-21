#include <stdio.h>
#include "strobj.h"

int main(void)
{
    String result = BLANK;
    
    scanStr(&result);

    printf("%s %ld\n",result.str,result.size);
    
    return 0;
}