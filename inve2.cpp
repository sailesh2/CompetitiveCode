#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

int main()
{
	long long int i,t,n,p,sum,j,p1,p2;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>p;
		p1=1;
		p2=1;
		sum=1;
		for(j=1;j<=p;j++)
		{
			p1=p1*(n-(j-1));
			p2=p2*j;
			sum=sum+p1/p2;
		}
		cout<<sum%1000000007<<"\n";
	}
	getch();
	return 0;
}
