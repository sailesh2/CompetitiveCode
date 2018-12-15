#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	long long int arr[100000]={0};
	long long int i,t,n,m,k;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>k>>m;
		if(m>=n)
		arr[i]=(long long int)((log10(m/n))/log10(k));
		else
		arr[i]=0;
	}
	for(i=0;i<t;i++)
	cout<<arr[i]<<"\n";
	return 0;
}
