#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	long long int n,m,a,b,j,l,c;
	int i,t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>m;
		a=n-1;
		b=m-1;
		j=a;
		l=b;
		if(a>b)
		{
			while(1)
			{
				if(j%l==0)
				{
					cout<<l+1;
					break;
				}
				c=j;
				j=l;
				l=c%l;
			}
		}
		else
		{
			while(1)
			{
				if(l%j==0)
				{
					cout<<j+1;
					break;
				}
				c=l;
				l=j;
				j=c%j;
			}
		}
	}
	getch();
	return 0;
}
