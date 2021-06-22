#include<stdio.h>
//#include<conio.h>
#include<math.h>
#define MAX 50
#define INF 999
int a[MAX][MAX],cost[MAX][MAX],dist[MAX];
void sssp(int v,int n)
{
 int i,k,u,j;
 for(i=1;i<=n;i++)
  dist[i]=cost[v][i];
 for(k=2;k<=n;k++)
  for(u=1;u<=n;u++)
   for(i=1;i<=n;i++)
    {
     if(a[i][u]==1)
      {
       if(dist[u]>(dist[i]+cost[i][u]))
       {
        dist[u]=dist[i]+cost[i][u];
       }
      }
    }
}
int main()
{
 int i,j,n,s;
 //clrscr();
 printf("Enter no. of Vertices:\n");
 scanf("%d",&n);
 printf("Enter Adjecency\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   {
    if(i==j)
    {
      a[i][j]=0;
    }
    else
    {
     printf("Enter Adjecency(0 or 1) %d %d :",i,j);
     scanf("%d",&a[i][j]);
    }
   }
for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
    cost[i][j]=INF;
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   {
    if(i==j)
     cost[i][j]=0;
    else
    {
    if(a[i][j]==1)
    {
     printf("Cost of edge %d %d :",i,j);
     scanf("%d",&cost[i][j]);
    }
    }
   }
 printf("Enter Source vertex.\n");
 scanf("%d",&s);
 sssp(s,n);
 for(i=1;i<=n;i++)
  printf("Dist from %d to %d : %d\n",s,i,dist[i]);
 return 0;
 //getch();
}
