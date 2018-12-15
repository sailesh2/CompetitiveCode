#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,j,k,n,m,maxi;
    long long int sm=0;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        maxi=0;
        sm=0;
        int arr[n];
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
            if(arr[j]>=maxi)
                maxi=arr[j];
        }
        for(j=0;j<n;j++)
            sm=sm+maxi-arr[j];
        if(m<sm)
            cout<<"No\n";
        else
        {
            if((m-sm)%n==0)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}
