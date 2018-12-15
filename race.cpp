#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<iterator>
#include<map>
using namespace std;
int fun(int);
map<int,int> mapk;
map<int,int>::iterator it;
int main()
{
	int i,t,n;
	cin>>t;
	
	for(i=0;i<t;i++)
	{
        int mini;
		cin>>n;
		mini=fun(n);
		cout<<mini<<"\n";
		mapk.erase(mapk.begin(),mapk.end());
	}
	getch();
	return 0;
}
int fun(int n)
{
	if(n==1)
	return 0;
	int a,minimum=10000000;
	if(n%3==0)
	{
		cout<<n/3<<" ";
        it=mapk.find(n/3);
      	if(mapk.count(n/3)!=0)
		a=it->second+1;
		else
		a=fun(n/3)+1;
		if(a<=minimum)
		minimum=a;
	}
	if(n%2==0)
	{
		cout<<n/2<<" ";
        it=mapk.find(n/2);
		if(mapk.count(n/2)!=0)
		a=it->second+1;
		else
		a=fun(n/2)+1;
		if(a<=minimum)
		minimum=a;
	}
	cout<<n-1<<"\n";
	it=mapk.find(n-1);
	if(mapk.count(n-1)!=0)
	a=it->second+1;
	else
	a=fun(n-1)+1;
	if(a<=minimum)
	minimum=a;
	mapk.insert(make_pair(n,minimum));
	return minimum;
}
