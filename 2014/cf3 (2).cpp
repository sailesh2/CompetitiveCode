#include<iostream>
#include<stdio.h>
#include<set>

using namespace std;
void fun(long long int,long long int,long long int);
long long int mini=1000000000000000000,n;
set< pair<long long int,long long int> > st;
int cnt=0;
int main()
{
	long long int a,b,m,i;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		st.insert(pair<long long int,long long int>(a,b));
	}
	fun(1,1,0);
	if(cnt==0)
	cout<<-1;
	else
	cout<<mini;
	return 0;
}
void fun(long long int i,long long int j,long long int ctr)
{
	if(i>n || j>n)
	return;
	if(st.count(pair<long long int,long long int>(i,j))!=0)
	return;
	if(i==n && j==n)
	{
		cnt=1;
		if(ctr<=mini)
		mini=ctr;
		return;
	}
	fun(i+1,j,ctr+1);
	fun(i,j+1,ctr+1);
}
