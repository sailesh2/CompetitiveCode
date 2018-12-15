#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

int n,m;
long long int sm,cnt;
int c[45];
long long int p[45];
void fun(int,long long int,int,int *arr);
int main()
{
	int i,t,j;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cnt=0;
		sm=0;
		cin>>n>>m;
		for(j=0;j<n;j++)
		{
			cin>>c[j]>>p[j];
		}
		int arr[45]={0};
		fun(0,0,0,arr);
		}
		
		printf("%0.9lf\n",(double)sm/cnt);
		cout<<sm<<"f"<<cnt;
		
	}
	getch();
	return 0;
}
void fun(int i,long long int sum,int ctr,int *arr)
{
	if(ctr>=m)
	{
		cnt++;
		sm=sm+sum;
	}
	if(i==n)
	return;
	int j;
	for(j=i;j<n;j++)
	{
		if((n-j)>=(m-ctr))
		{
			if(ctr<m)
			{
				if(arr[c[j]]==0)
				{
					arr[c[j]]=1;
					fun(j+1,sum+p[j],ctr+1,arr);
					arr[c[j]]=0;
				}
			}
			else
			{
                fun(j+1,sum+p[j],ctr+1,arr);
			}
		}
	}
}
