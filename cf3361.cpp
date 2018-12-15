#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int i,n,s,x,y,save;
    long long int sm=0;
    cin>>n>>s;
    vector<pair<int,int> > v;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(pair<int,int>(x,y));
    }
    sort(v.begin(),v.end());
    save=s;
    for(i=v.size()-1;i>=0;i--)
    {
        if(save>=v[i].first)
        {
            if(sm+save-v[i].first>v[i].second)
                sm=sm+save-v[i].first;
            else
                sm=v[i].second;
            save=v[i].first;
        }
    }
    sm=sm+save;
    cout<<sm;
    return 0;
}
