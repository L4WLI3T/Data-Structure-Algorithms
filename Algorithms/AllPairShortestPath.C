#include<stdio.h>
//#include<conio.h>
#include<math.h>
#define MAX 50
int a[MAX][MAX],cost[MAX][MAX];
int min(int a,int b)
{
 if(a<b)
  return a;
 else
  return b;
}
void allpair(int n)
{
 int i,j,k;
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   a[i][j]=cost[i][j];
 for(k=1;k<=n;k++)
 {
  printf("\nA%d ",k);
  for(i=1;i<=n;i++)
   printf(" %d ",i,i);
  printf("\n");
  for(i=1;i<=n;i++)
  {
   printf(" %d ",i);
   for(j=1;j<=n;j++)
    printf(" %d ",a[i][j]);
   printf("\n");
  }
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
 }
}
int main()
{
 int i,j,n;
 //clrscr();
 printf("Enter no. of Vertices:\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   if(i!=j)
   {
    printf("Cost of edge %d %d :",i,j);
    scanf(" %d",&cost[i][j]);
   }
   else
    cost[i][j]=0;
 allpair(n);
 printf("Shortest path : \n");
 printf("   ");
 for(i=1;i<=n;i++)
  printf(" %d ",i);
 printf("\n");
 for(i=1;i<=n;i++)
 {
  printf(" %d ",i);
  for(j=1;j<=n;j++)
   printf(" %d ",a[i][j]);
  printf("\n");

 }
 return 0;
 //getch();
}
