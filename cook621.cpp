#include<stdio.h>
#include<iostream>
#include<set>
#include<string.h>
#include<vector>

using namespace std;

int main()
{
    int i,t,j,n,m,k,l;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        vector<string> v;
        set<string> st;
        cin>>n>>m;
        for(j=0;j<n;j++)
        {
            cin>>s;
            v.push_back(s);
        }
        for(j=0;j<m;j++)
        {
            cin>>k;
            for(l=0;l<k;l++)
            {
                cin>>s;
                st.insert(s);
            }
        }
        for(j=0;j<n;j++)
        {
            if(st.count(v[j])==0)
                cout<<"NO ";
            else
            cout<<"YES ";
        }
        cout<<"\n";
    }
    return 0;
}
