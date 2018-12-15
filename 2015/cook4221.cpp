#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,ctr,j,n,a,b;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ctr=0;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>a>>b;
            if(a>=b)
                ctr=ctr+a%b;
            else
                ctr=ctr+b%a;
            ctr++;
        }
        ctr=ctr%2;
        if(ctr==0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
