#include<stdio.h>
#include<iostream>
using namespace std;

int n,maxi,k1;
long long int arr[5000];
void fun(int,int,long long int);
int main()
{
	int i,j;
	long long int x;
	cin>>n>>k1;
	maxi=0;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n;i++)
	{
		x=arr[i];
		for(j=i+1;j<n;j++)
		{
			if(arr[j]>x)
			{
				fun(j+1,1,arr[j]-x);
			}
		}
	}
	cout<<maxi;
	return 0;
}
void fun(int k,int ctr,long long int sum)
{
	int j,i;
	long long int x;
	if(sum>=maxi && ctr<=k1)
	{
		maxi=sum;
	}
    for(i=k;i<n;i++)
	{
		x=arr[i];
		for(j=i+1;j<n;j++)
		{
			if(arr[j]>x)
			{
				fun(j+1,ctr+1,sum+arr[j]-x);
			}
		}

	}
}
