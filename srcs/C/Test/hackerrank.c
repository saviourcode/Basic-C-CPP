#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

long getmincost(int crew_id_count, int job_id_count,int * crew_id, int * job_id)
{
    int costmat[crew_id_count][crew_id_count];
    int done[crew_id_count];

    for(int i =0; i<crew_id_count; i++){
        printf("for %d->",crew_id[i]);
        for(int j=0;j<job_id_count;j++){
            costmat[i][j] = abs(crew_id[i]-job_id[j]);
            printf("(%d)%d ",job_id[j],costmat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    long total = 0;
    
    for(int i=0;i<crew_id_count;i++){
        int small = INT_MAX;
        for(int j=0;j<crew_id_count;j++){
            if(costmat[i][j]<small){
                small = costmat[i][j];
            }
        }
        total = total + small;
    }

    return total;
}

int main(void)
{
    int crew[] = {5,3,1,4,6};
    int job[] = {9,8,3,15,1};
    printf("%ld\n",getmincost(5,5,crew,job));

    return 0;
}