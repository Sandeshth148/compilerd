#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include "main.h"
#include "parser.c"

int main(int argc,char* argv[])
{
 int fd,ttracker=0,ivar=0,t=0,i;
 char *a ;
 char in;
 char token[20]={'\0'};

/*
//testing
printf("\n%d\n",getIndex("$s"));
return 0;
//testing
*/
tokens.top=-1;

push(&tokens,"$");
 if(argc<2)
{
	printf("Error: Input file unspecified %d",']');
	exit(0);
 }
  fd = open(argv[1],O_RDONLY);
  while((read(fd,&in,1))==1){
    if(in==59||in==61||in==45||in==62||in==91||in==93||in=='('||in==')'){
      if(ttracker)
      push(&tokens,token);
      while(ttracker--){
  			token[ttracker]='\0';
  		}
      ttracker=0;
      token[0]=in;
      push(&tokens,token);
    }
    else if(in==32||in==10)
{
		 if(ttracker==0){
			continue;
		}
		//printf("\ntoken : %s",token);

    push(&tokens,token);
		token[ttracker]='\0';
		while(ttracker--){
			token[ttracker]='\0';
		}
		ttracker=0;
        }
	else{
		token[ttracker] = in;
		ttracker++;
	}
  }
  parse(&tokens);
/*
  while(tokens.top){
    printf("\ntoken : %s",pop(&tokens));
  }*/


  printf("\n");
  close(fd);
}
