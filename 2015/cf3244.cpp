#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i=1,n,ctr=0,j,ctr1,a,b,ctr2;
    cin>>n;
    while(i*i<=n)
    {
        if(n%i==0)
        {
            if(i==n/i)
                ctr++;
            else
                ctr=ctr+2;
        }
        i=i+1;
    }
    if(ctr==2)
        cout<<"1\n"<<n;
    else
    {
        if(n==4)
        {
            cout<<"2\n2 2";
        }
        else if(n==5)
        {
            cout<<"2\n2 3";
        }
        else if(n==6)
        {
            cout<<"2\n 3 3";
        }
        else
        {
            n=n-3;
            n=n/2;
            for(j=0;j<=n;j++)
            {
                a=n-j;
                b=n+j;
                i=1;
                ctr1=0;
                while(i*i<=a)
                {
                    if(a%i==0)
                    {
                        if(i==a/i)
                            ctr1++;
                        else
                            ctr1=ctr1+2;
                    }
                    i=i+1;
                }

                i=1;
                ctr2=0;
                while(i*i<=b)
                {
                    if(b%i==0)
                    {
                        if(i==b/i)
                            ctr2++;
                        else
                            ctr2=ctr2+2;
                    }
                    i=i+1;
                }

                if(ctr1==2 && ctr2==2)
                {
                    cout<<"3\n3 "<<a<<" "<<b;
                    break;
                }
            }
        }
    }
    return 0;
}
