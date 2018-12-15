#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>

using namespace std;


bool fun(pair<int,int> i,pair<int,int> j)
{
        return (i.second<j.second);
}

int main()
{
    int i,t,j,n,m;
    vector< pair<int,int> >::iterator it,save;
    cin>>t;
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&n,&m);
        vector< pair<int,int> > v;
        long long int p=1;
        char x;
        int y;
        for(j=0;j<m;j++)
        {
            cin>>x>>y;
            v.push_back(make_pair((int)x,y));
        }

        sort(v.begin(),v.end(),fun);



        it=v.begin();
        save=it;
        it++;
        while(it!=v.end())
        {
            if(it->first!=save->first)
            {
                p=((p*(it->second-save->second)%1000000009))%1000000009;
            }
            save=it;
            it++;
        }
        printf("%lld\n",p);
    }
    return 0;
}
