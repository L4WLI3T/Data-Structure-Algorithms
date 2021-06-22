#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
char ms[20],ps[10];
int pmbf(int lm,int lp)
{
 int flag,i,j;
 int mx=lm-lp+1;
 for(i=0;i<mx;i++)
 {
  flag=1;
  for(j=0;j<lp&&flag==1;j++)
  {
   if(ps[j]!=ms[j+i-1])
    flag=0;
  }
  if(flag==1)
   return i;
 }
 return 0;
}
int main()
{
 int lm,lp,x,i;
 //clrscr();
 printf("Enter main string.\n");
 gets(ms);
 lm=strlen(ms);
 printf("Enter pattern string.\n");
 gets(ps);
 lp=strlen(ps);
 x=pmbf(lm,lp);
 if (x==0)
  printf("Not found.\n");
 else
  printf("Found at : %d",x);
 return 0;
}
