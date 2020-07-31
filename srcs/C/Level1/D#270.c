#include <stdio.h>
#include <stdlib.h>

float money_value(char const * s)
{
    if(*s == '$')
        return atof(s+1);
    else if(*s=='-' && *(s+1)=='$')
        return -1*atof(s+2);
    else    
        return atof(s);
}

int main(void)
{
    printf("%f\n",money_value("$-.38"));
    printf("%f\n",money_value("-$ 0.1"));
    printf("%f\n",money_value("12.34"));
    printf("%f\n",money_value("$-2.3456"));
    printf("%f\n",money_value("$.2"));
}