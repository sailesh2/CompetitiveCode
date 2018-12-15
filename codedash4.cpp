#include<stdio.h>
#include<iostream>

using namespace std;

void fun(int m,int n)
{
    int i,j, k = 0, l = 0;
    int a[m][n];
    int m1=m,n1=n;
    int ctr=1;

    while (k < m && l < n)
    {
        for (i = l; i < n; ++i)
        {
           a[k][i]=ctr++;
        }
        k++;

        for (i = k; i < m; ++i)
        {
            a[i][n-1]=ctr++;
        }
        n--;

        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                a[m-1][i]=ctr++;
            }
            m--;
        }

        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                a[i][l]=ctr++;
            }
            l++;
        }
    }
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
            cout<<a[j][i]<<" ";
        cout<<"\n";
    }
}

int main()
{
    int i,t,x,y;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x;
        fun(x,x);
    }
    return 0;
}
