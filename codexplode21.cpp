#include<stdio.h>
#include<iostream>
#include<iterator>
#include<set>

using namespace std;

int main()
{
    int i,j,n,t,cnt;
    long long int p,sm,x;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sm=0;
        cnt=0;
        set<long long int> st;
        cin>>n>>p;
        for(j=0;j<n;j++)
        {
            cin>>x;
            sm=sm+x;
            if(sm==p)
            {
                cnt=1;
                cout<<"Yes\n";
                break;
            }
            if(st.find(sm-p)!=st.end())
            {
                cnt=1;
                cout<<"Yes\n";
                break;
            }
            st.insert(sm);
        }
        if(cnt==0)
            cout<<"No\n";
    }
    return 0;
}
