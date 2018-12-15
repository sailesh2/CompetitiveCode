#include<stdio.h>
#include<iostream>

using namespace std;

int n,a,b,c;
int fun(int,int,int,int,int *,int *,int *);
int main()
{
    int i,t,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b>>c;
        cin>>n;
        int arr[n],brr[n],crr[n];
        for(j=0;j<n;j++)
        {
            cin>>arr[j]>>brr[j]>>crr[j];
        }
        cout<<"Case #"<<i+1<<": ";
        if(fun(0,0,0,0,arr,brr,crr)==1)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
int fun(int i,int sma,int smb,int smc,int *arr,int *brr,int *crr)
{
    if(sma==a && smb==b && smc==c)
        return 1;

    if(i>=n)
        return 0;
    int j;
    for(j=i;j<n;j++)
    {
        if(fun(j+1,sma+arr[j],smb+brr[j],smc+crr[j],arr,brr,crr)==1)
            return 1;
    }
    return 0;
}
