#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,t,v;
    cin>>n>>t;
    int arr[n];
    vector<int> st;
    map<int,int> mp;
    map<int,int>::iterator mpIt;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        v=0;
        mpIt=mp.find(arr[i]);
        if(mpIt!=mp.end()){
            v=mpIt->second;
            mp.erase(mpIt);
        }else{
            st.push_back(arr[i]);
        }
        mp.insert(make_pair(arr[i],v+1));
    }
    sort(st.begin(),st.end());
    int factorMap[t+1];
    for(int i=0;i<=t;i++){
        factorMap[i]=0;
    }
    int ctr;
    for(int i=0;i<st.size();i++){
        v=st[i];
        mpIt=mp.find(v);
        ctr=mpIt->second;
        for(int j=v;j<=t;j=j+v){
            factorMap[j]=factorMap[j]+ctr;
        }
    }
    int maxi=0,save=0;
    for(int i=1;i<=t;i++){
        if(factorMap[i]>maxi){
            maxi=factorMap[i];
            save=i;
        }else if(factorMap[i]==maxi){
            if(i<save){
                save=i;
            }
        }
    }
    if(maxi==0){
        cout<<maxi<<" "<<maxi;
    }else
        cout<<maxi<<" "<<t/save;
    return 0;
}
