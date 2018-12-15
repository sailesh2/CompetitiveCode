#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
	multimap<int,int> m;
	int n,i,k,x,d,cnt;
	scanf("%d %d",&n,&k);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		d=a[i+1]-a[i];
		x=a[i]-d*i;
		m.insert(make_pair(x,d));
	}
	multimap<int,int>::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		d=it->second;
		x=it->first;
		cnt=0;
		for(i=0;i<n;i++)
		{
			if(a[i]!=x+i*d)
			{
				cnt++;
			}
			if(cnt>k)
			    break;
		}
		if(cnt<=k)
			    break;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",x+i*d);
	}
	return 0;
}
