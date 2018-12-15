#include<stdio.h>
#include<set>
#include<iterator>
#include<iostream>
#include<map>

using namespace std;
int main()
{
		set< pair<int,int> > s;
s.insert(pair<int,int>(3,40));

map<pair<int,int>,int> mapa;
map< pair<int,int>,int >::iterator it1;
	int n,i,m,ax,j,x,y,a,b,maxi,ans,temp;
	cin>>n>>m;
	int arr[n];

	for(i=0;i<n;i++)
	{
		cin>>arr[i];

	}
	for(i=0;i<m;i++)
	{
        int crr[100001]={0};
		cin>>ax>>x>>y;
		maxi=0;
		for(j=x-1;j<=y-1;j++)
		{
            crr[arr[j]]++;
			a=ax;
			b=arr[j];
			ans=1;
			if(a>b)
			{
				while(1)
				{
                    it1=mapa.find(pair<int,int>(a,b));
					if(it1->second!=0)
					{
						ans=it1->second;
						break;
					}
					if(a%b==0)
					{
						ans=b;
						break;
					}
					temp=a;
					a=b;
					b=temp%b;
				}
				mapa.insert(make_pair(pair<int,int>(a,b),ans));
			}
			else
			{
				while(1)
				{
                    it1=mapa.find(pair<int,int>(b,a));
					if(it1->second!=0)
					{
						ans=it1->second;
						break;
					}
					if(b%a==0)
					{
						ans=a;
						break;
					}
					temp=b;
					b=a;
					a=temp%a;
				}
				mapa.insert(make_pair(pair<int,int>(b,a),ans));
			}
			if(ans>1)
			{
				if(arr[j]>=maxi)
				{
					maxi=arr[j];
				}
			}
		}
		if(maxi==0)
		cout<<"-1 -1\n";
		else
		cout<<maxi<<" "<<crr[maxi]<<"\n";
	}

	return 0;
}
