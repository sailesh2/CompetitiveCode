#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t;
    long long int a,b,n,d,sm;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>d;
        a=n/d;
        b=n%d;
        sm=a*(d*(d-1))/2+(b*(b+1)/2);
        cout<<sm<<"\n";
    }
}
