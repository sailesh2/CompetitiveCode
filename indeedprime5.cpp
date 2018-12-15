#include<stdio.h>
#include<iostream>
#define gc getchar_unlocked

using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}


int n,k;
long long int dp[100][100]={0};
int xarr[1000],sarr[1000],aarr[1000],barr[1000];

long long int fun(int,int);

int main()
{
    int i;
    scanint(n);
    scanint(k);
    for(i=0;i<n;i++)
    {
        scanint(xarr[i]);
        scanint(sarr[i]);
        scanint(aarr[i]);
        scanint(barr[i]);
    }
    cout<<fun(0,0);
}
long long int fun(int pos,int len)
{
    //cout<<pos<<" "<<len<<"\n";
    if(pos==n)
        return 0;
    int i,v;
    long long int val=0;
    if(pos+1<n && dp[pos+1][len]!=0)
        val=max(val,dp[pos+1][len]);
    else
        val=max(val,fun(pos+1,len));
    if(len+aarr[pos]<=k)
    {
        if(pos+1<n && dp[pos+1][len+aarr[pos]]!=0)
            val=max(val,dp[pos+1][len+aarr[pos]]+xarr[pos]);
        else
            val=max(val,fun(pos+1,len+aarr[pos])+xarr[pos]);
        len=len+aarr[pos];

        v=(k-len)/barr[pos];
        if(v>0)
        {
            if(pos+1<n && dp[pos+1][len+v*barr[pos]]!=0)
                val=max(val,dp[pos+1][len+v*barr[pos]]+v*xarr[pos]);
            else
                val=max(val,fun(pos+1,len+v*barr[pos])+v*xarr[pos]);
        }
    }

    /*for(i=0;i<sarr[pos]-1;i++)
    {
        if(len+barr[pos]<=k)
        {
            if(pos+1<n && dp[pos+1][len+barr[pos]]!=0)
                val=max(val,dp[pos+1][len+barr[pos]]+(i+2)*xarr[pos]);
            else
                val=max(val,fun(pos+1,len+barr[pos])+(i+2)*xarr[pos]);
            len=len+barr[pos];
        }
        else
        {
            break;
        }
    }*/
    //}
    dp[pos][len]=val;
    return val;
}
