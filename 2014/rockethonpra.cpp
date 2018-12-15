#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	long long int ctr=0,i,n,k;
	cin>>n>>k;
	long long int arr[n];
	int crr[1000000]={0};
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		if(crr[k-arr[i]]>0)
		{
			ctr++;
			crr[k-arr[i]]--;
		}
		else
		crr[arr[i]]++;
	}
	cout<<ctr;
	return 0;
}
