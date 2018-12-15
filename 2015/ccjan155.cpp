#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i,t,j,k,cnt;
    long long int n,sm,x,save;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        sm=0;
        cnt=0;
        save=0;
        long long int arr[k];
        for(j=0;j<k;j++)
        {
            cin>>arr[j];
        }
        sort(arr,arr+k);
        for(j=0;j<k;j++)
        {
            x=arr[j];
            sm=sm+(x*(x-1))/2-(save*(save+1))/2;
            save=x;
            if(sm<x)
            {
                cnt=1;
                break;
            }
        }
        if(cnt==0)
            sm=sm+(n*(n+1))/2-(arr[k-1]*(arr[k-1]+1))/2;
        //cout<<sm+1;
        if((sm+1)%2==0)
            cout<<"Mom\n";
        else
            cout<<"Chef\n";
    }
    return 0;
}
