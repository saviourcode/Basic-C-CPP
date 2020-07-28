#include <stdio.h>

int waterbombs(char *s,int w)
{
    int cntfire = 0;
    int firebombs = 0;
    do{
        if(*(s)=='x'){
            cntfire++;
        }
        else{
            firebombs += cntfire/w;
            if(cntfire%w!=0){
                firebombs++;
            }
            cntfire = 0;
        }
    }while(*(s++)!='\0');
    return firebombs;
}

int main(void)
{
    printf("Test Case 1 = %d\n",waterbombs("xxxxYxYx",4));
    printf("Test Case 2 = %d\n",waterbombs("xxYxx", 3));
    return 0;
}