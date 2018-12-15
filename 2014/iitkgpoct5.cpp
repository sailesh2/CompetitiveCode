#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

string str;
int n;
int fun(int s,int d,int *);
int main()
{
    int j,s,d,q;
    cin>>n>>q;
    cin>>str;
    for(j=0;j<q;j++)
    {
        cin>>s>>d;
        int has[100005]={0};
        if(fun(s,d,has)==1)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}

int fun(int s,int d,int * has)
{
    if(has[s]==1)
        return 0;
    has[s]=1;
    if(s<1 || s>n)
        return 0;
    if(str[s-1]=='1')
        return 0;
    if(s==d)
        return 1;
    if(fun(2*s,d)==1)
        return 1;
    if(fun(2*s+1,d)==1)
        return 1;
    if(s%2==0)
    {
        if(fun(s/2,d)==1)
            return 1;
        else
            return 0;
    }
    else
    {
        if(fun((s-1)/2,d)==1)
            return 1;
        else
            return 0;
    }
    return 0;
}
