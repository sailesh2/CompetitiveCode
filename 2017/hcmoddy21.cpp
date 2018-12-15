#include<bits/stdc++.h>

using namespace std;
vector<pair<int,int> > st;
int binSear(int cost){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<st.size() && st[save+ctr].first<=cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    if(save==-1)
        return -1;
    return st[save].second;
}

int main(){
    int n,x,j;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        j=st.size()-1;
        while(j>=0 && x<=st[j].first){
            st.pop_back();
            j=st.size()-1;
        }
        st.push_back(make_pair(x,i+1));
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>x;
        cout<<binSear(x)<<"\n";
    }
    return 0;

}
