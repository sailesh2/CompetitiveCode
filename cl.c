#include<stdio.h>
#include<conio.h>

long long int cnt=0;
long long int n;
void fun(long long int,int);
int main()
{
scanf("%lld",&n);
fun(0,1);
printf("%lld",cnt);
getch();
return 0;
}
void fun(long long int k,int ctr)
{
	long long int i;
	for(i=k;i<n;i++)
	{
		if(ctr==3)
		{
			cnt++;
			continue;
		}
		fun(i+1,ctr+1);
	}
}
