#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int i,t,n,j,p,a;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		p=1;
		for(j=0;j<n;j++)
		{
			cin>>a;
			p=p|a;
		}
		cout<<p*pow(2,n-1)<<"\n";
	}
	getch();
	return 0;
}
