#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> st;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        st.insert(arr[i]);
    }
    int save=0;
    int sz=st.size();
    int has[200005]={0};
    for(int i=n-1;i>=0;i--){
        if(has[arr[i]]==0){
            has[arr[i]]=1;
            sz--;
            if(sz==0){
                save=arr[i];
                break;
            }
        }
    }
    cout<<save;
    return 0;
}
