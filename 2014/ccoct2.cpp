#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int i,t,n,j,k;
    long long int sm;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int arr[n];
        for(j=0;j<n;j++)
            cin>>arr[j];
        sm=0;
        k=0;
        j=0;
        while(k<n)
        {
            if(arr[j]<0)
            {
                while(k<n)
                {
                    if(arr[k]>=0)
                    {
                        if(abs(arr[j])<arr[k])
                        {
                            sm=sm+abs(arr[j])*abs(j-k);
                            arr[k]=arr[k]-abs(arr[j]);
                            break;
                        }
                        sm=sm+arr[k]*abs(j-k);
                        arr[j]=arr[j]+arr[k];
                    }
                    k++;
                }
            }
            j++;
        }
        cout<<sm<<"\n";
    }
    return 0;
}
