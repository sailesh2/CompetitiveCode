#include<bits/stdc++.h>

using namespace std;

bool fun(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    set<int> tapes;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<"1";
    }else{
        pair<int,int> diff[n-1];
        for(int i=0;i<n-1;i++){
            diff[i]=make_pair(arr[i+1]-arr[i],i+1);
        }

        sort(diff,diff+n-1,fun);
        int ctr=0;
        for(int i=0;i<n-1 && ctr<k-1;i++){
            tapes.insert(diff[i].second);
            ctr++;
        }
        long long int ans=0,en,st=arr[0];
        for(int i=0;i<n;i++){
            if(tapes.count(i)>0){
                //cout<<i<<"\n";
                ans=ans+en-st+1;
                st=arr[i];
                en=st;
            }else{
                en=arr[i];
            }
        }
        cout<<ans+en-st+1;
    }

    return 0;
}
