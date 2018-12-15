#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int arr[10]={1,2,5,13,33,81,193,449,1025,2305};
	int i,t,n,s,a,b,c,x;
	cin>>t;
	int ans[t];
	for(i=0;i<t;i++)
	{
		cin>>n;
		a=int(floor(log(n)));
		s=arr[a];
		b=pow(2,a)+1;
		while(b<=n)
		{
			c=b;
			while(c>0)
			{
				x=c%2;
				c=c/2;
				if(x==1)
				s++;
			}
			b++;
		}
		ans[i]=s;
	}
	for(i=0;i<t;i++)
	{
		cout<<ans[i]<<"\n";
	}
	return 0;
}
