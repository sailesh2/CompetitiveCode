#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,n,a,b,j,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>a>>b;
        s=(n-1)*a;
        cout<<s<<" ";
        for(j=0;j<n-1;j++)
        {
            s=s-a+b;
            cout<<s<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
