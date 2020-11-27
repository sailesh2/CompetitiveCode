#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int x,ctr=0;
        set<int> st;
        for(int j=0;j<n;j++){
            cin>>x;
            if(st.count(x)==0){
                st.insert(x);
                ctr++;
            }
        }
        cout<<ctr<<"\n";
    }
    return 0;
}
