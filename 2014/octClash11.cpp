#include<stdio.h>
#include<iostream>
#include<string>
#include<iterator>
#include<vector>
#define gc getchar

using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}


int main()
{
    int i,j,n,t,x,maxi;
    vector<string>::iterator it;
    vector<int>::iterator it1;
    string str;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        maxi=0;
        vector<string> v;
        vector<int> v1;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            cin>>str;
            v.push_back(str);
        }
        for(j=0;j<n;j++)
        {
            scanint(x);
            v1.push_back(x);
        }
        for(j=0;j<n-1;j++)
        {
            scanf("%d",&x);
            it=v.begin()+x-1;
            it1=v1.begin()+x-1;
            if(*it1>=maxi)
                maxi=*it1;
            //printf("%s %d",*it,*it1);
            cout<<*it<<maxi<<"\n";
            v.erase(it);
            v1.erase(it1);
        }
        if(v1.at(0)>=maxi)
            maxi=v1.at(0);
        cout<<*(v.begin())<<maxi<<"\n";
    }
    return 0;
}

