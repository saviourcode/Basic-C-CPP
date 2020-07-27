/* ReadTheDoc at Joplin, Programming Language/C/Basic####Three ways of using `const` keyword
*/
#include <stdio.h>

int main(void)
{
    char * const s = "GOOD";
    printf("%s\n",s);
    char *c ="a";
    s = c;
    printf("%s\n",s);
    return 0;
}