#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int main()
{
	long long int i,t,n,j,sum,x,cnt,savef,savel;
	cin>>t;
	for(i=0;i<t;i++)
	{
		long long int crr[1001]={0};
		cin>>sum;
		cin>>n;
		cnt=0;
		for(j=0;j<n;j++)
		{
			cin>>x;
			if(cnt==0 && x<=sum)
			{
				if(crr[sum-x]>0)
				{
					savef=crr[sum-x];
					savel=j+1;
					cnt=1;
				}
				else
				{
					if(crr[x]==0)
					crr[x]=j+1;
				}
			}
		}
		cout<<savef<<" "<<savel<<"\n";
	}
	getch();
	return 0;
}
