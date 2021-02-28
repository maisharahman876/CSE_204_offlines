#include<bits/stdc++.h>
using namespace std;
int maximum(int a,int b)
{
    if(b>=a)
        return b;
    else
        return a;
}
char* Lcs(char x[], char y[])
{
    int m=0,n=0;


    for(int i=0;x[i];i++)
    {
        m++;
    }

     for(int i=0;y[i];i++)
    {
        n++;
    }

    int c[m+1][n+1];
    for(int i=0 ;i<= m; i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0) c[i][j]=0;
            else
            {
                if (x[i-1] == y[j-1]) c[i][j] = c[i-1][j-1] + 1;
                else c[i][j] = maximum(c[i-1][j], c[i][j-1]);
            }
        }
    }
    int len = c[m][n];
    char * lcs = new char[len + 1];
    lcs[len]='\0';
    int k = m;
    int l= n;
    while (k > 0 && l > 0)
    {
      if (x[k-1] == y[l-1])
      {
          lcs[len-1] = x[k-1];
          k--;
          l--;
          len--;
      }
      else if (c[k-1][l]>c[k][l-1])
         k--;
      else
         l--;
   }
   return lcs;

}


int main()
{
  char y[100],z[100];
    cout<<"Input the two sequence : ";
    cin>>y;
    cout<<"Another sequence : ";
    cin>>z;


    cout<<Lcs(y,z);
    return 0;
}
