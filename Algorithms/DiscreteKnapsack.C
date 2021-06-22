#include<stdio.h>
#include<math.h>
#define MAX 20
int n=7;
int wi[MAX]={3,7,4,7,3,3,10},bi[MAX]={5,3,4,8,2,1,6};
int B[MAX][MAX];
int m=15;
int i,w;
void ks()
{
    for(w=0;w<=m;w++)
        B[0][w]=0;
    for(i=1;i<=n;i++)
        B[i][0]=0;
    for(i=1;i<=n;i++)
        for(w=1;w<=m;w++)
            if(wi[i]<=m)
                if((bi[i]+(B[i-1][w-wi[i]]))>B[i-1][w])
                    B[i][w]=bi[i]+B[i-1][w-wi[i]];
                else
                    B[i][w]=B[i-1][w];
            else
                B[i][w]=B[i-1][w];
    for(i=1;i<=n;i++)
        for(w=1;w<=m;w++)
            printf("%d%d",B[i][w]);
}
int main()
{
    ks();
    return 0;
}
