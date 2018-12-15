#include<stdio.h>
#include<iostream>

using namespace std;

int arr[5001];
int sav[2001][4]={0};
int fun(int,int,int);
int main()
{
    int n,i,j,ctr=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        j=fun(i-1,arr[i],3);
        if(j==1)
            ctr++;
    }
    cout<<ctr;
    return 0;
}
int fun(int i,int sum,int ctr)
{

    if(sum==0 && ctr==0)
        return 1;
    if(i<0)
        return -1;
    int a,k;
    for(k=i;k>=0;k--)
    {
        if(sum-arr[k]>=0 && ctr>=0)
        {
            if(sav[1000+sum-arr[k]][ctr-1]!=0)
                a=sav[1000+sum-arr[k]][ctr-1];
            else
                a=fun(k,sum-arr[k],ctr-1);
            if(a==1)
            {
                sav[1000+sum-arr[k]][ctr-1]=1;
                return 1;
            }
            if(a==-1)
            {
                sav[1000+sum-arr[k]][ctr-1]=-1;
            }
        }
    }
    return -1;
}
