/* ID: 13. Roman to Integer
 * Problem Statement: Convert Roman Letters to Integers
 * Solution: Created a Hash Table as shown below for working out mathematically
 *           hashfun(int ascii_val) takes the ascii value and then converts it to appropriate index. However there is one collision.
 *           To solve the collision we have used the linear probing technique that helps to avoid collison between two same index.
 *   +-------------+--------------+---------------+------------+----------------+
 *   | ASCII Value | Roman Letter | Integer Value | Hash Index | Linear Probing |
 *   +-------------+--------------+---------------+------------+----------------+
 *   |      73     |       I      |       1       |      3     |        3       |
 *   +-------------+--------------+---------------+------------+----------------+
 *   |      86     |       V      |       5       |      2     |        2       |
 *   +-------------+--------------+---------------+------------+----------------+
 *   |      88     |       X      |       10      |      4     |        4       |
 *   +-------------+--------------+---------------+------------+----------------+
 *   |      76     |       L      |       50      |      6     |        6       |
 *   +-------------+--------------+---------------+------------+----------------+
 *   |      67     |       C      |      100      |      4     |  1 (Collision) |
 *   +-------------+--------------+---------------+------------+----------------+
 *   |      68     |       D      |      500      |      5     |        5       |
 *   +-------------+--------------+---------------+------------+----------------+
 *   |      77     |       M      |      1000     |      0     |        0       |
 *   +-------------+--------------+---------------+------------+----------------+
*/
#include <stdio.h>
#define SIZE 7

int hashvalue[] = {
    1000,
    100,
    5,
    1,
    10,
    500,
    50,
};

//A Simple hash function to work out with the values
int hashfun(int ascii_val)
{
    int index = ascii_val % SIZE;

    //Linear Probing done when true
    return (ascii_val == 67)?1:index; 

}

int romanToInt(char *s) 
{
    int num = 0;
    //a variable to detect the when to subtract and when to add.
    int neg = 1;
    for(;*s!='\0';s++){
        //debugging
        //printf("%c ",*s);
        //printf("%i\n",hashvalue[hashfun((int)*s)]);

        //Check the condition if the next character is NULL or not.
        if(*(s+1)!='\0'){
            //If there is a slope which is going downwards then subtract by changing the sign of neg varibale to "-"
            if(hashvalue[hashfun((int)*s)]>=hashvalue[hashfun((int)*(s+1))])
                neg = 1;
            //else if there is a slope which is going upwards then add by changing the sign of neg varibale "+"
            else 
                neg = -1;
            num = num + neg*hashvalue[hashfun((int)*s)];
        }
        //Special case for the last term in the sequence, simply add it with the rest.
        else {
            neg = 1;
            num = num + neg*hashvalue[hashfun((int)*s)];
        }
        //debugging
        //printf("Num = %d\n",num);
    }

    return num;
}

int main(void) 
{
    int final;

    //Test Case Number 0
    final = romanToInt("III");
    printf("%d\n",final);

    //Test Case Number 1
    final = romanToInt("IV");
    printf("%d\n",final);

    //Test Case Number 2
    final = romanToInt("IX");
    printf("%d\n",final);

    //Test Case Number 3
    final = romanToInt("LVIII");
    printf("%d\n",final);

    //Test Case Number 4
    final = romanToInt("MCMXCIV");
    printf("%d\n",final);
}