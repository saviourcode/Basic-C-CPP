#include <stdio.h>
#define WEEK 5
#define TOTAL (WEEK*30)
typedef struct person{
    int attn[WEEK];
    int prod[WEEK];
    int clfb[WEEK];
    char name[20];
    float per;
} person;

person p1 = {
    .attn={6,4,7,5,5},
    .prod={3,4,3,5,5},
    .clfb={4,6,5,4,4},
    .name="Peter Parker"
};
person p2 = {
    .attn={8,9,7,6,8},
    .prod={3,4,8,6,5},
    .clfb={7,7,5,8,9},
    .name="Steve Rogers"
};
person p3 = {
    .attn={3,4,6,4,5},
    .prod={9,9,8,7,7},
    .clfb={6,7,6,5,6},
    .name="Tony Stark"
};

int cal_sum(person p)
{
    int sum=0;
    for(int i=0;i<WEEK;i++){
        sum = sum + p.attn[i] + p.prod[i] + p.clfb[i];
    }
    return sum;
}

int main()
{
    p1.per = ((float)cal_sum(p1)/TOTAL)*100;
    p2.per = ((float)cal_sum(p2)/TOTAL)*100;
    p3.per = ((float)cal_sum(p3)/TOTAL)*100;
    printf("Percentage of P1: %f\n",p1.per);
    printf("Percentage of P2: %f\n",p2.per);
    printf("Percentage of P3: %f\n",p3.per);
    //Calculate Highest per
    if(p1.per>=p2.per){
        if(p1.per>=p3.per){
            printf("Employee of the week: %s\n",p1.name);
        }
        else{
            printf("Employee of the week: %s\n",p3.name);
        }
    }
    else{
        if(p2.per>=p3.per){
            printf("Employee of the week: %s\n",p2.name);
        }
        else{
            printf("Employee of the week: %s\n",p3.name);
        }
    }
    return 0;
}