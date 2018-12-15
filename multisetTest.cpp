#include<stdio.h>
#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int main()
{
    multiset<pair<pair<int,float>,int> > st;
    multiset<pair<pair<int,float>,int> >::iterator it,it2;



    st.insert(make_pair(make_pair(20,(float)1/4),5));
    st.insert(make_pair(make_pair(20,1),3));

    st.insert(make_pair(make_pair(20,1),4));

    st.insert(make_pair(make_pair(10,(float)1/2),2));
    st.insert(make_pair(make_pair(10,(float)1/1),1));



    for(it=st.begin();it!=st.end();it++)
    {
        cout<<(it->first).first<<" "<<(it->first).second<<" "<<(it->second)<<"\n";


    }
    return 0;
}
