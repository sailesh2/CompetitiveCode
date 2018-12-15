#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ctr=0;
    int u,v;
    set<pair<int,int> > st;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        st.insert(make_pair(u,v));
    }
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        if(st.count(make_pair(u,v))>0 ||st.count(make_pair(v,u))>0)
            ctr++;
    }
    cout<<ctr;
    return 0;
}
