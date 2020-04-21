#include <stdio.h>
#include <stdlib.h>

char* readinput();

int main()
{
  char* s;
  s=readinput();
  printf("%s",s);
}

char* readinput()
{
  char* s;
  char c;
  int i=0;
  s=(char*)malloc(1*sizeof(char));
  while((c=getchar())!='\n' && c!=EOF){
    s=(char*)realloc(s,(i+1)*sizeof(char));
    s[i]=c;
    i++;
  }
  s[i]='\0';
  
  return s;
}
