#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	long long int i,t,a,b;
	long long int arr[1000000]={0},brr[1000000]={0};
	long long int drr[1000000]={0};
	long long int k=0,min=1000000;
	int cnt=-1;
	cin>>t;
	long long int mid=ceil((double)t/2);
	for(i=0;i<t;i++)
	{
		cin>>a>>b;
		if(arr[a]==0)
		drr[k++]=a;
		arr[a]++;
		brr[b]++;
	}
	for(i=0;i<k;i++)
	{
		if(arr[drr[i]]>=mid)
		{
			cnt=1;
			break;
		}
		else
		{
			if((arr[drr[i]]+brr[drr[i]])>=mid)
			{
				cnt=0;
				if((mid-arr[drr[i]])<=min)
				min=mid-arr[drr[i]];
			}
		}
	}
	if(cnt==-1)
	cout<<"Impossible";
	if(cnt==1)
	cout<<"0";
	if(cnt==0)
	cout<<min;
	return 0;
}
