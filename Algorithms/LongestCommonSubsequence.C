#include<stdio.h>
#include<string.h>
#define mx 20
char X[mx],Y[mx];
int max(int a, int b);
void lcs(int m, int n )
{
   int L[m+1][n+1];
   int i, j;
   for (i=0; i<=m; i++)
     for (j=0; j<=n; j++)
      {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }

  int index=L[m][n];
  char ls[index + 1];
  ls[index] = '\0';

  int c = m, d = n;
  while (c > 0 && d > 0)
  {
    if (X[c - 1] == Y[d - 1])
    {
      ls[index - 1] = X[c - 1];
      c--;
      d--;
      index--;
    }
    else if (L[c - 1][d] > L[c][d - 1])
      c--;
    else
      d--;
  }
  printf("Length(LCS): %d\nLCS: %s",strlen(ls),ls);
}
int max(int a, int b)
{
    return (a > b)? a : b;
}

int main()
{
  printf("Enter 1st string.\n");
  gets(X);
  printf("Enter 2nd string.\n");
  gets(Y);
  int p = strlen(X);
  int q = strlen(Y);
  lcs(p,q);
  return 0;
}
