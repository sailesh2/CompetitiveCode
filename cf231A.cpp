#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,a,b,c,ctr=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        if(a+b+c>=2)
            ctr=ctr+1;
    }
    cout<<ctr;
    return 0;
}
