#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>

int main()
{
	long long int ctr=0,i,t,k=0,n,a;
	scanf("%lld",&t);
	long long int arr[2*t];
	for(i=0;i<t;i++)
	{
		scanf("%lld",&n);
		a=(long long int)ceil(log2(n));
		arr[k++]=(long long int)exp2(a);
		ctr=0;
		while(n>1)
		{
			if(n%2!=0)
			break;
			ctr=ctr+1;
			n=n/2;
		}
		arr[k++]=a-ctr;
	}
	i=0;
	while(i<k)
	{
		printf("%lld %lld\n",arr[i],arr[i+1]);
		i=i+2;
	}
	getch();
	return 0;
}
