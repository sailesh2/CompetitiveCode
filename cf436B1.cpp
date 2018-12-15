#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int maxi=0,ctr;
    set<int> st;
    for(int i=0;i<n;i++){
        if(s[i]<='Z' && s[i]>='A'){
            ctr=st.size();
            maxi=max(maxi,ctr);
            st.clear();
        } else{
            st.insert((int)(s[i]-'a'));
        }
    }
    ctr=st.size();
    maxi=max(maxi,ctr);
    cout<<maxi;
    return 0;
}
