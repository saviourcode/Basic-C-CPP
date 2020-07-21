#ifndef _LIBSTROBJ_H_
#define _LIBSTROBJ_H_

#include <stdio.h>
#include <stdlib.h>

#define BLANK {NULL,0}
#define String static string

typedef struct string{
     char* str;
     int size;
}string;

#include "garcol.h"

void append(string*,char);
void appendStr(string*,char*);
void scanStr(string*);


#endif