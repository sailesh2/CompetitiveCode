#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,j,n;
    cin>>n;
    int arr[n+1];
    for(i=0;i<n;i++)
    {
        cin>>arr[i+1];
    }
    vector<vector<long long int> > sum;
    for(i=1;i<=n;i++)
    {
        vector<long long int> v
        sm=0;
        for(j=1;j<=n;j=j+i)
        {
            sm=sm+arr[j];
            v.push_back(sm);
        }
        sum.push_back(v);
    }
    int q;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>x>>y;

    }

    return 0;
}
