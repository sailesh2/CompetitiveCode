#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,n,j,k;
    long long int sm,maxi;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sm=0;
        maxi=0;
        cin>>n>>k;
        int arr[n];
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
            if(j<k)
                sm=sm+arr[j];
        }
        maxi=sm;
        for(j=k;j<n;j++)
        {
            sm=sm-arr[j-k]+arr[j];
            if(sm>=maxi)
                maxi=sm;
        }
        cout<<maxi<<"\n";
    }
    return 0;
}
