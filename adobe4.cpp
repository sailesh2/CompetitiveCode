#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<map>
#include<iterator>

using namespace std;

int main()
{
	map<long long int,long long int> mapa;
	map<long long int,long long int>::iterator it;
	int n,m,i,j,q,k;
	cin>>n>>m;
	long long int x,arr[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>x;
			arr[i][j]=x;
			mapa.insert(make_pair(x,i));
		}
	}
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>x;
		if(mapa.count(x)>0)
		{
			it=mapa.find(x);
			k=it->second;
			for(j=0;j<m;j++)
			{
				if(arr[k][j]==x)
				break;
			}
			cout<<k<<" "<<j<<"\n";
		}
		else
		cout<<"-1-1\n";
	}
	getch();
	return 0;
}
