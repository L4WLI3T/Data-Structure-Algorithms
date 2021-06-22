#include<stdio.h>
#define MAX 100
int main()
{
 int a[MAX],i,j,n,pos,large;
 printf("Enter the number of elements.\n");
 scanf("%d",&n);
 //scan the elements
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 for(j=n-1;j>=1;j--)
 {
     large=a[0];
     pos=0;
     for(i=1;i<=j;i++)
     {
         if(a[i]>large)
         {
             large=a[i];
             pos=i;
         }
     }
     a[pos]=a[j];
     a[j]=large;
 }
 //print sorted array
 printf("Sorted array.\n");
 for(i=0;i<n;i++)
  printf("%d ",a[i]);
 return 0;
}
