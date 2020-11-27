#include<bits/stdc++.h>

using namespace std;

bool isSort(pair<int,int>* p, int n){
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(p[i].first>p[i+1].first){
            cnt=1;
            break;
        }
    }

    if(cnt==0)
        return true;

    for(int i=0;i<n-1;i++){
        if(p[i].second!=p[i+1].second)
            return true;
    }

    return false;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int a[n],b;
        pair<int,int> p[n];;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<n;j++){
            cin>>b;
            p[j]=make_pair(a[j],b);
        }

        if(isSort(p,n)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
