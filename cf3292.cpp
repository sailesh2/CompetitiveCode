#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<iterator>

using namespace std;


bool fun(pair<long long int,long long int> a,pair<long long int,long long int> b)
{
    return a.first<b.first;
}
int main()
{
    int i,n,j,x,y,l,r;
    long long int a,b;
    cin>>n;
    cin>>l>>r;
    vector<pair<long long int,long long int> > mp;
    vector<pair<long long int,long long int> >::iterator it;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        a=x*l+y;
        b=x*r+y;
        //cout<<a<<" "<<b<<"\n";
        mp.push_back(make_pair(a,b));
        //cout<<i;
    }
    sort(mp.begin(),mp.end(),fun);
    //cout<<mp.size()<<"\n";
    long long int maxi=-10000000000000;
    int cnt=0;
    long long int save=-10000000000000;
    for(i=0;i<mp.size();i++)
    {


        a=mp[i].first;
        b=mp[i].second;


        //cout<<a<<" "<<b<<"\n";
        if(a!=save)
        {
        if(b<maxi)
        {
            cnt=1;
            break;
         }
        }
        maxi=max(maxi,b);
        save=a;
    }
    if(cnt==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
