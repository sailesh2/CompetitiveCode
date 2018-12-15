#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> st;
    int arr[n],brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        st.insert(arr[i]);
    }

    for(int i=0;i<n;i++){
        cin>>brr[i];
        st.insert(brr[i]);
    }
    int ctr=0,c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c=arr[i]^brr[j];
            if(st.count(c)>0)
                ctr++;
        }
    }
    if(ctr%2==0){
        cout<<"Karen";
    }else{
        cout<<"Koyomi";
    }
    return 0;
}
