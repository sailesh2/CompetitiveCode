#include<stdio.h>

int func(int a,int b)
{
	int temp,tmp;

	temp=b/a;

	if(b%a==0)
	{
		return (temp-1);

	}


	tmp=func(b%a,a);

	if(tmp>=temp)
	{
		return (temp-1);
	}

	return temp;
}
int main()
{
	int ans,t,n,a,b,temp;

	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);
		ans=0;

		while(n--)
		{
			scanf("%d%d",&a,&b);

			if(a>b)
			{
				temp=a;
				a=b;
				b=temp;
			}

			ans=ans^func(a,b);
		}

		if(ans!=0)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}
}
