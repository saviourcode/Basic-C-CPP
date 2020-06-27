#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_MEETING_PERSON1 3
#define NUMBER_OF_MEETING_PERSON2 4

#define MEETING_INTERVAL 30

void calculate_free_time(const char **,const char **);

const char *meeting_time_person1[6] = {
    "9:00","10:30",
    "12:00","13:00",
    "16:00","18:00",
};

const char *meeting_time_person2[8] = {
    "10:00","11:30",
    "12:30","14:30",
    "14:30","15:00",
    "16:00","17:00",
};

const char *inbound_person1[2] = {
    "9:00","20:00",
};

const char *inbound_person2[2] = {
    "10:00","18:30",
};

int main()
{
    printf("%p\n",&meeting_time_person1[0]);
    printf("%p\n",&meeting_time_person1[1]);
    calculate_free_time(meeting_time_person1,inbound_person1);
}

void calculate_free_time(const char **pm,const char **pib)
{
    printf("%s\n",*(pm+1));
}