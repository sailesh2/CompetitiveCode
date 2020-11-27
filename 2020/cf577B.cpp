#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    multiset<int> st;
    multiset<int>::iterator stIt;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        st.insert(arr[i]);
    }

    int cnt=0;
    while(st.size()>0){
        stIt=st.begin();
        int f=*stIt;
        if(st.size()==1){
            if(f>0)
            cnt=1;
            break;
        }

        st.erase(stIt);

        stIt=st.end();
        stIt--;
        int l=*stIt;
        st.erase(stIt);
        l=l-f;
        if(l>0){
            st.insert(l);
        }
    }

    if(cnt==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
