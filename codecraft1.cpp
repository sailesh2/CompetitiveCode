#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,t,n,p;
    string str;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>str>>p;
        if(str[0]=='o')
        {
            cout<<2*p<<"\n";
        }
        else
        {
            cout<<2*p-1<<"\n";
        }
    }
    return 0;
}
