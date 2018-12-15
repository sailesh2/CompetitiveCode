#include<stdio.h>
#include<iostream>
#include<set>

using namespace std;

int main()
{
	set<long long int> st;
	set<long long int>::iterator it;
	int cnt,i,n,m;
	cin>>n>>m;
	long long int arr[n],a,s=0;
	long long int crr[1000000]={0};
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<m;i++)
	{
		cin>>a;
		st.insert(a);
		crr[a]++;
	}
	for(i=0;i<n;i++)
	{
		cnt=0;
		it=st.lower_bound(arr[i]);
		while(it!=st.end())
		{
			if(crr[*it]>0)
			{
				cnt=1;
				crr[*it]--;
				break;
			}
			it++;
		}
		if(cnt==0)
		s++;
	}
	cout<<s;
	return 0;
}
