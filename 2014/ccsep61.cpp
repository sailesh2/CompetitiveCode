#include<stdio.h>
#include<iostream>

using namespace std;

long long int fun(int);

int main()
{
    int i,t,n,m;
    long long int q,p,k,s;
    cin>>t;
    i=0;
    while(i<t)
    {
        cin>>n>>m;
        s=0;
        j=1;
        while(j<=n)
        {
            p=(long long int)floor((float)n/j)
            k=(long long int)floor((float)n/p)
            q=fun(k)-fun(j-1);
            s=s+((q%m)*(p%m))%m;
            j=k+1;
        }
        cout<<s%m;
        i=i+1;
    }

long long int fun(int n)
{
    a=((pow(n,5)%m)*(5%m))%m+((pow(n,4)%m)*(2%m))%m+((pow(n,3)%m)*(3%m))%m+n%m)*(30%m
    return int(a)
}
