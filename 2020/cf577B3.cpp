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
    vector<int> v;
    for(stIt=st.begin();stIt!=st.end();stIt++){
        v.push_back(*stIt);
    }
    int m=v.size();
    if(m%3!=0){
        cnt=1;
    }else{
        m=2*(m/3);
        long long int s=0;
        for(int i=0;i<m;i++){
            s=s+v[i];
        }
        long long int sl=0;
        for(int i=m;i<v.size();i++){
            sl=sl+v[i];
        }
        if(s!=sl){
            cnt=1;
        }
    }

    if(cnt==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
