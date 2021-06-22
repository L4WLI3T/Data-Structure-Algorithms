#include<stdio.h>
#include<stdlib.h>
int x[20],counter;
int place(int k,int i)
{
    int j;
    for(j=1;j<k;j++)
        if(x[j]==i||(abs(x[j]-i)==abs(j-k)))
            return 0;
    return 1;
}
void nq(int k,int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                printf("%d  ",++counter);
                for(j=1;j<=n;j++)
                    printf(" %d",x[j]);
                printf("\n");
            }
            else
                nq(k+1,n);
        }
    }
}
int main()
{
    int i,n;
    printf("Enter no. of Queens.\n");
    scanf("%d",&n);
    nq(1,n);
    printf("No. of solution:%d",counter);
    return 0;
}
