#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    long long int n,t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        if(n==1)
            cout<<"1\n";
        else
            cout<<(n*(n-1))/2<<"\n";
    }
    return 0;
}
