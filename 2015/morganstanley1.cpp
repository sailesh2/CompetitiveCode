#include<stdio.h>
#include<iostream>
#include<math.h>
#include<utility>
#include<stdlib.h>

using namespace std;

int main()
{
    int i,j,t,n,nva;
    cin>>t;
    long long int s=0;
    for(i=0;i<t;i++)
    {
        s=0;
        cin>>n;
        int arr[n];
        for(j=0;j<n;j++)
            cin>>arr[j];
        for(j=1;j<n-1;j++)
        {
            if(arr[j-1]%2==0 && arr[j+1]%2==0)
            {
                nva=(arr[j-1]+arr[j+1])/2;
                if(abs(nva-arr[n-1-j])>=abs(arr[j]-arr[n-1-j]))
                   arr[j]=nva;
            }
        }
        for(j=0;j<n/2;j++)
            s=s+abs(arr[j]-arr[n-1-j]);
        cout<<s<<"\n";
    }
    return 0;
}
