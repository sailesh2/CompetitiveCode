#include<stdio.h>
#include<iostream>
#include<math.h>
#define gc getchar

using namespace std;

void scanint(unsigned long long &x)
{
    register  unsigned long long c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    unsigned long long i,n;
    unsigned long long x,cnt,ctr,sm=0,p=1,j,val,num;
    scanint(n);
     unsigned long long arr[n];
    for(i=0;i<n;i++)
    {
        scanint(arr[i]);
    }
    for(i=0;i<n;i++)
    {
        x=arr[i];
        if(x==0)
        {
            p=0;
            break;
        }
        j=0;
        cnt=0;
        ctr=0;
        num=x;
        while(num>0)
        {
            ctr=ctr+1;
            val=num%10;
            if(val>1)
            {
                cnt=2;
                break;
            }
            if(val==1)
            {
                if(cnt==1)
                {
                    cnt=2;
                    break;
                }
                cnt=1;
            }
            num=num/10;
        }
        if(cnt==2)
            p=p*x;
        else
            sm=sm+ctr-1;
    }
    if(p==0)
        cout<<p;
    else
    {
        i=0;
        while(i<sm)
        {
            p=p*10;
            i=i+1;
        }
        cout<<p;
    }
    return 0;
}
