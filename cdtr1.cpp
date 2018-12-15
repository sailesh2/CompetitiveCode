#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,n,k,j,x;
    long long int sm;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sm=0;
        cin>>n;
        int arr[n];
        for(j=0;j<n;j++)
            cin>>arr[j];
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>x;
            sm=sm+arr[x-1];
        }
        cout<<sm<<"\n";
    }
    return 0;
}
