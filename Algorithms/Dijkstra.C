#include<stdio.h>
#include<math.h>
#define inf 999
int adj[20][20],weight[20][20];
int path[20];
int n;
void sp(int s,int t)
{
    int i,dc,newdist,mindist,current,l,x;
    int dist[20],nodeset[20];
    for(i=1;i<=n;i++)
    {
        dist[i]=inf;
        nodeset[i]=0;
    }
    current=s;
    dist[current]=0;
    nodeset[current]=1;
    while(current!=t)
    {
        dc=dist[current];
        for(i=1;i<=n;i++)
        {
            if(adj[current] && !(nodeset[i]))
            {
                newdist=dc+weight[current][i];
                if(newdist<dist[i])
                {
                    dist[i]=newdist;
                    path[i]=current;
                }
            }
        }
        mindist=inf;
        for(i=1;i<=n;i++)
            if(!(nodeset[i]) && (dist[i]<mindist))
            {
                mindist=dist[i];
                current=i;
            }
        nodeset[current]=i;
    }
    printf("%d\nPATH:",dist[t]);
    l=t;
    printf("  %d",t);
    do
    {
        x=path[l];
        printf("<--%d",x);
        l=x;
    }
    while(l!=s);
}
int main()
{
     int i,j,s,t;
 //clrscr();
 printf("Enter no. of Vertices:\n");
 scanf("%d",&n);
 printf("Enter Adjecency\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   {
    if(i==j)
    {
      adj[i][j]=0;
    }
    else
    {
     printf("Enter Adjecency(0 or 1) %d %d :",i,j);
     scanf("%d",&adj[i][j]);
    }
   }
for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
    weight[i][j]=inf;
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   {
    if(i==j)
     weight[i][j]=0;
    else
    {
    if(adj[i][j]==1)
    {
     printf("Weight of edge %d %d :",i,j);
     scanf("%d",&weight[i][j]);
    }
    }
   }
 printf("Enter Source vertex.\n");
 scanf("%d",&s);
 printf("Enter Destination vertex.\n");
 scanf("%d",&t);
 sp(s,t);
    return 0;
}
