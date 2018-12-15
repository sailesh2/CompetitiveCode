#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int max (int x, int y) { return (x > y)? x : y; }

int lps(string str,int st,int en)
{
   int n = str.length();
   int i, j, cl;
   int L[n][n];


   for (i = st; i <=en; i++)
      L[i][i] = 1;

    for (cl=2; cl<=n; cl++)
    {
        for (i=st; i<=en-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }

    return L[st][en];
}

int main()
{
    int i,n,maxi,p;
    string seq;
    cin>>seq;
    n = seq.length();
    maxi=0;
    for(i=0;i<n-1;i++)
    {
        p=lps(seq,0,i)*lps(seq,i+1,n-1);
        if(p>=maxi)
            maxi=p;
    }
    cout<<maxi;
    return 0;
}
