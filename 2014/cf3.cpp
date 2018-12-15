#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	long long int a,b,w,x,c;
	long long int i=0;
	cin>>a>>b>>w>>x>>c;
	while(1)
	{
		if(c<=a)
		{
			cout<<i;
			break;
		}
		c=c-1;
		if(b>=x)
		b=b-x;
		else
		{
			a=a-1;
			b=w-(x-b);
		}
		i=i+1;
	}
	return 0;
}
