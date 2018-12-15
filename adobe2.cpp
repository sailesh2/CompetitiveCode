#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<set>

using namespace std;

int main()
{
	int i,t;
	set<long long int> st;
	long long int j,k,l,p,ctr,x,y;
	for(j=2;j<=1000;j++)
	{
		if(st.count(j)==0)
		{
			k=j*j;
			l=1;
			p=k;
			while(p<=10000000)
			{
                p=k*l;
				st.insert(p);
				l++;
			}
		}
	}
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>x>>y;
		ctr=0;
		for(j=x;j<=y;j++)
		{
			if(st.count(j)==0)
			{
				ctr++;
			}
		}
		cout<<ctr<<"\n";
	}
	getch();
	return 0;
}
