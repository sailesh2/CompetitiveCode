#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	long long int i,n,mid,left,joy=0;
	cin>>n;
	long long int arr[n],brr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>brr[i];
		mid=brr[i]/2;
		if(mid<=arr[i] && mid>=1)
		{
			left=brr[i]-mid;
			if(left<=arr[i] && left>=1)
			joy=joy+mid*left;
			else
			joy--;
		}
		else
		joy--;
	}
	cout<<joy;
	return 0;
}
