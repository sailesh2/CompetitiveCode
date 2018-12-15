#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
#include<iterator>
#include<set>

using namespace std;

int main()
{
    int i,n,t,j,k,l,m,maxi;
    cin>>t;
    string s,s2;
    for(i=0;i<t;i++)
    {
        map<string,int> mp;
        map<string,int>::iterator it;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>s;
            set<string> has;
            for(k=0;k<s.length();k++)
            {
                for(l=0;l<s.length();l++)
                {
                    s2="";
                    for(m=k;m<=l;m++)
                    {
                        s2=s2+s[m];
                    }
                    if(has.count(s2)==0)
                    {
                        it=mp.find(s2);
                        if(it!=mp.end())
                        {
                            it->second=it->second+1;
                        }
                        else
                        {
                            mp.insert(make_pair(s2,1));
                        }
                        has.insert(s2);
                    }
                }
            }
        }
        s2="";
        maxi=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            //cout<<it->first<<" "<<it->second<<"\n";
            if(it->second==n)
            {
                if(it->first.length()>maxi)
                {
                    maxi=it->first.length();
                    s2=it->first;
                }
            }
        }
        cout<<s2<<"\n";
    }
    return 0;
}
