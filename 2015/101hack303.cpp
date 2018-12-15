#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,k,j;
    cin>>n>>k;
    int arr[n],brr[n],save,saved;
    long long int maxi=0;
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
        cin>>brr[i];
    for(i=0;i<k;i++)
    {
        maxi=0;
        for(j=0;j<n;j++)
        {
            if(arr[j]*brr[j]==maxi)
            {
                if(arr[j]<saved)
                {
                    maxi=arr[j]*brr[j];
                    save=j;
                    saved=arr[j];
                }
            }
            else if(arr[j]*brr[j]>maxi)
            {
                maxi=arr[j]*brr[j];
                save=j;
                saved=arr[j];
            }
        }
        arr[save]--;
    }
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
