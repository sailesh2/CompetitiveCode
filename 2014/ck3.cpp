#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	long long int j,l,p,ctr,i,t,n,k;
	cin>>t;
	long long int crr[t];
	for(i=0;i<t;i++)
	{
		cin>>n>>k;
		long long int arr[n];
		for(j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		ctr=0;
		for(j=0;j<n;j++)
		{
			p=arr[j];
			if(p<k)
			ctr++;
			for(l=j+1;l<n;l++)
			{
				p=p^arr[l];
				if(p<k)
				ctr++;
			}
		}
		crr[i]=ctr;
	}
	for(i=0;i<t;i++)
	cout<<crr[i]<<"\n";
	return 0;
}
