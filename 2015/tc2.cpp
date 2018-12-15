#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class BearDartsDiv2
{
	public:
	long long count(vector<int> v)
	{
		int i,j;
		long long val,cnt=0;
		map<long long,vector<int> > mp;
		map<long long,vector<int> >::iterator it;
		for(i=0;i<v.size();i++)
		{
			for(j=i+1;j<v.size();j++)
			{
				val=(long long)v[i]*v[j];
				it=mp.find(val);
				if(it==mp.end())
				{
					vector<int> v2;
					v2.push_back(j);
					mp.insert(make_pair(val,v2));
				}
				else
				{
					(it->second).push_back(j);
				}
			}
		}
		for(it=mp.begin();it!=mp.end();it++)
        {
            sort((it->second).begin(),(it->second).end());
        }
        for(it=mp.begin();it!=mp.end();it++)
        {
            cout<<it->first<<"\n";
            for(i=0;i<(nit->second).size();i++)
                cout<<(it->second)[i]<<" ";
            cout<<"\n";
        }
		int ctr,save,save2;
		for(i=1;i<v.size();i++)
		{
			for(j=0;j<i;j++)
			{
				if(v[i]%v[j]==0)
				{
					it=mp.find(v[i]/v[j]);
					if(it!=mp.end())
					{
						vector<int> v1=it->second;
						save=-1;
						save2=-1;
						ctr=1;
						while(1)
						{
							while(save+ctr<v1.size() && v1[save+ctr]<j)
							{
								save2=save+ctr;
								ctr=ctr*2;
							}
							if(save==save2)
								break;
							save=save2;
							ctr=1;
						}
						cnt=cnt+save+1;
					}
				}
			}
		}
		return cnt;
	}
};

int main()
{
    BearDartsDiv2 ob;
    vector<int> v;
    int i;
    for(i=0;i<10;i++)
        v.push_back(1);
    cout<<ob.count(v);
    return 0;
}
