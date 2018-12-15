#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

int main()
{
    long long int i,j,n,k;
    cin>>n;
    map<long long int,long long int> mp;
    map<long long int,long long int>::iterator it;
    //int ans[n];
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
    long long int sm=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if(sm==n*n-n)
            break;
        if((it->second)>1)
        {
            if((it->second)%2==0)
            {
                if((sm+it->second)>(n*n)-n)
                {
                    it->second=it->second-(((n*n)-n)-sm);
                    sm=n*n-n;
                    break;
                }
                else
                {
                    sm=sm+it->second;
                    it->second=0;
                }
            }
            else
            {
                if((sm+(it->second)-1)>(n*n)-n)
                {
                    it->second=(it->second-1)-(((n*n)-n)-sm);
                    sm=n*n-n;
                    break;
                }
                else
                {
                    sm=sm+(it->second)-1;
                    it->second=1;
                }
            }
        }
    }
    k=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
        for(j=0;j<it->second;j++)
        {
            cout<<it->first<<" ";
            k++;
        }
    }
    return 0;
}
