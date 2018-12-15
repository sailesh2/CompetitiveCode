#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[100002]={0};
int fun(int,int*);

int main()
{
    int i,n,x,y,val,ctr,save,save2;
    cin>>n;
    vector<pair<int,int> > v;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(pair<int,int>(x,y));
    }
    int arr[v.size()];
    sort(v.begin(),v.end());
    for(i=v.size()-1;i>=0;i--)
    {
        val=v[i].first-v[i].second;
        if(val<0)
            val=0;
        save=i;
        ctr=1;
        save2=i;
        while(1)
        {
            save=save2;
            ctr=1;
            while(save-ctr>=0 && v[save-ctr].first>=val)
            {
                save2=save-ctr;
                ctr=ctr*2;
            }
            if(save2==save)
                break;
        }
        arr[i]=save;
    }
    int brr[v.size()];
    for(i=0;i<v.size();i++)
    {
        if(dp[i]!=0)
            val=dp[i];
        else
            val=fun(i,arr);
        brr[i]=val;
        //cout<<brr[i]<<" ";
    }
    int mini=1000000000;
    for(i=0;i<v.size();i++)
    {
        if(i+1-brr[i]+v.size()-i-1<mini)
            mini=i+1-brr[i]+v.size()-i-1;
    }
    cout<<mini;
    return 0;
}
int fun(int i,int * arr)
{
    if(arr[i]==0)
        return 1;
    int v;
    if(dp[arr[i]-1]!=0)
        v=dp[arr[i]-1];
    else
        v=fun(arr[i]-1,arr);
    v++;
    dp[i]=v;
    return v;
}
