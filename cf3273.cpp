#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,j,cnt=0,sm;
    cin>>n;
    int arr[n],brr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<10000;i++)
    {
        cnt=0;
        brr[0]=arr[0];
        brr[n-1]=arr[n-1];
        for(j=1;j<n-1;j++)
        {
            sm=arr[j-1]+arr[j]+arr[j+1];
            if(sm<2)
                brr[j]=0;
            else
                brr[j]=1;
        }

        for(j=0;j<n;j++)
        {
            if(brr[j]!=arr[j])
            {
                cnt=1;
                break;
            }
        }
        if(cnt==0)
        {
            cout<<i<<"\n";
            for(j=0;j<n;j++)
                cout<<brr[j]<<" ";
            break;
        }
        for(j=0;j<n;j++)
            arr[j]=brr[j];
    }
    if(cnt==1)
        cout<<"-1";
    return 0;
}
