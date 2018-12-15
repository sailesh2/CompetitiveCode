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
    int cnt=0;
    if(n%2==0)
        cnt=1;
    if(cnt==0)
    {
    for(i=1;i<=n/2;i++)
    {
        if(arr[i]<=arr[i-1])
        {
            cnt=1;
            break;
        }
    }
    }
    if(cnt==0)
    {
    for(i=0;i<n/2;i++)
    {
        if(arr[i]!=arr[n-1-i])
        {
            cnt=1;
            break;
        }
    }
    }
    if(cnt==0)
        cout<<"Perfect";
    else
      cout<<"Not perfect";
    return 0;
}
