#include<stdio.h>
#include<iostream>
#include<map>
#include<iterator>

using namespace std;

int main()
{
    int n,m,i,j,c,maxi=0,save=-1;
    cin>>n>>m;
    map<int,int> mp;
    map<int,int>::iterator it;
    for(i=0;i<n;i++)
    {
        cin>>j;
        it=mp.find(j);
        if(it==mp.end())
        {
            mp.insert(make_pair(j,1));
            c=1;
        }
        else
        {
            c=it->second+1;
            mp.erase(it);
            mp.insert(make_pair(j,c));
        }
        if(c==maxi)
        {
            if(j>save)
            {
                save=j;
            }
        }
        else if(c>maxi)
        {
            maxi=c;
            save=j;
        }
        cout<<save<<" "<<maxi<<"\n";
    }
    return 0;
}
