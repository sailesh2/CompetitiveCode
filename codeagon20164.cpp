#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;


pair<int,int> fun(string str)
{
   int n = str.length();
   int o,i, j, cl,k,maxi=0;
   int L[n][n];


   for (i = 0; i < n; i++)
      L[i][i] = 1;

    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
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

    o=L[0][n-1];


    for(j=0;j<n;j++)
    {
        for(k=j+1;k<n;k++)
        {
            if(str[j]==str[k])
            {
                if(j+1<=k-1 && L[j+1][k-1]+2>maxi)
                    maxi=L[j+1][k-1];
            }
        }
    }

    return pair<int,int>(o,maxi);
}

int main()
{
    int i,j,t,e1,e2,o1,o2;
    string s1,s2;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s1>>s2;
        pair<int,int> p=fun(s1);
        e1=p.second;
        o1=p.first;


        p=fun(s2);
        e2=p.second;
        o2=p.first;

        cout<<max((e1+e2),max((e1+o2),(e2+o1)))<<"\n";
    }
}
