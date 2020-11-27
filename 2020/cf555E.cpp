#include<bits/stdc++.h>

using namespace std;
int mapCtr[200005]={0};

int n;

int main(){
    cin>>n;
    int arr[n];
    int brr[n];
    set<int> st;
    set<int>::iterator stIt;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        cin>>brr[i];
        st.insert(brr[i]);
        mapCtr[brr[i]]++;
    }

    int v,v2;

    int crr[n];
    for(int i=0;i<n;i++){
        stIt=st.lower_bound(n-arr[i]);
        if(stIt==st.end()){
            stIt=st.lower_bound(0);
            v2=*stIt;

            mapCtr[v2]--;
            if(mapCtr[v2]==0)
                st.erase(v2);
            crr[i]=(arr[i]+v2)%n;


        }else{
            v=*stIt;

            stIt=st.lower_bound(0);
            v2=*stIt;

            if((v+arr[i])%n < (v2+arr[i])%n){
                mapCtr[v]--;
                if(mapCtr[v]==0)
                    st.erase(v);
                crr[i]=(arr[i]+v)%n;
            }else{
                mapCtr[v2]--;
                if(mapCtr[v2]==0)
                    st.erase(v2);
                crr[i]=(arr[i]+v2)%n;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<crr[i]<<" ";
    }
    return 0;
}
