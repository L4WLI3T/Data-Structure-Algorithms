#include<stdio.h>
//#include<conio.h>
#include<math.h>
#define MAX 20
int n=7;
float w[MAX]={3,7,4,7,3,3,10},p[MAX]={5,3,4,8,2,1,6};
float m=15;
void sort()
{
 int i,j;
 float s[MAX],t1=0.0,t2=0.0,t3=0.0;
 for(i=0;i<n;i++)
  s[i]=(p[i]/w[i]);
 //for(i=0;i<n;i++)
   //printf("%f\n",s[i]);
 for(i=n-1;i>0;i--)
  for(j=0;j<i;j++)
  {
   if(s[j]<s[j+1])
   {
    t1=s[j];
    s[j]=s[j+1];
    s[j+1]=t1;
    t2=p[j];
    p[j]=p[j+1];
    p[j+1]=t2;
    t3=w[j];
    w[j]=w[j+1];
    w[j+1]=t3;
   }
  }
  for(i=0;i<n;i++)
   printf("%f\n",s[i]);
}
float ks()
{
 float x[MAX]={0};
 float cp,mp=0.0;
 int i;
 cp=m;
 sort();
 i=0;
 while(i<n&&w[i]<=cp)
 {
  x[i]=1;
  cp=cp-w[i];
  i++;
 }
 if(i<n)
  x[i]=cp/w[i];
 for(i=0;i<n;i++)
  mp=mp+x[i]*p[i];
 return mp;
}
int main()
{
 //int i;
 float r;
 //clrscr();
 /*printf("Enter no. of items\n");
 scanf("%d",&n);
 printf("Enter max Cap.\n");
 scanf("%f",&m);
 for(i=1;i<=n;i++)
 {
  printf("Enter Weight and Profit\n");
  scanf("%f %f",&w[i],&p[i]);
 }*/
 r=ks();
 printf("Max Profit : %f",r);
// getch();
 return 0;
}
