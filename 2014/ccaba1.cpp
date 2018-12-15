#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int i,t,cnt;
	long long int j,n,a,b;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>b>>n;
		if(n%2==0)
		{
			if(n==2)
			cout<<"-1\n";
			else
			cout<<n<<"\n";
		}
		else
		{
			if(n==3)
			{
				cout<<"-1\n";
			}
			else
			{
			cnt=0;
			a=(long long int)floor(sqrt(n));
			for(j=2;j<=a;j++)
			{
				if(n%j==0)
				{
					cnt=1;
					break;
				}
			}
			if(cnt==1)
			cout<<n<<"\n";
			else
			{
				if((n-1)>=b)
				cout<<n-1<<"\n";
				else
				cout<<"-1\n";

			}
			
			}
		}
	}
	return 0;
}
