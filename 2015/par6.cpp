#include<stdio.h>
#include<iostream>
#include<string.h>
#define gc getchar

using namespace std;


void scanint(long long int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}


int main()
{
    long long int i,j,l,r,ctr2,n,t,m,val;
    long long int sm;
    string x;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sm=0;
        cin>>x;
        scanint(m);
        long long int arr[m];
        arr[0]=1;
        for(j=1;j<m;j++)
        {
            arr[j]=(arr[j-1]*j)%m;
         //   cout<<arr[j]<<" ";
        }
        for(j=2;j<m;j++)
        {
            //cout<<arr[j]<<" ";
            arr[j]=(arr[j]+arr[j-1])%m;
            //cout<<arr[j]<<"\n";
        }
        for(j=0;j<x.length()-1;j++)
        {
            if(x[j]!='0')
            {
                val=(int)x[j]-48;
                if(val<m)
                    sm=(sm+arr[val])%m;
                else
                    sm=(sm+arr[m-1])%m;
                if(x[j]==x[j+1])
                {
                    val=((int)x[j]-48)*10+(int)x[j+1]-48;
                    if(val<m)
                        sm=(sm+arr[val])%m;
                    else
                        sm=(sm+arr[m-1])%m;
                }
            }
        }
        if(x[j]!='0')
        {
            val=(int)x[j]-48;
            if(val<m)
                sm=(sm+arr[val])%m;
            else
                sm=(sm+arr[m-1])%m;
        }
        n=x.length();
        j=2;
        ctr2=0;
        while(j<n)
        {
            if(x[j]!='0')
            {
                if(j+1<n && x[j]==x[j+1])
                {
                    l=j-1;
                    r=j+2;
                    while(l>=0 && r<n)
                    {
                        if(x[l]!=x[r])
                            break;
                    }
                    ctr2=ctr2+(r-l)/2;
                }
                else
                {
                    l=j-1;
                    r=j+1;
                    while(l>=0 && r<n)
                    {
                        if(x[l]!=x[r])
                            break;
                    }
                    ctr2=ctr2+(r-l)/2;
                }
            }
            j++;
        }
        //cout<<ctr2<<"\n";
        sm=(sm+(ctr2*arr[m-1])%m)%m;
        cout<<sm%m<<"\n";
    }
    return 0;
}
