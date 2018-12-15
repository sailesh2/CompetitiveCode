#include<stdio.h>
#include<iostream>

using namespace std;

int arr[101][101];
int sav[1000];
int n,maxi;
int maxSum[101];
void fun(int,int);

int main()
{
    int i,t,j,k,sm,maxm;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        maxi=0;
        sm=0;
        for(j=0;j<n;j++)
        {
            sav[j]=0;
            maxm=0;
            for(k=0;k<n;k++)
            {
                cin>>arr[j][k];
                if(arr[j][k]>=maxm)
                    maxm=arr[j][k];
            }
            sm=sm+maxm;
            maxSum[j]=sm;
        }
        fun(0,0);
        cout<<maxi<<"\n";
    }
    return 0;
}
void fun(int i,int sum)
{
    if(sum+maxSum[n-1]-maxSum[i-1]<=maxi)
        return;
    if(sum>=maxi)
        maxi=sum;
    int j;
    for(j=0;j<n;j++)
    {
        if(sav[j]==0)
        {
            sav[j]=1;

            fun(i+1,sum+arr[i][j]);
            sav[j]=0;
        }
    }
}
