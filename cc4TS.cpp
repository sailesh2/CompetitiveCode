#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int maxi,save,k,i,t,s,n,a,b,c,d,l,r,ctr,j,cnt;
	cin>>t;
	int arr[t];
	for(i=0;i<t;i++)
	{
		cin>>n>>a>>b>>c>>d;
		ctr=0;
		l=0;
		r=0;
		s=0;
		if(a==0 && b==0 && c>=0 && d>=0)
		{
			if(n%2!=0)
			cout<<d<<"\n";
			else
			{
				if(c>d)
				cout<<c-d<<"\n";
				else
				cout<<d-c<<"\n";
			}
		}
		else if(c==0 && d==1 && ((a==0 && b==1)||(a==1 && b==0)))
		{
			if(n%2==0)
			cout<<"0\n";
			else
			cout<<"1\n";
		}
		else if(a>=0 && b>=0 && c==0 && d==0)
		cout<<"0\n";
		else
		{
			vector<int> arr[10];
			k=0;
			while(1)
			{
				if(ctr==n)
				break;
				if(ctr==0)
				{
					s=d;
					arr[k].push_back(s);
				}
				else
				{
					s=a*s*s+b*s+c;
					if(s>=1000000)
					{
						s=s%1000000;
						k=k+1;
					}
					arr[k].push_back(s);
				}
				ctr=ctr+1;
			}
			ctr=0;
			while(1)
			{
				j=0;
				cnt=0;
				maxi=0;
				save=-1;
				while(j<=k)
				{
					if(arr[j].size()>0)
					{
						if(arr[j].back()>=maxi)
						{
							maxi=arr[j].back();
							save=j;
						}
						cnt=1;
					}
					j=j+1;
				}
				if(cnt==0)
				break;
				if(ctr%2==0)
				l=l+maxi;
				else
				r=r+maxi;
				arr[save].pop_back();
				ctr++;
			}
			if(l>r)
			cout<<l-r<<"\n";
			else
			cout<<r-l<<"\n";
		}
	}
	return 0;
}
