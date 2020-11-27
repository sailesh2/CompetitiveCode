#include<bits/stdc++.h>

using namespace std;
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

bool possible(int a, int b, int* has){
    int v1=min(a,b);
    int v2=max(a,b);

    while(v1!=0){
        if(v1==v2)
            return true;
        v1=has[v1];
    }
    return false;
}

int main(){
    int t,n,m,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        pair<int,int> arr[n];
        int p[m];
        int orig[n];
        int has[200]={0};
        for(int j=0;j<n;j++){
            cin>>x;
            orig[j]=x;
            arr[j]=make_pair(x,j);
        }
        for(int j=0;j<m;j++){
            cin>>p[j];
            has[p[j]]=p[j]+1;
        }
        sort(arr,arr+n,comp);
        int cnt=0;
        for(int j=0;j<n;j++){
            if(orig[j]!=arr[j].first){
                if(!possible(j+1,1+arr[j].second,has)){
                    cnt=1;
                    break;
                }
            }
        }
        if(cnt==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    return 0;
}
