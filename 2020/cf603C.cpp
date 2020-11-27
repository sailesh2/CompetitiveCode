#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        set<int> st;
        vector<int> v;
        v.push_back(0);
        st.insert(0);
        for(int j=1;j*j<=n;j++){
            int f=n/j;
            int s=n/f;
            if(st.count(f)==0){
                v.push_back(f);
                st.insert(f);
            }
            if(st.count(s)==0){
                v.push_back(s);
                st.insert(s);
            }
        }
        sort(v.begin(),v.end());
        cout<<v.size()<<"\n";
        for(int j=0;j<v.size();j++){
            cout<<v[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
