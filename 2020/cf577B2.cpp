#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    set<int> st;
    set<int>::iterator stIt;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(st.count(arr[i])>0){
            st.erase(st.find(arr[i]));
        }else{
            st.insert(arr[i]);
        }
    }

    int cnt=0;

    while(st.size()>0){
        stIt = st.begin();
        int f=*stIt;
        if(st.size()==1){
            if(f>0)
                cnt=1;
            break;
        }
        stIt++;
        int sec=*stIt;
        stIt=st.find(f+sec);
        if(stIt==st.end()){
            cnt=1;
            break;
        }else{
            st.erase(st.find(f));
            st.erase(st.find(sec));
            st.erase(st.find(f+sec));
        }
    }
    if(cnt==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
