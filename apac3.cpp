#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
#include<iterator>

using namespace std;

int fun(string fin,map<string,string>,map<string,int>);
int main()
{
    int i,j,n,t;
    string str1,str2,fin;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        map<string,string> v;

        map<string,int> vsave;
        for(j=0;j<n;j++)
        {
            cin>>str1;
            cin>>str2;
            v.insert(make_pair(str1,str2));
            vsave.insert(make_pair(str1,-1));

        }
        map<string,string>::iterator it;
        for(it=v.begin();it!=v.end();it++)
        {
          //  cout<<it->first<<" ";
        }
        //cout<<"\n";
        string ans;
        for(it=v.begin();it!=v.end();it++)
        {
            fin=it->second;
          //  cout<<fin<<" ";
            int ctr=fun(fin,v,vsave)+1;
        //    cout<<ctr;
            if(ctr==n)
            {
                ans=it->first;
                break;
            }
        }
        cout<<"Case #"<<i+1<<": ";
        it=v.find(ans);
        while(it!=v.end())
        {
            cout<<it->first<<"-"<<it->second<<" ";
            it=v.find(it->second);
        }
        cout<<"\n";
    }
    return 0;
}
int fun(string fin,map<string,string> v,map<string,int> vsave)
{
    map<string,int>::iterator itsave;
    itsave=vsave.find(fin);
    if(itsave==vsave.end())
        return 0;
    if(itsave->second==-1)
    {
        string s=(v.find(fin))->second;
        itsave->second=fun(s,v,vsave)+1;
    }
    return itsave->second;
}
