#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int i,n,q,l,k,val;
    cin>>n>>q;
    vector<int> v;
    int brr[n];
    for(i=0;i<n;i++)
    {
        cin>>brr[i];
        v.push_back(brr[i]);
    }
    sort(brr,brr+n);
    int has[100001]={0};
    int query[n+1];
    for(i=0;i<q;i++)
    {
        cin>>l>>k;
        has[l]=i+1;
        query[l]=k;
    }
    int ans[q+1];
    for(i=0;i<n;i++)
    {
        val=brr[i];
        //cout<<val<<" "<<has[val]<<" "<<query[val]<<"\n";
        if(has[val]!=0)
        {
            ans[has[val]]=v[query[val]-1];
        }
        v.erase(find(v.begin(),v.end(),val));
    }
    for(i=1;i<=q;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
