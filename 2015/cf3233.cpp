#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

int main()
{
    int i,j,n,k;
    cin>>n;
    map<int,int> mp;
    map<int,int>::iterator it;
    int ans[n];
    k=0;
    for(i=0;i<n*n;i++)
    {
        cin>>j;
        it=mp.find(j);
        if(it!=mp.end())
        {
            it->second=it->second+1;
        }
        else
        {
            mp.insert(make_pair(j,1));
        }
    }
    for(it=mp.begin();it!=mp.end();it++)
    {
        if((it->second)%2!=0)
        {
            ans[k++]=it->first;
            it->second=it->second-1;
        }
    }
    for(i=0;i<k;i++)
        cout<<ans[i]<<" ";
    int cnt=0;
    while(k<n)
    {
            cnt=0;
            for(it=mp.begin();it!=mp.end();it++)
            {
                if(k<n && it->second%2!=0)
                {
                    cnt=1;
                    cout<<it->first<<" ";
                    it->second=it->second-1;
                    k++;
                }
            }
            if(cnt==0)
            {
              for(it=mp.begin();it!=mp.end();it++)
            {
                if(k<n && it->second>2)
                {
                    cnt=1;
                    cout<<it->first<<" ";
                    it->second=it->second-1;
                    k++;
                }
            }
            }
    }
    return 0;
}
