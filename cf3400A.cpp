#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int i,t,j,a,b;
	cin>>t;
	int ans[t][15][2];
	int cnt[t];
	for(i=0;i<t;i++)
	{
		int ctr=0;
		int k=0;
		char c[15];
		cin>>c;
		b=12;
		a=1;
		int arr[15]={0};
		for(j=0;j<12;j++)
		{
			if(c[j]=='X')
			arr[j%b]++;
		}
		for(j=0;j<b;j++)
		{
			if(arr[j]==a)
			{
				ctr++;
				ans[i][k][0]=a;
				ans[i][k][1]=b;
				k++;
				break;
			}
		}
		
		b=6;
		a=2;
		for(j=0;j<15;j++)
		arr[j]=0;
		for(j=0;j<12;j++)
		{
			if(c[j]=='X')
			arr[j%b]++;
		}
		for(j=0;j<b;j++)
		{
			if(arr[j]==a)
			{
				ctr++;
				ans[i][k][0]=a;
				ans[i][k][1]=b;
				k++;
				break;
			}
		}
		
		b=4;
		a=3;
		for(j=0;j<15;j++)
		arr[j]=0;
		for(j=0;j<12;j++)
		{
			if(c[j]=='X')
			arr[j%b]++;
		}
		for(j=0;j<b;j++)
		{
			if(arr[j]==a)
			{
				ctr++;
				ans[i][k][0]=a;
				ans[i][k][1]=b;
				k++;
				break;
			}
		}
		
		b=3;
		a=4;
		for(j=0;j<15;j++)
		arr[j]=0;
		for(j=0;j<12;j++)
		{
			if(c[j]=='X')
			arr[j%b]++;
		}
		for(j=0;j<b;j++)
		{
			if(arr[j]==a)
			{
				ctr++;
				ans[i][k][0]=a;
				ans[i][k][1]=b;
				k++;
				break;
			}
		}
		
		b=2;
		a=6;
		for(j=0;j<15;j++)
		arr[j]=0;
		for(j=0;j<12;j++)
		{
			if(c[j]=='X')
			arr[j%b]++;
		}
		for(j=0;j<b;j++)
		{
			if(arr[j]==a)
			{
				ctr++;
				ans[i][k][0]=a;
				ans[i][k][1]=b;
				k++;
				break;
			}
		}
		
		b=1;
		a=12;
		for(j=0;j<15;j++)
		arr[j]=0;
		for(j=0;j<12;j++)
		{
			if(c[j]=='X')
			arr[j%b]++;
		}
		for(j=0;j<b;j++)
		{
			if(arr[j]==a)
			{
				ctr++;
				ans[i][k][0]=a;
				ans[i][k][1]=b;
				k++;
				break;
			}
		}
		cnt[i]=ctr;
	}
for(i=0;i<t;i++)
		{
			cout<<cnt[i]<<" ";
		for(j=0;j<cnt[i];j++)
		{
			cout<<ans[i][j][0]<<"x"<<ans[i][j][1]<<" ";
		}
		cout<<"\n";
}

		return 0;
}
