#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,j,maxi=0;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i>0)
        {
            if((arr[i]-arr[i-1])>=maxi)
                maxi=arr[i]-arr[i-1];
        }
    }
    int mini=1000000000;
    for(i=0;i<n-2;i++)
    {
        if((arr[i+2]-arr[i])>maxi)
        {
            if((arr[i+2]-arr[i])<=mini)
                mini=arr[i+2]-arr[i];
        }
        else
        {
            if(maxi<=mini)
                mini=maxi;
        }
    }
    cout<<mini;
    return 0;
}
