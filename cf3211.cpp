#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long int maxi=1,ctr=1;
    for(i=1;i<n;i++)
    {
        if(arr[i]>=arr[i-1])
            ctr++;
        else
        {
            if(ctr>maxi)
                maxi=ctr;
            ctr=1;
        }
    }
    if(ctr>maxi)
        maxi=ctr;
    cout<<maxi;
    return 0;
}
