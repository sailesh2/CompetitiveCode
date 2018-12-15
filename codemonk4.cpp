#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i,j,n,k,mid,maxi=0,maxi2=0;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    j=0;
    for(i=0;i<n-1;i=i+2)
    {
        if(j>=k)
            break;
        mid=(arr[i+1]-arr[i])/2;
        if(mid>=maxi)
            maxi=mid;
        j++;
    }
    if((arr[n-1]-(arr[i]+mid))>=maxi)
        maxi=(arr[n-1]-(arr[i]+mid));
    j=0;
    for(i=n-1;i>0;i=i-2)
    {
        if(j>=k)
            break;
        mid=(arr[i]-arr[i-1])/2;
        if(mid>=maxi2)
            maxi2=mid;
        j++;
    }

    if(((arr[i]-mid)-arr[0])>=maxi2)
        maxi2=((arr[i]-mid)-arr[0]);
    cout<<min(maxi,maxi2);
    return 0;
}
