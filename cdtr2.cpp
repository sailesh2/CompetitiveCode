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
    int i,t,j,n,k;
    long long int sm;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sm=0;
        cin>>n;
        int arr[n];
        int crr[100005]={0};
        for(j=0;j<n;j++)
        {
            scanint(arr[j]);
        }
        cin>>k;
        for(j=0;j<n;j++)
        {
            if(k>=arr[j])
            sm=sm+crr[k-arr[j]];
            crr[arr[j]]++;
        }
        cout<<sm<<"\n";
    }
    return 0;
}
