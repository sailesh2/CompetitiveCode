#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int main()
{
	int m,n,i,j;
	cin>>m>>n;
	long long int arr[m][n];
	long long int sum,sm;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr[i][j];
			if(i!=0 && j!=n-1)
			{
				arr[i][j]=arr[i][j]+arr[i-1][j];
			}
		}
	}
	sm=0;
	for(i=0;i<m;i++)
	{
		sum=sm;
		for(j=0;j<n-1;j++)
		{
			if(arr[i][j]>sum)
			sm=sm+arr[i][j]-sum;
		}
		sm=sm+arr[i][n-1];
		cout<<sm<<" ";
	}
	getch();
	return 0;
}
