#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int a1,b1,a2,b2,n,m,cnt=0;
    cin>>n>>m;
    cin>>a1>>b1;
    cin>>a2>>b2;
    if(a1+a2<=n || a1+a2<=m)
    {
        if(a1+a2<=n)
        {
            if(max(b1,b2)<=m)
            {
                cnt=1;
            }
        }
        if(a1+a2<=m)
        {
            if(max(b1,b2)<=n)
            {
                cnt=1;
            }
        }

    }
    if(a1+b2<=n || a1+b2<=m)
    {
        if(a1+b2<=n)
        {
            if(max(b1,a2)<=m)
            {
                cnt=1;
            }
        }
        if(a1+b2<=m)
        {
            if(max(b1,a2)<=n)
            {
                cnt=1;
            }
        }
    }
    if(b1+a2<=n || b1+a2<=m)
    {
        if(b1+a2<=n)
        {
            if(max(a1,b2)<=m)
            {
                cnt=1;
            }
        }
        if(b1+a2<=m)
        {
            if(max(a1,b2)<=n)
            {
                cnt=1;
            }
        }
    }
    if(b1+b2<=n || b1+b2<=m)
    {
        if(b1+b2<=n)
        {
            if(max(a1,a2)<=m)
            {
                cnt=1;
            }
        }
        if(b1+b2<=m)
        {
            if(max(a1,a2)<=n)
            {
                cnt=1;
            }
        }
    }
    if(cnt==1)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
