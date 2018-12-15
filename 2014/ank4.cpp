#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,n,ctr;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ctr=0;
        cin>>n;
        while(n!=0)
        {
            if(n%2==1)
                ctr++;
            n=n/2;
        }
    }
    return 0;
}
