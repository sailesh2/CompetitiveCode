#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,k,maxi=0;
    cin>>n;
    int arr[n],brr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(n<=2)
        cout<<"1";
    else
    {
        brr[0]=1;
        brr[n-1]=1;
        for(i=1;i<n-1;i++)
        {
            if(arr[i]==1)
                brr[i]=1;
            else
            {
                k=min(arr[i-1],arr[i+1]);
                if(k<arr[i])
                    brr[i]=min(brr[i-1]+1,k+1);
                else
                    brr[i]=min(brr[i-1]+1,arr[i]);
            }
        }
        for(i=n-2;i>=0;i--)
        {
            brr[i]=min(brr[i],brr[i+1]+1);
        }
        for(i=0;i<n;i++)
            maxi=max(maxi,brr[i]);
        cout<<maxi;
    }
    return 0;
}
