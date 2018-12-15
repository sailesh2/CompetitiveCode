#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int main()
{
	int i,t,j,n,sm;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		sm=0;
		int arr[n],brr[n],an[n];
		for(j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		for(j=0;j<n;j++)
		{
			cin>>brr[j];
			if(arr[j]<=brr[j])
			an[j]=brr[j]-arr[j];
			else
			an[j]=4-(arr[j]-brr[j]);
		}
		sm=an[0];
		for(j=1;j<n;j++)
		{
			if(an[j]>=an[j-1])
			sm=sm+an[j]-an[j-1];
		}
		cout<<sm<<"\n";
	}
	getch();
	return 0;
}
