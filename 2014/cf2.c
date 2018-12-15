#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	long long int a,b,w,x,c;
	scanf("%lld",&a);
	scanf("%lld",&b);
	scanf("%lld",&w);
	scanf("%lld",&x);
	scanf("%lld",&c);
	long long int i=0;
	while(1)
	{
		if(c<=a)
		{
			printf("%lld",i);
			break;
		}
		c=c-1;
		if(b>=x)
		b=b-x;
		else
		{
			a=a-x;
			b=w-(x-b);
		}
		i=i+1;
	}
	getch();
	return 0;
}
