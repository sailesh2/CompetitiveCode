#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string.h>
using namespace std;
int brr[100000][10];
int arr[100000];
int main()
{
	long long int n,m,i,j,ctra,sma,ctrb,smb,x;
	cin>>n>>m;
	string s;
	cin>>s;
	for(i=0;i<n;i++)
	{
		arr[i]=int(s[i])-48;
	}

	long long int crr[10]={0};
	for(i=0;i<n;i++)
	{
		for(j=0;j<10;j++)
		{
			brr[i][j]=crr[j];
		}
		if(i>0)
		{
			brr[i][arr[i-1]]++;
			crr[arr[i-1]]++;
		}
	}
	for(i=0;i<m;i++)
	{
		cin>>x;
		ctra=0;
		ctrb=0;
		sma=0;
		smb=0;
		for(j=0;j<10;j++)
		{
			if(j<=arr[x-1])
			{
				ctra=ctra+brr[x-1][j];
				sma=sma+brr[x-1][j]*j;
			}
			else
			{
				ctrb=ctrb+brr[x-1][j];
				smb=smb+brr[x-1][j]*j;
			}
		}
		cout<<arr[x-1]*ctra-sma+smb-arr[x-1]*ctrb<<"\n";
	}
	getch();
	return 0;
}
