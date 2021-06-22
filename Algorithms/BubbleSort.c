#include<stdio.h>
#include<conio.h>
#define MAX 20
int a[MAX];
void bubblesort(int n)
{
 int i=0,j=0;
 int temp;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
}
void main()
{
 int i,n;
 clrscr();
 printf("Enter the number of elements.\n");
 scanf("%d",&n);
 printf("Enter the elements.\n");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 bubblesort(n);
 for(i=0;i<n;i++)
  printf("%d",a[i]);
 getch();
}