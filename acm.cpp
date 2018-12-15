#include<stdio.h>
#include<iostream>

using namespace std;
long long int maxi;
long long int arr[4][4],crr[5][5]={0};

void fun(long long int,long long int,long long int);
int main()
{
	long long int i,t,j,k,sum=0;
	cin>>t;
	for(k=0;k<t;k++)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				crr[i][j]=0;
				cin>>arr[i][j];
			}
		}
		sum=0;
		maxi=0;
		
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			sum=sum+arr[i][j];
			if(sum>=maxi)
			maxi=sum;
			crr[i][j]=1;
			if(i+1<4 && crr[i+1][j]==0 && arr[i+1][j]>arr[i][j])
			fun(i+1,j,sum);
			if(j+1<4 && crr[i][j+1]==0 && arr[i][j+1]>arr[i][j])
			fun(i,j+1,sum);
			if(i-1>=0 && crr[i-1][j]==0 && arr[i-1][j]>arr[i][j])
			fun(i-1,j,sum);
			if(j-1>=0 && crr[i][j-1]==0 && arr[i][j-1]>arr[i][j])
			fun(i,j-1,sum);
			crr[i][j]=0;
			sum=sum-arr[i][j];
		}
	}
	cout<<maxi<<"\n";
}
return 0;
}
void fun(long long int i,long long int j,long long int sum)
{
	sum=sum+arr[i][j];
	if(sum>=maxi)
	maxi=sum;
	crr[i][j]=1;
			if(i+1<4 && crr[i+1][j]==0 && arr[i+1][j]>arr[i][j])
			fun(i+1,j,sum);
			if(j+1<4 && crr[i][j+1]==0 && arr[i][j+1]>arr[i][j])
			fun(i,j+1,sum);
			if(i-1>=0 && crr[i-1][j]==0 && arr[i-1][j]>arr[i][j])
			fun(i-1,j,sum);
			if(j-1>=0 && crr[i][j-1]==0 && arr[i][j-1]>arr[i][j])
			fun(i,j-1,sum);
	crr[i][j]=0;
}
