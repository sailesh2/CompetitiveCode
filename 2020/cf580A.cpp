#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n;
    int arr[n];
    set<int> st;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        st.insert(arr[i]);
    }

    cin>>m;
    int brr[m];
    for(int i=0;i<m;i++){
        cin>>brr[i];
        st.insert(brr[i]);
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(st.count(arr[i]+brr[j])==0){
                cnt=1;
                cout<<arr[i]<<" "<<brr[j];
                break;
            }
        }
        if(cnt==1)
            break;
    }
    return 0;
}
