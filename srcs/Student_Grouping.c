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

