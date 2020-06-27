#include <stdio.h>
#include <stdlib.h>

#define MEETING_INTERVAL 30

const char *meeting_time_person1[] = {
    "09:00","10:30",
    "12:00","13:00",
    "16:00","18:00",
};

const char *meeting_time_person2[] = {
    "10:00","11:30",
    "12:30","14:30",
    "14:30","15:00",
    "16:00","17:00",
};

const char *inbound_person1[] = {
    "09:00","20:00",
};

const char *inbound_person2[] = {
    "10:00","18:30",
};

typedef struct person {
    const char **meeting_ptr;
    int meeting_len;
    const char **inbound_ptr;
    int inbound_len;
    char **freetime_ptr;
    int freetime_len;
} person;

typedef struct time {
    int hour;
    int minute;
} time;

person initperson(const char *[],int,const char *[],int);
void intersection_meeting_time(person*,person*);
void cal_free_time(person *); 
time conv_time(char *);
void verify_add_elm_free_time(time,time,person*);
void calloc_new_elm(time,person*);
void realloc_new_elm(time,person*);

#define PARAMINIT(x,y) initperson(x,LEN(x),y,LEN(y)); 
#define LEN(x) sizeof(x)/sizeof(x[0])
#define CONVTIME(x) conv_time((char *)x);

int main()
{
    person p1, p2;

    p1 = PARAMINIT(meeting_time_person1,inbound_person1)
    p2 = PARAMINIT(meeting_time_person2,inbound_person2)

    cal_free_time(&p1);
    cal_free_time(&p2);
    
    intersection_meeting_time(&p1,&p2);

}

person initperson(const char *pm[], int npm, const char *pib[], int npib)
{
    person p;

    p.meeting_ptr = pm;
    p.meeting_len = npm;
    p.inbound_ptr = pib;
    p.inbound_len = npib;
    p.freetime_ptr = NULL;
    p.freetime_len = 0;

    return p;
}

void intersection_meeting_time(person *p1, person *p2)
{   
    time t1,t2,tu,td;
    person r;
    r = PARAMINIT(NULL,NULL)
    int count = (p1->freetime_len <= p2->freetime_len) ? p1->freetime_len/2 : p2->freetime_len/2;
    printf("Interator = %d\n",count);

    for(int i=0;i<count;i++){
        t1 = CONVTIME(p1->freetime_ptr[2*i])
        t2 = CONVTIME(p2->freetime_ptr[2*i])
        if((t1.hour*60+t1.minute) <= (t2.hour*60+t2.minute)){
            tu = t2;
            t1 = CONVTIME(p1->freetime_ptr[2*i+1])
            t2 = CONVTIME(p2->freetime_ptr[2*i+1])

            if((t1.hour*60+t1.minute) <= (t2.hour*60+t2.minute)){
                td = t1;
            }
            else{
                td = t2;
            }

            verify_add_elm_free_time(tu,td,&r); 
        }
        else{
            tu = t1;
            t1 = CONVTIME(p1->freetime_ptr[2*i+1])
            t2 = CONVTIME(p2->freetime_ptr[2*i+1])

            if((t1.hour*60+t1.minute) <= (t2.hour*60+t2.minute)){
                td = t1;
            }
            else{
                td = t2;
            }

            verify_add_elm_free_time(tu,td,&r);

        }
    }

    printf("\n\t\tFree Time Heap: { ");
    for(int i=0;i<r.freetime_len;i++){
        printf("%s ",r.freetime_ptr[i]);
    }
    printf("}\n\n");

}

void cal_free_time(person *p)
{
    time t1,t2;

    t1 = CONVTIME(p->inbound_ptr[0])
    t2 = CONVTIME(p->meeting_ptr[0])
   
    verify_add_elm_free_time(t1,t2,p);

    for(int i=0;i<p->meeting_len/2-1;i++){
        t1 = CONVTIME(p->meeting_ptr[2*i+1])
        t2 = CONVTIME(p->meeting_ptr[2*i+2])

        verify_add_elm_free_time(t1,t2,p);
    }

    t1 = CONVTIME(p->meeting_ptr[p->meeting_len-1])
    t2 = CONVTIME(p->inbound_ptr[1])

    verify_add_elm_free_time(t1,t2,p);

    printf("\n\t\tFree Time Heap: { ");
    for(int i=0;i<p->freetime_len;i++){
        printf("%s ",p->freetime_ptr[i]);
    }
    printf("}\n\n");
}

time conv_time(char *end)
{
    time t;

    t.hour = (int)strtol(end,&end,10);
    t.minute = (int)strtol(end+1,&end,10);

    return t;
}

void verify_add_elm_free_time(time t1,time t2, person *p)
{
    if((t2.hour*60+t2.minute)-(t1.hour*60+t1.minute)>=MEETING_INTERVAL){
        printf("New Element\n");
        if(p->freetime_ptr == NULL){
            calloc_new_elm(t1,p);
            realloc_new_elm(t2,p);
        }
        else{
            realloc_new_elm(t1,p);
            realloc_new_elm(t2,p);
        }
    }
}

void calloc_new_elm(time t, person *p)
{
    printf("\tAllocated:   ");
    p->freetime_ptr = (char **)calloc(++p->freetime_len,sizeof(char *));
    p->freetime_ptr[p->freetime_len-1] = (char *)calloc(6,sizeof(char));
    sprintf(p->freetime_ptr[p->freetime_len-1],"%02d:%02d",t.hour,t.minute);
    printf("%s\n",p->freetime_ptr[p->freetime_len-1]);
}

void realloc_new_elm(time t,person *p)
{
    printf("\tReAllocated: ");
    p->freetime_ptr = (char **)realloc(p->freetime_ptr,++p->freetime_len*sizeof(char *));
    p->freetime_ptr[p->freetime_len-1] = (char *)calloc(6,sizeof(char));
    sprintf(p->freetime_ptr[p->freetime_len-1],"%02d:%02d",t.hour,t.minute);
    printf("%s\n",p->freetime_ptr[p->freetime_len-1]);
}