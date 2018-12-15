#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,t,j,cnt;
    long long int maxi;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int arr[n],brr[n];
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        for(j=0;j<n;j++)
        {
            cin>>brr[j];
        }
        maxi=0;
        cnt=0;
        for(j=0;j<n;j++)
        {
            if(min(arr[j],brr[j])>=maxi)
            {
                maxi=min(arr[j],brr[j]);
            }
            else
            {
                if(max(arr[j],brr[j])>=maxi)
                {
                    maxi=max(arr[j],brr[j]);
                }
                else
                {
                    cnt=1;
                    break;
                }
            }
        }
        if(cnt==1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
