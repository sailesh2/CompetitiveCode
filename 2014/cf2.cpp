#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int i,n,max,save,ind1,ind2,sm=0;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	while(1)
	{
		max=-1;
		save=-1;
		ind1=-1;
		ind2=-1;
		for(i=0;i<n;i++)
		{
			if(arr[i]>max)
			{
				ind2=ind1;
				save=max;
				max=arr[i];
				ind1=i;
			}
			else
			{
				if(arr[i]!=max && arr[i]>save)
				{
					ind2=i;
					save=arr[i];
				}
			}
		}
		if(ind2==-1)
		break;
		arr[ind1]=arr[ind1]-arr[ind2];
	}
	for(i=0;i<n;i++)
	sm=sm+arr[i];
	cout<<sm;
	return 0;
}
