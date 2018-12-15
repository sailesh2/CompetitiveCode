#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int main()
{
	vector<string> v;
	string rawInput;
	long long int j,i,t,n,q,k=0,a,b,c,ctr;
	cin>>n;
	long long int arr[n],ans[1000]={0};
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>q;
	for(i=0;i<q;i++)
	{
		while(getline(cin,rawInput,' '))
		{
			v.push_back(rawInput);
		}
		if(atoi((v.pop_back()).c_str())==0)
		{	ctr=0;
			a=atoi(v.pop_back().c_str());
            b=atoi(v.pop_back().c_str());
            c=atoi(v.pop_back().c_str());

			for(j=a-1;j<b;j++)
			{
				if(arr[j]>=c)
				ctr++;
			}
			ans[k++]=ctr;
		}
		else
		{
            a=atoi(v.pop_back().c_str());
            b=atoi(v.pop_back().c_str());
            arr[a-1]=b;
		}
	}
	for(i=0;i<k;i++)
	{
		cout<<ans[i]<<"\n";
	}
	return 0;
}
