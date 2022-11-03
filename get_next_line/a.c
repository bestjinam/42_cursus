#include <unistd.h>
#include <stdlib.h>

char *_(size_t a,int b){char*t,c=0,k=read(b,&c,1);if(k<0||(k==0&&a==0))return NULL;if(k==0||c=='\n')t=malloc(a+2);else t=_(a+1,b);if(t)t[a]=c,t[a+1]=t[a+1]*(c!='\n'); return t;}
char *get_next_line(int fd){return _(0,fd);}
