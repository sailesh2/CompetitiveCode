#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i,t,j,n,ctr;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ctr=0;
        cin>>n;
        int arr[n],brr[n];
        for(j=0;j<n;j++)
            cin>>arr[j];
        for(j=0;j<n;j++)
            cin>>brr[j];
        sort(arr,arr+n);
        sort(brr,brr+n);
        for(j=0;j<n;j++)
        {
            if(arr[j]>=brr[n-j-1])
            {
                if(arr[j]%brr[n-j-1]==0)
                    ctr++;
            }
            else
            {
                if(brr[n-j-1]%arr[j]==0)
                    ctr++;
            }
        }
        cout<<ctr<<"\n";
    }
    return 0;
}
