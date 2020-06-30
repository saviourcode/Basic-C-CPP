/* Student_Grouping.c

Suppose, A School took N students to a picnic. The teachers decided that they should form groups. They made the students to stand linewise and started making groups. But the students had their own compatibility factor Xi. The teacher had to keep similar compatibitlity factor students in each group. The groups are be formed of consecutive students standing in line. If two students don't have same compatibiltiy factor then find the take students such that their sum equals to a studnent of higher compatibitlity factor.

Sample Input:

Enter Number of Students: 8

Enter their compatibitlity factor: 1 2 1 1 1 1 1 1

Sample Output:

Number of Maximum Groups: 3

Explaination:

First Group: 1 2 1

Second Group: 1 1

Third Group: 1 1 1
*/
#include<stdio.h>
#include<stdlib.h>

void findgroup(int);
int n;
int *a;

int main() {
    printf("Enter the number of students\n");
    scanf("%d", &n);
    a = (int*) calloc(n, sizeof (int));
    printf("Enter the compatibility factors\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &*(a + i));
    findgroup(n);
    return 0;
}

void findgroup(int n) {
    int c = 0;
    int numg = 0;
    int j = 0;
    for (int i = 0; i < n - 1;) {
        if (*(a + i) == *(a + 1 + i)) {
            numg++;
            i = i + 2;
        } else if (*(a + i)<*(a + 1 + i)) {
            c = *(a + i);
            i++;
            j = i;
            while (c != (*(a + j))) {
                i++;
                c = c + *(a + i);
            }
            numg++;
            i++;
        } else if (*(a + i)>*(a + 1 + i)) {
            j = i;
            i++;
            while (c != *(a + j)) {
                c = c + *(a + i);
                i++;
            }
            numg++;
        }
    }
    printf("Number of Maximum that can be formed = %d\n", numg);
}

