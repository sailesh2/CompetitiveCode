#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
    int i,j,ctr=0,n,k,mid,maxi=0,maxi2=0;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int dif[n-1];
    for(i=0;i<n-1;i=i+1)
    {
        dif[i]=arr[i+1]-arr[i];
        ctr++;
    }
    sort(dif,dif+n-1);
    j=min(ctr-1,k-1);
    cout<<(int)ceil((float)dif[k-2]/2);
    return 0;
}
