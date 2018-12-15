#include<stdio.h>
#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int main()
{
    int i,n,q,ctru,ctrv,u,v,x;
    cin>>n>>q;
    int has[200005]={0};
    multiset<long long int> arr;
    multiset<long long int>::iterator it;
    for(i=0;i<n;i++)
    {
        cin>>x;
        arr.insert(x);
        has[i+1]=x;
    }
    int par[200005]={0};
    for(i=0;i<q;i++)
    {
        ctru=0;
        ctrv=0;
        cin>>u>>v;
        while(par[u]!=0)
        {
            ctru++;
            u=par[u];
        }
        while(par[v]!=0)
        {
            ctrv++;
            v=par[v];
        }
        if(u!=v)
        {
            if(ctru<ctrv)
            {
               // cout<<"ctru"<<" "<<u<<" "<<v<<"\n";
                par[u]=v;
                arr.erase(arr.find(has[u]));
                arr.erase(arr.find(has[v]));
                has[v]=has[u]+has[v];
                arr.insert(has[v]);
            }
            else
            {

             //   cout<<"ctrv"<<" "<<u<<" "<<v<<"\n";
                par[v]=u;

                arr.erase(arr.find(has[u]));
                arr.erase(arr.find(has[v]));
                has[u]=has[u]+has[v];
                arr.insert(has[u]);
            }
        }

        cout<<*arr.begin()<<"\n";
    }
    return 0;
}
