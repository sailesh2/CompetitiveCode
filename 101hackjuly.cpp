#include<stdio.h>
#include<iostream>


using namespace std;

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int arr[n],brr[m],crr[m];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<m;i++)
    {
        cin>>brr[i];
    }
    for(i=0;i<m;i++)
    {
        cin>>crr[i];
    }
    for(i=0;i<m;i++)
    {
        j=1;
        while(j*brr[i]<=n)
        {
            arr[j*brr[i]-1]=((arr[j*brr[i]-1]%1000000007)*(crr[i]%1000000007))%1000000007;
            j++;
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
