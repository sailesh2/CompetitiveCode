#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main()
{
    int i,j,n,m,save,save2,ctr;
    cin>>n>>m;
    long long int x,y;
    long long int arr[n][2],ans[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    vector<long long int> v;
    map<long long int,int> mp;
    for(i=0;i<m;i++)
    {
        cin>>x;
        v.push_back(x);
        mp.insert(make_pair(x,i+1));
    }
    sort(v.begin(),v.end());
    int cnt=0;
    for(i=0;i<n-1;i++)
    {
        x=arr[i+1][0]-arr[i][1];
        y=arr[i+1][1]-arr[i][0];
        ctr=1;
        save=-1;
        save2=-1;
        while(1)
        {
            save=save2;
            while(v[save+ctr]<x)
            {
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2)
                break;
            ctr=1;
        }
        if(v[save+ctr]<x)
        {
            cnt=1;
            break;
        }
        else
        {
            if(v[save+ctr]>y)
            {
                cnt=1;
                break;
            }
            else
            {
                ans[i]=v[save+ctr];
                v.erase(v.begin()+save+ctr);
            }
        }
    }
    if(cnt==0)
    {
        cout<<"YES\n";
        for(i=0;i<n-1;i++)
        {
            cout<<mp[ans[i]]<" ";
        }
    }
    else
        cout<<"NO";
    return 0;
}
