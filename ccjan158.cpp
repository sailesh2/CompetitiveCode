#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int i,j,q,t,l,r,x,maxi,save;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>t;
        if(t==0)
        {
            cin>>x;
            v.push_back(x);
        }
        else if(t==1)
        {
            cin>>l>>r>>x;
            maxi=0;
            for(j=l-1;j<r;j++)
            {
                if((x^v[j])>=maxi)
                {
                    maxi=x^v[j];
                    save=v[j];
                }
            }
            cout<<save<<"\n";
        }
        else if(t==2)
        {
            cin>>x;
            for(j=0;j<x;j++)
            {
                v.pop_back();
            }
        }
        else if(t==3)
        {
            cin>>l>>r>>x;
            maxi=0;
            for(j=l-1;j<r;j++)
            {
                if(v[j]<=x)
                    maxi++;
            }
            cout<<maxi<<"\n";
        }
        else
        {
            cin>>l>>r>>x;
            maxi=0;
            int brr[r-l+1];
            for(j=l-1;j<r;j++)
            {
                brr[maxi++]=v[j];
            }
            sort(brr,brr+maxi);
            cout<<brr[x-1]<<"\n";
        }
    }
    return 0;
}
