#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int cnt=0,j,i,n,k=0;
	cin>>n;
	int arr[n];
	char ans[1000000];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]!=0)
		cnt=1;
	}
	if(cnt==1)
	{
		while(1)
		{
			cnt=0;
			j=0;
			while(j<n)
			{
				if(ans[k-1]!='P')
				{
					if(arr[j]!=0)
					{
						arr[j]--;
						ans[k++]='P';
					}
				}
				if(j!=(n-1))
				ans[k++]='R';
				if(arr[j]!=0)
				cnt=1;
				j++;
			}
			if(cnt==0)
			break;
			j=n-1;
			cnt=0;
			while(j>=0)
			{
				if(ans[k-1]!='P')
				{
					if(arr[j]!=0)
					{
						arr[j]--;
						ans[k++]='P';
					}
				}
				if(j!=0)
				ans[k++]='L';
				if(arr[j]!=0)
				cnt=1;
				j--;
			}
			if(cnt==0)
			break;
		}
	}
	for(i=0;i<k;i++)
	cout<<ans[i];
	return 0;
}
