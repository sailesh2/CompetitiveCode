#include<stdio.h>
#include<iostream>
#define gc getchar

using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    int i,t,n,q,j,a,b,gcd,temp;
    scanint(t);
    for(i=0;i<t;i++)
    {
        scanint(n);
        scanint(q);
        int arr[n];
        int larr[n+1];
        int rarr[n+1];
        for(j=0;j<n;j++)
        {
            scanint(arr[j]);
        }
        larr[0]=0;
        larr[1]=arr[0];
        a=arr[0];
        if(n>1)
        {
            b=arr[1];
            if(a>=b)
            {
                while(1)
                {
                    if(a%b==0)
                    {
                        gcd=b;
                        break;
                    }
                    temp=a;
                    a=b;
                    b=temp%b;
                }
            }
            else
            {
                while(1)
                {
                    if(b%a==0)
                    {
                        gcd=a;
                        break;
                    }
                    temp=b;
                    b=a;
                    a=temp%a;
                }
            }
            larr[2]=gcd;
            for(j=2;j<n;j++)
            {
                a=gcd;
                b=arr[j];
                if(a>=b)
                {
                    while(1)
                    {
                        if(a%b==0)
                        {
                            gcd=b;
                            break;
                        }
                        temp=a;
                        a=b;
                        b=temp%b;
                    }
                }
                else
                {
                    while(1)
                    {
                        if(b%a==0)
                        {
                            gcd=a;
                            break;
                        }
                        temp=b;
                        b=a;
                        a=temp%a;
                    }
                }
                larr[j+1]=gcd;
            }
        }

        rarr[n]=0;
        rarr[n-1]=arr[n-1];
        a=arr[n-1];
        if(n>1)
        {
            b=arr[n-2];
            if(a>=b)
            {
                while(1)
                {
                    if(a%b==0)
                    {
                        gcd=b;
                        break;
                    }
                    temp=a;
                    a=b;
                    b=temp%b;
                }
            }
            else
            {
                while(1)
                {
                    if(b%a==0)
                    {
                        gcd=a;
                        break;
                    }
                    temp=b;
                    b=a;
                    a=temp%a;
                }
            }
            rarr[n-2]=gcd;
            for(j=n-3;j>=0;j--)
            {
                a=gcd;
                b=arr[j];
                if(a>=b)
                {
                    while(1)
                    {
                        if(a%b==0)
                        {
                            gcd=b;
                            break;
                        }
                        temp=a;
                        a=b;
                        b=temp%b;
                    }
                }
                else
                {
                    while(1)
                    {
                        if(b%a==0)
                        {
                            gcd=a;
                            break;
                        }
                        temp=b;
                        b=a;
                        a=temp%a;
                    }
                }
                rarr[j]=gcd;
            }
        }
        for(j=0;j<q;j++)
        {
            scanint(a);
            scanint(b);
            a=larr[a-1];
            b=rarr[b];
            if(a>=b)
            {
                if(b==0)
                {
                    gcd=a;
                }
                else
                {
                while(1)
                {
                    if(a%b==0)
                    {
                        gcd=b;
                        break;
                    }
                    temp=a;
                    a=b;
                    b=temp%b;
                }
                }
            }
            else
            {
                if(a==0)
                {
                    gcd=b;
                }
                else
                {
                while(1)
                {
                    if(b%a==0)
                    {
                        gcd=a;
                        break;
                    }
                    temp=b;
                    b=a;
                    a=temp%a;
                }
                }
            }
            cout<<gcd<<"\n";
        }
    }
    return 0;
}
