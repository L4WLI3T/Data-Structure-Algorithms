#include<stdio.h>
#include<conio.h>
#define MAX 20
int a[MAX];
void combine(int down,int mid,int up)
{
 int temp[MAX];
 int i,j,k;
 i=down;
 k=down;
 j=mid+1;
 while(i<=mid&&j<=up)
 {
  if(a[i]<=a[j])
   temp[k++]=a[i++];
  else
   temp[k++]=a[j++];
 }
 while(i<=mid)
  temp[k++]=a[i++];
 while(j<=up)
  temp[k++]=a[j++];
 for(k=down;k<=up;k++)
  a[k]=temp[k];
}
void mergesort(int down,int up)
{
 int mid;
 if(down<up)
 {
  mid=(down+up)/2;
  mergesort(down,mid);
  mergesort(mid+1,up);
  combine(down,mid,up);
 }
}
void main()
{
 int i,n,down,up;
 clrscr();
 printf("Enter the number of elements to be sorted.\n");
 scanf("%d",&n);
 printf("Enter the elements.\n");
 for(i=1;i<=n;i++)
  scanf("%d",&a[i]);
 down=1;
 up=n;
 mergesort(down,up);
 printf("Sorted array is.\n");
 for(i=1;i<=n;i++)
  printf("%d\n",a[i]);
 getch();
}