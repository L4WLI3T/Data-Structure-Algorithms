#include<stdio.h>
int part (int a[],int lb,int ub)
{
 int down,up,x,temp;
 down=lb;
 up=ub;
 x=a[lb];
 while(down<up)
 {
  while(a[down]<=x&&down<up)
  down++;
  while(a[up]>x)
   up--;
  if(down<up)
   {
    temp=a[down];
    a[down]=a[up];
    a[up]=temp;
   }
 }
 a[lb]=a[up];
 a[up]=x;
 return up;
}
void qs(int a[], int lb, int ub)
{
 int j;
 if(lb<ub)
 {
  j=part(a,lb,ub);
  qs(a,lb,j-1);
  qs(a,j+1,ub);
 }
}
int main()
{
 int a[100],n,i;
 printf("Enter number of elements.\n");
//scans the number of total elements
 scanf("%d",&n);
 printf("Enter the elements.\n");
//scans the elements
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
//calls the function for quicksort
 if(n==1)
     printf("Sorted array: %d",a[0]);
 else if(n==2)
     if(a[0]>a[1])
         printf("Sorted array: %d %d",a[1],a[0]);
     else
         printf("Sorted array: %d %d",a[0],a[1]);
 else
 {
    qs(a,0,n-1);
    printf("Sorted array.\n");
//prints the sorted array
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
 }
return 0;
}
