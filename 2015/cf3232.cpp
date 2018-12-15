#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n;
    cin>>n;
    int arr[n];
    int ctr=0,counter=-1;
    int has[2000]={0};
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    while(1)
    {
        if(ctr==n)
            break;
        counter++;
        for(i=0;i<n;i++)
        {
            if(arr[i]<=ctr && has[i]==0)
            {
                ctr++;
                has[i]=1;
            }
        }
        if(ctr==n)
            break;
        counter++;
        for(i=n-1;i>=0;i--)
        {
            if(arr[i]<=ctr && has[i]==0)
            {
                ctr++;
                has[i]=1;
            }
        }
    }
    cout<<counter;
    return 0;
}
