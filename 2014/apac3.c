#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<pair>
#include<iterator>

using namespace std;

int main()
{
    int i,i,j,n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        vector< pair<string,string> > v;
        for(j=0;j<n;j++)
        {
            cin>>str1;
            cin>>str2;
            v.push_back(make_pair(str1,str2));
        }
        vector< pair<string,string> >::iterator it;
        for(it=v.begin();it!=v.end();it++)
            cout<<it->first<<" "<<it->second<<"\n";
    }
    return 0;
}
