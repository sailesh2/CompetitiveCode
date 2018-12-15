#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;
int n;
long long int sav[1000][1000]={0},arr[1000][2]={0};
long long int fun(int,int,int);
int main()
{
	int i;
	cin>>n;
	long long int s;
	for(i=0;i<n;i++)
	{
		cin>>arr[i][0]>>arr[i][1];
	}
	s=fun(0,n,0);
	cout<<s;
	getch();
	return 0;
}
long long int fun(int i,int ctr,int t)
{
	int a,b;
	if(ctr==t || i==n)
	return 0;
	if(sav[i+1][t]!=0)
	a=sav[i+1][t];
	else
	a=fun(i+1,ctr,t);
	if(sav[i+1][t+1]!=0)
	b=sav[i+1][t+1]+arr[i][1];
	else
	b=fun(i+1,ctr-1,t+1)+arr[i][1];
	if(a<=b)
	sav[i][t]=a;
	else
	sav[i][t]=b;
	return sav[i][t];
}
