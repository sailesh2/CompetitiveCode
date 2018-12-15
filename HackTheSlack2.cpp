#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,x,ctr=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x<=300000000)
            ctr++;
    }
    cout<<ctr;
    return 0;
}
