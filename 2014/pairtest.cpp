#include<stdio.h>
#include<iostream>
#include<iterator>
#include<set>

using namespace std;

int main()
{
    set< pair<int,int> > st;
    st.insert(make_pair(10,20));

    st.insert(make_pair(10,40));

    st.insert(make_pair(40,50));
    set< pair<int,int> >::iterator it=st.find(make_pair(10,50));
    if(it==st.end())
        cout<<"sdgf";
    cout<<it->second;
    return 0;
}
