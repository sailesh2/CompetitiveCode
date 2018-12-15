#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        cout<<n/2*(n-n/2)<<"\n";
    }
    return 0;
}
