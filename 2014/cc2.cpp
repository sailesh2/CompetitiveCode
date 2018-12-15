#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{

 	long long int a,cnt1,cnt2,i,j,t,n;
 	long long int ans;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cnt1=0;
		cnt2=0;
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>a;
			if(a==1 || a==0)
			cnt1++;
			if(a==2)
			cnt2++;
		}
		n=n-cnt1;
		ans=((n*(n-1))/2)-((cnt2*(cnt2-1))/2);
		cout<<ans<<"\n";
	}
	return 0;
}
