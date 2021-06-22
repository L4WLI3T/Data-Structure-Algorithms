#include<stdio.h>
void subsetsum_Backtracking(int Set[] , int pos, int sum, int tmpsum, int size, bool & found)
        {
            if (sum == tmpsum)
                found = true;
                // generate nodes along the breadth
            for (int i = pos; i < size; i++)
            {
             if (tmpsum + Set[i] <= sum)
               {
                  tmpsum += Set[i];
                  // consider next level node (along depth)
                  subsetsum_Backtracking(Set, i + 1, sum, tmpsum, size, found);
                  tmpsum -= Set[i];
                }
            }
        }

    int main()
    {
        int i, n, sum;
        int S;
        printf("Enter the number of elements in the set" );
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
          scanf("%d",&a[i]);
        printf("Enter value of sum\n");
        scanf("%d",&sum);
        bool f = false;
        subsetsum_Backtracking(a, 0, sum, 0, n, f);
        if (f)
           printf("subset with the given sum found");
        else
           printf("no required subset found" );
        return 0;
    }
