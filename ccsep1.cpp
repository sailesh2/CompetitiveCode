#include<stdio.h>
#include<iostream>

using namespace std;

long long int s;
int six[7]={1,6,15,20,15,6,1};
//int fac[7]={1,1,2,6,24,120,720};
//int has[7]={0};
void fun(int,int,int);

int main()
{
    int n;
    cin>>n;
    n=n-13;
    if(n<0)
        cout<<"0";
    else if(n==0)
        cout<<"1";
    else
    {
        s=1;
        while(n>0)
        {
            if(n%2==0)
            {
                fun(n/2,0,0);
                n=n-2;
            }
            else
            {
                n--;
            }
        }
        cout<<s%1000000007;
    }
    return 0;
}
void fun(int n,int ctr,int sum)
{
    //int p=1;
    if(ctr>6)
        return;
    if(sum==n)
    {
        /*for(int i=1;i<=6;i++)
            p=p*fac[has[i]];
        s=(s+(six[ctr]*fac[ctr])/p)%1000000007;*/
        s=(s+six[ctr])%1000000007;
        return;
    }
    else if(sum>n)
        return;
    else
    {
        for(int i=1;i<=1000000;i++)
        {
            if(sum+i>n)
                return;
            //has[i]++;
            fun(n,ctr+1,sum+i);
            //has[i]--;
        }
    }
    return;
}
