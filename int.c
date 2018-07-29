#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int r=0,c=0;
char item[50],item[50];
char a[25][25][11]={
{"S","K","$"},
{"K","int","A","$"},
{"K","begin","$"},
{"K","endif","$"},
{"K","end","$"},
{"K","return ","R","D","R","$"},
{"K","if","B","$"},
{"A","main","(",")","$"},
{"A","D","R","10","R",";","$"},
{"A","T","R","0",";","$"},
{"A","M","R","D","R","10","R",";","$"},
{"B","D","R","T","R","R","M","$"},
{"D","l","$"},
{"T","i","$"},
{"M","maxval","$"},
{"R","[","$"},
{"R","]","$"},
{"R","(","$"},
{"R",")","$"},
{"R","=","$"},
{"R",">","$"},
{"K","maxval","R","D","R","T","R",";","$"}
};

char b[40][40][10]={
{"S","int","0"},
{"S","if","0"},
{"S","begin","0"},
{"S","end","0"},
{"S","endif","0"},
{"S","return","0"},
{"S","maxval","0"},
{"K","int","1"},
{"K","begin","2"},
{"K","maxval","21"},
{"K","endif","3"},
{"K","end","4"},
{"K","return","5"},
{"K","if","6"},
{"A","main","7"},
{"A","l","8"},
{"A","i","9"},
{"A","maxval","10"},
{"B","l","11"},
{"D","l","12"},
{"T","i","13"},
{"M","maxval","14"},
{"R","[","15"},
{"R","]","16"},
{"R","(","17"},
{"R",")","18"},
{"R","=","19"},
{"R",">","20"},

};
int prod(int x , char str[]);
char stack[10][110];
char queue[10][100];
char *token;
int count;
int l=0,i,k,front=0,rear=-1,state=1,r;
char str[50],stp[100];
int main()
{
int x;
strcpy(stack[r],"S");//intialization
printf("\n Enter the line to be parsed\n Enter $ to indicate your termination\n");
while(strcmp(queue[rear],"$")!=0)
{
rear++;
scanf("%s",queue[rear]);
}
l1:
strcpy(stp,queue[front]);//
if((strcmp(stp,")")==0)||(strcmp(stp,"(")==0)||(strcmp(stp,";")==0)||(strcmp(stp,",")==0)||
(strcmp(stp,"1")==0)||(strcmp(stp,"0")==0))
{
printf("%s parsed\n",stp);
front++;
r++;
goto l1;
}
while(strcmp(stp,"$")!=0)
{
for(i=0;i<40;i++)
{
strcpy(str,stack[r]);
strcpy(stp,queue[front]);
if((strcmp(b[i][0],str)==0)&&(strcmp(b[i][1],stp)==0))// comparing from the starting production
{
x=atoi(b[i][2]);//you have taken the prod no now
r=prod(x,str);
}
else if((strcmp(str,stp))==0)
{
strcpy(item,queue[front]);
printf("%s parsed\n",item);
front++;
strcpy(str,queue[front]);
strcpy(item,stack[r]);
r++;
goto l1;
}
}
}
if(strcmp(stack[r],"\0")!=0)
{
printf("\n not correct syntax\n");
}
printf("line code is Accepted\n");
return 0;
}
int prod(int x,char str[])
{
char stq[100];
int y=1,count=0;
printf("%s ->",a[x][0]);//outputing the non terminal eg X->
l2 : strcpy(stq,a[x][y]);//terminal symbols in stq
while(strcmp(stq,"$")!=0)//comparing till the $
{
strcpy(str,stq);
printf("%s",str);//printing the productions
strcpy(stack[r],str);
count++;
r++;
y++;
goto l2;
}
if(count>r)
{
r = count-r;
}
else
{
r = r-count;
}
printf("\n");
return r;
}
