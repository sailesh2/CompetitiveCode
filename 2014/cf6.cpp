#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

set<int> sav;
int n,x,y;
int fun(int,int *);
int main()
{
	int i,a;
	cin>>n;
	cin>>x>>y;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
    sort(arr,arr+n);
	a=fun(x,arr);
	if(a==-1)
		cout<<"IMPOSSIBLE";
	if(a==1)
		cout<<"POSSIBLE";
return 0;
}


int fun(int ctr,int *arr)
{
	if(ctr==y)
	{
		return 1;
	}
	if(ctr>y)
		return -1;
	int i,a,b,it;
	for(i=0;i<n;i++)
	{
		a=ctr-1+arr[i];
		if(a>y)
            return -1;
		if(ctr==a)
			continue;
		it=sav.count(a);
		if(it==0)
		{
			b=fun(a,arr);
			if(b==1)
			{
				return 1;
			}
		}
	}
    sav.insert(ctr);
	return -1;
}
