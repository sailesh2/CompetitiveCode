#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int i,t,n,j;
	long long int sm;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		long long int arr[n],brr[n];
		for(j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		for(j=0;j<n;j++)
		{
			cin>>brr[j];
		}
		sort(arr,arr+n);
		sort(brr,brr+n);
		sm=0;
		for(j=0;j<n;j++)
		{
			sm=sm+arr[j]*brr[n-j-1];
		}
		cout<<"Case #"<<i+1<<": "<<sm<<"\n";
	}
	getch();
	return 0;
}
