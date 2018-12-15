#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,n,j,ctr,x,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ctr=0;
        cin>>n>>k;
        for(j=0;j<n;j++)
        {
            cin>>x;
            if(x%2==0)
                ctr++;
        }
        if(ctr>=k)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

