#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,i,j,k;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int maxi=0;
    for(i=0,j=2*(n-k)-1;i<j;i++,j--)
    {
        if(arr[i]+arr[j]>maxi)
            maxi=arr[i]+arr[j];
    }
    for(i=n-1;i>max(-1,2*(n-k)-1);i--)
    {
        maxi=max(maxi,arr[i]);
    }
    cout<<maxi;
    return 0;
}
