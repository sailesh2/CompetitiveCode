#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

struct node
{
    int id;
    int val;
};

int main()
{
	int i,j,n,mi,ki,u,v,x;
  	cin>>n>>mi>>ki;
	vector< vector<struct node> > arr;
	int has[n];
	long long int dis[n];
	for(i=0;i<n;i++)
	{
	    has[i]=0;
		dis[i]=10000000000000000;
	    vector<struct node> v;
	    arr.push_back(v);
	}
    for(i=0;i<mi;i++)
    {
        cin>>u>>v>>x;
        struct node nm;
        nm.id=v-1;
        nm.val=x;
        arr[u-1].push_back(nm);

        struct node nm1;
        nm1.id=u-1;
        nm1.val=x;
        arr[v-1].push_back(nm1);

    }
	has[0]=1;
	int ch=0,k=1,save;
	long long int mini=1000000000000000;
	dis[ch]=0;
	while(1)
	{
		if(k>n)
			break;
		mini=1000000000000000;
		for(i=0;i<arr[ch].size();i++)
		{
			if(has[arr[ch][i].id]==0)
			{
					if(dis[ch]+arr[ch][i].val<dis[arr[ch][i].id])
					{
						dis[arr[ch][i].id]=dis[ch]+arr[ch][i].val;
					}
				if(dis[arr[ch][i].id]<mini)
				{
					mini=dis[arr[ch][i].id];
					save=arr[ch][i].id;
				}
			}
		}
		for(i=0;i<n;i++)
        {
            if(has[i]==0)
            {
                if(dis[i]<mini)
                {
                    mini=dis[i];
                    save=i;
                }
            }
        }
		ch=save;
		k++;
		has[ch]=1;
	}
	//for(i=0;i<n;i++)
    //    cout<<dis[i]<<"\n";
	int p,q,ctr=0;
	for(i=0;i<ki;i++)
    {
        cin>>p>>q;
        if(dis[p-1]<=q)
            ctr++;
    }
    cout<<ctr;
	return 0;
}
