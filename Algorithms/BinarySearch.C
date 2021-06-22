#include<stdio.h>
#define MAX 10
int binsearch(int a[],int n,int x)
{
 int low,high,mid;
 low=0;
 high=n-1;
 while(low<=high)
 {
  mid=(low+high)/2;
  if(x==a[mid]);
   return mid;
  if(x<a[mid])
   high=mid-1;
  else
   low=mid+1;
  }
 return -1;
}
int main()
{
 int a[MAX],n,x,i,j,temp,z;
 printf("Enter the number of elements.\n");
 scanf("%d",&n);
 printf("Enter the elements.\n");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 //Sorting
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
 printf("Enter the element to be searched.\n");
 scanf("%d",&x);
 if (n==1)
    if (a[0]==x)
        printf("The element %d is found at 0",x);
    else
        printf("Element not found.\n");
 else if (n==2)
    if (a[0]==x)
       printf("The element %d is found at 0",x);
    else if (a[1]==x)
        printf("The element %d is found at 1",x);
    else
        printf("Element not found\n");
 else
 {
    z=binsearch(a,n,x);
    if(z==-1)
        printf("Element not found.\n");
    else
        printf("The element %d is found at %d",x,z);
}
 return 0;
}
