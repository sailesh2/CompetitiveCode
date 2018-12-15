#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<iterator>
#include<string.h>
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
    int i,x,n,j,m,k,q,cnt,t,counter,ctr;
    int arr[301][301];
    int ans1[301],ans2[301];
    scanint(n);
    vector< multiset<int> > v;
    for(i=0;i<n;i++)
    {
        scanint(m);
        multiset<int> st;
        for(j=0;j<m;j++)
        {
            scanint(x);
            st.insert(x);
        }
        v.push_back(st);
    }
    cin>>q;
    int brr[301][301];
    for(i=0;i<q;i++)
    {
        scanint(t);
        scanint(m);
        ans1[i]=t;
        ans2[i]=m;
        for(j=0;j<m;j++)
        {
            scanint(brr[i][j]);
        }
    }
    for(i=0;i<q;i++)
    {
        t=ans1[i];
        m=ans2[i];
        multiset<int> st;
        set<int> st2;
        multiset<int>::iterator it;
        set<int>::iterator it2;
        for(j=0;j<m;j++)
        {
            x=brr[i][j];
            st.insert(x);
            st2.insert(x);
        }
        if(t==1)
        {
            counter=0;
            for(j=0;j<n;j++)
            {
                ctr=0;
                cnt=0;
                for(it2=st2.begin();it2!=st2.end();it2++)
                {
                    if(v[j].count(*it2)<st2.count(*it2))
                    {
                        cnt=1;
                        break;
                    }
                }
                if(cnt==0)
                    counter++;
            }
            cout<<counter<<"\n";
        }
        else if(t==2)
        {
            counter=0;
            for(j=0;j<n;j++)
            {
                ctr=0;
                for(it2=st2.begin();it2!=st2.end();it2++)
                {
                    if(v[j].count(*it2)>0)
                    {
                        ctr++;
                        break;
                    }
                }
                if(ctr==1)
                    counter++;
            }
            cout<<counter<<"\n";
        }
        else
        {
            counter=0;
            for(j=0;j<n;j++)
            {
                ctr=0;
                cnt=0;
                for(it2=st2.begin();it2!=st2.end();it2++)
                {
                    it=st.find(*it2);
                    ctr=ctr+min(v[j].count(*it),st.count(*it));
                    if(ctr>=m)
                    {
                        cnt=1;
                        break;
                    }
                }
                if(cnt==0)
                {
                if(ctr>0 && ctr<m)
                    counter++;
                }
            }
            cout<<counter<<"\n";
        }
    }
    return 0;
}
