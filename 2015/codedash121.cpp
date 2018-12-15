#include<stdio.h>
#include<iostream>

using namespace std;

int n;
void fun(int,int,int *);

int main()
{
    int i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int cnt=0;
    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            cnt=1;
            break;
        }
    }
    if(cnt==1)
        fun(0,n-1,arr);
    return 0;
}
void fun(int i,int j,int *arr)
{
    if(i>=j)
        return;
    int l,r,p=j,temp;
    for(l=i;l<j;l++)
    {
        if(arr[l]<arr[p])
        {
            for(r=i;r<l;r++)
            {
                if(arr[r]>arr[p])
                {
                    temp=arr[l];
                    arr[l]=arr[r];
                    arr[r]=temp;
                    break;
                }
            }
        }
    }
    for(l=i;l<j;l++)
    {
        if(arr[l]>arr[j])
        {
            temp=arr[l];
            arr[l]=arr[j];
            arr[j]=temp;
            break;
        }
    }
    p=l;
    for(r=0;r<n;r++)
        cout<<arr[r]<<" ";
    cout<<"\n";
    int cnt=0;
    for(r=i;r<p-1;r++)
    {
        if(arr[r]>arr[r+1])
        {
            cnt=1;
            break;
        }
    }
    if(cnt==1)
        fun(i,p-1,arr);
    cnt=0;
    for(r=p+1;r<j;r++)
    {
        if(arr[r]>arr[r+1])
        {
            cnt=1;
            break;
        }
    }
    if(cnt==1)
        fun(p+1,j,arr);
}
