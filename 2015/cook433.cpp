#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>

using namespace std;

bool fun(pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}



int main()
{
    int i,n,m,f,idx,val;
    cin>>n;
    int mrr[n];
    int frr[n];
    vector<pair<int,int> > v,mf;
    map<int,int> mp;
    map<int,int>::iterator it;
    for(i=0;i<n;i++)
    {
        cin>>m>>f;
        frr[i]=f;
        v.push_back(make_pair(m,f));
    }
    sort(frr,frr+n);
    for(i=0;i<n;i++)
    {
        mp.insert(make_pair(frr[i],i));
    }
    for(i=0;i<n;i++)
    {
        it=mp.find(v[i].second);
        mf.push_back(make_pair<int,int>(v[i].first,it->second));
    }
    sort(mf.begin(),mf.end(),fun);
    int sm[100001]={0},sum;
    long long int cnt=0;
    for(i=0;i<mf.size();i++)
    {
        idx=mf[i].second+1;
        sum = 0;
        while (idx > 0)
        {
            sum = (sum + sm[idx-1]);
            idx -= (idx & -idx);
        }
        cnt=cnt+mf[i].second-sum;
        idx=mf[i].second+1;
        val=1;
        while (idx <=mf.size())
        {
            sm[idx-1] = (sm[idx-1] + val);
            idx += (idx & -idx);
        }
    }
    cout<<cnt;
    return 0;
}
