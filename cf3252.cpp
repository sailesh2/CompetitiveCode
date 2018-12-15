#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,save,save2;
    cin>>n;
    int arr[n],brr[n],srr[n];
    for(i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n-1;i++)
    {
        cin>>brr[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>srr[i];
    }
    for(i=1;i<n-1;i++)
        arr[i]=arr[i]+arr[i-1];
    for(i=n-3;i>=0;i--)
        brr[i]=brr[i]+brr[i+1];
    long long int mini=10000000000,mini2=1000000000;
    save=-2;
    save2=-2;

    if(srr[0]+brr[0]<mini)
    {
        mini=srr[0]+brr[0];
        save=-1;
    }
    for(i=0;i<n-2;i++)
    {
        if(arr[i]+brr[i+1]+srr[i+1]<mini)
        {
            mini=arr[i]+brr[i+1]+srr[i+1];
            save=i;
        }
    }
    if(arr[n-2]+srr[n-1]<mini)
    {
        mini=arr[n-2]+srr[n-1];
        save=n-2;
    }



    if(save!=-1 && srr[0]+brr[0]<mini2)
    {
        mini2=srr[0]+brr[0];
        save2=-1;
    }
    for(i=0;i<n-2;i++)
    {
        if(i!=save && arr[i]+brr[i+1]+srr[i+1]<mini2)
        {
            mini2=arr[i]+brr[i+1]+srr[i+1];
            save2=i;
        }
    }

    if(save!=n-2 && arr[n-2]+srr[n-1]<mini2)
    {
        mini2=arr[n-2]+srr[n-1];
        save2=n-2;
    }
    cout<<mini+mini2;
    return 0;
}
