#include<stdio.h>
float a[20]={1,0,-3,22,2,-4};
int n=6;
int main()
{ int i,j;
float t1;
 for(i=n-1;i>=0;i--)
  for(j=0;j<=i-1;j++)
  {
   if(a[i]>a[j])
   {
    t1=a[i];
    a[i]=a[j];
    a[j]=t1;
    /*t2=p[i];
    p[i]=p[j];
    p[j]=t2;
    t3=w[i];
    w[i]=w[j];
    w[j]=t3;*/
   }
  }
  for(i=0;i<=n-1;i++)
   printf("%f\n",a[i]);

 return 0;
}
