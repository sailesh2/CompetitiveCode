#include<stdio.h>
#include<iostream>
#include<map>
#include<iterator>
#include<algorithm>
#include<utility>
#define gc getchar

using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    int i,j,n,x,maxi,save,save2;
    cin>>n;
    int arr[2*n];
    map<pair<int,int>,int> mp;
    map<pair<int,int>,int>::iterator it,saveit;

    for(i=1;i<2*n;i++)
    {
        for(j=0;j<i;j++)
        {
            scanint(x);
            pair<int,int> p=make_pair(i,j);
            mp.insert(make_pair(p,x));
        }
    }
    int cnt,has[1000]={0};
    while(1)
    {
        cnt=0;
            maxi=0;
            save=-1;
            save2=-1;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(has[(it->first).first]==0 && has[(it->first).second]==0 && it->second>maxi)
            {
                cnt=1;
                maxi=it->second;
                save=(it->first).first;
                save2=(it->first).second;
            }

        }
        if(cnt==0)
            break;
        arr[save]=save2;
        arr[save2]=save;
        has[save]=1;
        has[save2]=1;
    }
    for(i=0;i<2*n;i++)
        cout<<arr[i]+1<<" ";
    return 0;
}
