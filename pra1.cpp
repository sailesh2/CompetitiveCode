#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,x;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x;
        if(x==1)
            cout<<"1 0\n";
        else
            cout<<x-1<<" 1\n";
    }
    return 0;
}
