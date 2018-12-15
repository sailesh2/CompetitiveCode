#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,j,n,k,maxi;
    cin>>t;
    for(i=0;i<t;i++)
    {
        maxi=0;
        cin>>n;
        long long int arr[n],brr[n];
        for(j=0;j<n;j++)
            cin>>arr[j];
        for(j=0;j<n;j++)
            cin>>brr[j];
        k=n-1;
        for(j=n-1;j>=0;j--)
        {
            while(k>=0 && arr[k]<=brr[j])
            {
                k--;
            }
            if((j-k-1)>=maxi)
                maxi=j-k-1;
        }
        cout<<maxi<<"\n";
    }
    return 0;
}
