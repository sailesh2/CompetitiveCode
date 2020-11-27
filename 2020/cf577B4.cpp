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
    int ctr=0;
    map<int,int> mp;
    map<int,int>::iterator mpIt;
    for(stIt=st.begin();stIt!=st.end();stIt++){
        v.push_back(*stIt);
        mp.insert(make_pair(v[ctr],ctr));
        ctr++;
    }
    int m=v.size();
    int has[100005]={0};
    long long int s=0;
    for(int i=0;i<m;i++){
        if(has[i]==0){
            if(s<=v[i])
            s=s+v[i];
            else
            s=s-v[i];
            mpIt=mp.find(s);
            int ind=-1;
            if(mpIt!=mp.end()){
                ind=mpIt->second;
            }
            if(ind!=-1 && ind>i){
                has[ind]=1;
                s=0;
            }
        }
    }


    if(s==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
