#include<stdio.h>
#include<iostream>
#include<set>

using namespace std;

int main()
{
    int n,q,i,x;
    cin>>n>>q;
    set<int> st;
    for(i=0;i<n;i++)
    {
        cin>>x;
        st.insert(x);
    }
    for(i=0;i<q;i++)
    {
        cin>>x;
        if(st.count(x)>0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
