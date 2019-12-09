#include <stdio.h>
#include <string.h>
#include "greeting.h"
int verifier(char login[],char password[])
{
char log[20];
char pass[20];
int k=0;
int r;
FILE*f;
f=fopen("/home/firas/Projects/project3/src/users.txt","r");

while(fscanf(f,"%s %s %d ",log,pass,&r)!=EOF)
{ if ( strcmp(login,log)==0 && strcmp(password,pass)==0) 
{k=r ;}
}
return k;
}
