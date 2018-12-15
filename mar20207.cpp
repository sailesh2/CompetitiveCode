#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int sm,mini,save,n;
void fun(int *,int,int);
int main()
{
	int i,t,j,g;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>g;
		int arr[n];
		sm=0;
		mini=100000;
		save=0;
		for(j=0;j<n;j++)
		{
			cin>>arr[j];
			sm=sm+arr[j];
		}
		fun(arr,0,0);
		if(save>=sm-save)
		{
			if(save<=g)
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
		else
		{
			if(sm-save<=g)
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
	}
	getch();
	return 0;
}
void fun(int *arr,int i,int sum)
{
	int j;
	if(abs(sm-(2*sum))<=mini)
	{
		mini=abs(sm-(2*sum));
		save=sum;
	}
	for(j=i;j<n;j++)
	{
		fun(arr,j+1,sum+arr[j]);
	}
}
