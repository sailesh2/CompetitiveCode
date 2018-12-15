#include<stdio.h>
#include<iostream>
#include<set>

using namespace std;

int main()
{
    int i,x,k,n;
    cin>>n;
    cin>>k;
    long long int sm=0,ctr=0;
    set<long long int> st;
    st.insert(0);
    for(i=0;i<n;i++)
    {
        cin>>x;
        sm=sm+x;
        if(st.count(sm-k)>0)
            ctr++;
        st.insert(sm);
    }
    cout<<ctr;
    return 0;
}
