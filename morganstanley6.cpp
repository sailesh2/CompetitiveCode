#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,j,n,q,ctr;
    cin>>n>>q;
    int arr[n];
    int l,k;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<q;i++)
    {
        cin>>l>>k;
        ctr=0;
        for(j=0;j<n;j++)
        {
            if(arr[j]>=l)
                ctr++;
            if(ctr==k)
            {
                cout<<arr[j]<<"\n";
                break;
            }
        }
    }
    return 0;
}
