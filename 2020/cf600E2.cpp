#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,m,x,s;
    cin>>n>>m;
    long long int taken[100005]={0};
    long long int who[100005]={0};
    for(long long int i=0;i<n;i++){
        cin>>x>>s;
        for(long long int j=max(0LL,x-s);j<=min(x+s,m);j++){

            who[j]=max(who[j],x+s);

            taken[j]=1;
        }
    }
    long long int sm=0;
    long long int ctr=0;
    set<long long int> st;
    set<long long int>::iterator stIt;

    for(long long int i=1;i<=m;i++){
        if(taken[i]==0){
            ctr++;
        }else{
            if(ctr>0LL){
                st.insert(ctr);
                ctr=0;
            }
        }
    }
    if(ctr>0LL)
        st.insert(ctr);

    while(st.size()>0){
        stIt = st.end();
        stIt--;
        long long int v=*stIt;
        sm=sm+v;
        st.erase(stIt);
        while(st.size()>0){
            stIt=st.end();
            stIt--;

            if(v-*stIt < 0){
                break;
            }
            v=v-*stIt;
            st.erase(stIt);
        }
        if(st.size()==0){
            sm=sm+v;
            break;
        }
        if(v>0){
            st.insert(v);
        }
    }
    cout<<sm;
    return 0;
}
