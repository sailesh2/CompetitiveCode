#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int main()
{
	int i,t;
	long long int tot,sm,n,j,x,k,ctr,max;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		long long int arr[n];
		long long int crr[100001]={0};
		for(j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		tot=(n*(n-1))/2;
		sm=0;
		max=0;
		for(j=0;j<n;j++)
		{
			ctr=0;
			k=j;
			while(arr[k]!=0)
			{
				k=arr[k]-1;
				ctr++;
			}
			crr[ctr]++;
			if(ctr>=max)
			max=ctr;
		}
		for(j=1;j<=max;j++)
		{
			sm=sm+(crr[j]*(crr[j]-1))/2;
		}
		cout<<tot-sm<<" "<<sm<<"\n";
	}
	getch();
	return 0;
}
