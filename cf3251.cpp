#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,ctr=0,j,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    j=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            j=1;
            ctr++;
        }
        else
        {
            if(j==1)
            {
                if(i+1<n && arr[i+1]==1)
                    ctr++;
                else
                    j=0;
            }
        }
    }
    cout<<ctr;
    return 0;
}
