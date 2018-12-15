#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool fun(pair<int,int> a,pair<int,int> b)
{
    return a.second>b.second;
}

int main()
{
    int i,j,n,q,x;

    cin>>n>>q;
    vector< pair<int,int> > v;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(make_pair(x,0));
    }
    for(i=0;i<n;i++)
    {
        cin>>x;
        v[i].second=x;
    }
    sort(v.begin(),v.end(),fun);
    long long int sum[n];
    sum[0]=v[0].first;
    for(i=1;i<n;i++)
        sum[i]=sum[i-1]+v[i].first;
    for(i=0;i<q;i++)
    {
        cin>>x;
        cout<<sum[x-1]<<"\n";
    }
    return 0;
}
