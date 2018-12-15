#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	long long int i,n,ctrx=0,ctry=0;
	cin>>n;
	int a,b;
	long long int crrx[200]={0},crry[200]={0};
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		if(crrx[a]==0)
		ctrx++;
		crrx[a]++;
		if(crry[b]==0)
		ctry++;
		crry[b]++;
	}
	if(ctrx<=ctry)
	cout<<ctrx;
	else
	cout<<ctry;
	return 0;
}
