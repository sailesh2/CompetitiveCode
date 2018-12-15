#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iterator>

using namespace std;

int main()
{
    int i,j,n,m,save,save2,ctr;
    cin>>n>>m;
    vector<pair<long long int,int> > v2;
    long long int x,y;
    long long int arr[n][2],ans[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    for(i=0;i<n-1;i++)
    {

        x=arr[i+1][0]-arr[i][1];
        y=arr[i+1][1]-arr[i][0];
        v2.push_back(make_pair(y-x,i));
    }
    sort(v2.begin(),v2.end());
    vector<long long int> v;
    map<long long int,vector<int> > mp;
    map<long long int,vector<int> >::iterator it;
    for(i=0;i<m;i++)
    {
        cin>>x;
        v.push_back(x);
        it=mp.find(x);
        if(it==mp.end())
        {

            vector<int> v3;
            v3.push_back(i+1);
            mp.insert(make_pair(x,v3));
        }
        else
        {
            (it->second).push_back(i+1);
        }

    }
    sort(v.begin(),v.end());
    int cnt=0;
    for(i=0;i<n-1;i++)
    {
        j=v2[i].second;
        x=arr[j+1][0]-arr[j][1];
        y=arr[j+1][1]-arr[j][0];
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
                ans[j]=v[save+ctr];
                v.erase(v.begin()+save+ctr);
            }
        }
    }
    if(cnt==0)
    {
        cout<<"Yes\n";
        for(i=0;i<n-1;i++)
        {
            //cout<<ans[i]<<"\n";
            cout<<(mp[ans[i]].back())<<" ";
            mp[ans[i]].pop_back();
        }
    }
    else
        cout<<"No";
    return 0;
}
