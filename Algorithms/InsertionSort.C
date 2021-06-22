#include<stdio.h>
#define MAX 100
int main()
{
 int a[MAX],i,j,n,x,k;
 printf("Enter the number of elements.\n");
 scanf("%d",&n);
 //scan the elements
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 if(n==1)
     printf("Sorted array: %d",a[0]);
 else if(n==2)
     if(a[0]>a[1])
         printf("Sorted array: %d %d",a[1],a[0]);
     else
         printf("Sorted array: %d %d",a[0],a[1]);
 else
 {
     for(j=1;j<n;j++)
     {
         x=a[j];
         k=j-1;
     while(k>=0&&a[k]>x)
     {
         a[k+1]=a[k];
         k--;
     }
     a[k+1]=x;
     }
 //print sorted array
     printf("Sorted array.\n");
     for(i=0;i<n;i++)
     printf("%d ",a[i]);
}
 return 0;
}
