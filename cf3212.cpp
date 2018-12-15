#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool fun(pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}

int main()
{
    int i,n,d,x,m,s;
    cin>>n>>d;
    vector<pair<int,int> > v;
    for(i=0;i<n;i++)
    {
        cin>>m>>s;
        v.push_back(make_pair(m,s));
    }
    sort(v.begin(),v.end(),fun);
    //long long int sum[n];
    long long int sm=0;
    /*for(i=0;i<n;i++)
    {
        sm=sm+v[i].second;
        sum[i]=sm;
    }*/
    int j=0;
    i=0;
    long long int maxi=0;
    while(i<=j && i<n && j<n)
    {
        while(j<n && v[j].first-v[i].first<d)
        {
            sm=sm+v[j].second;
            //cout<<sm<<"\n";
            if(sm>maxi)
                maxi=sm;
            j++;
        }
        if(j<n)
        {
            while(i<=j && v[j].first-v[i].first>=d)
            {
                sm=sm-v[i].second;
                i++;
            }
        }
    }
    cout<<maxi;
    return 0;
}
