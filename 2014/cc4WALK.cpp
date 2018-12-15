#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int i,t,j,n,a;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		int maxi=0;
		for(j=0;j<n;j++)
		{
			cin>>a;
			if((a+j)>=maxi)
			maxi=a+j;
		}
		cout<<maxi<<"\n";
	}
	return 0;
}
