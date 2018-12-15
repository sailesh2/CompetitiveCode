#include<bits/stdc++.h>

using namespace std;

int main(){
    set<pair<int,int> > st;
    set<pair<int,int> >::iterator stIt;
    int n,u,v;
    cin>>n;
    vector<int> tree[n+1];
    int val[n+1];
    int offNode[n+1];
    for(int i=1;i<=n;i++){
        cin>>val[i];
        offNode[i]=0;
        st.insert(make_pair(val[i],i));
    }
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int cnt,offline=0,root,next,nextnext,maxi=-1000000050;
    while(offline<n){
        stIt=st.end();
        cnt=0;
        while(cnt==0){
            stIt--;
            root=stIt->second;
            if(offline==0){
                cnt=1;
                break;
            }
            for(int i=0;i<tree[root].size();i++){
                next=tree[root][i];
                if(offNode[next]==1){
                    cnt=1;
                    break;
                }
            }
        }
        maxi=max(maxi,stIt->first);

        for(int i=0;i<tree[root].size();i++){
            next=tree[root][i];
            if(offNode[next]==0){
                stIt=st.find(make_pair(val[next],next));
                if(stIt!=st.end()){
                    st.erase(stIt);
                    val[next]++;
                    st.insert(make_pair(val[next],next));
                }
                for(int j=0;j<tree[next].size();j++){
                    nextnext=tree[next][j];
                    if(nextnext!=root && offNode[nextnext]==0){
                        stIt=st.find(make_pair(val[nextnext],nextnext));
                        if(stIt!=st.end()){
                            st.erase(stIt);
                            val[nextnext]++;
                            st.insert(make_pair(val[nextnext],nextnext));
                        }
                    }
                }
            }
        }
        offNode[root]=1;
        stIt=st.find(make_pair(val[root],root));
        st.erase(stIt);
        offline++;
    }
    cout<<maxi;
    return 0;
}
