#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i,n,k;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int save=0;
    for(i=1;i<n;i++)
    {
        if(arr[i]-arr[save]>k)
        {
            i--;
            if(save==i)
                break;
            save=i;
        }
    }
    if(i==n && arr[n-1]-arr[n-2]<=k)
        cout<<arr[n-1];
    else
        cout<<arr[save];
    return 0;

}
