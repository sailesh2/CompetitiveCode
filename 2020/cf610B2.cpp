#include<bits/stdc++.h>

using namespace std;

vector<int> totSm;

bool isPossible(int st, int en, vector<int> v, int p){
    if(st==0)
        return v[en]<=p;
    return (v[en] - v[st-1])<=p;
}

int binSear(int st, int p, vector<int> v){
    int ctr=1;
    int save=-1;
    int save2=-1;
int len=v.size();
    while(1){
        while(st+save+ctr<len && isPossible(st,st+save+ctr,v,p)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return st+save;
}

vector<int> reverseVector(vector<int> v){
    vector<int> vRev;
    for(int i=v.size()-1;i>=0;i--)
        vRev.push_back(v[i]);
    return vRev;
}

int left(int n, int p){
  int ctr=1;
    int save=-1;
    int save2=-1;
    while(1){
        while(save+ctr<=n && isPossible(0,save+ctr,totSm,p)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;5
        }
        save=save2;
        ctr=1;
    }
    return save+1;
}

int maxGoods(int* arr, int n, int p, int k){
    int maxi=0;
    for(int i=1;i<=k;i++){
        int j=n-i;

        vector<int> sm;
        vector<int> v;
        int cumsl=0;
        while(j>=0){
            v.push_back(j);
            j=j-k;
        }
        v=reverseVector(v);
        for(int st=0;st<v.size();st++){

            cumsl=cumsl+arr[v[st]];
            sm.push_back(cumsl);
        }
        for(int st=0;st<v.size();st++){

            int lt=binSear(st,p,sm);
            if(lt>=st){
                int am=st-1>=0?p-(sm[lt]-sm[st-1]):p-sm[lt];
                maxi=max(maxi,v[lt]-v[st] + (v[st]+1>=k?k + left(v[st]-k,am):1+left(v[st]-1,am)));
            }
        }
    }

    return maxi;
}

int main(){
    int t,n,p,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>p>>k;
        int arr[n];
        for(int j=0;j<n;j++)
            cin>>arr[j];
        sort(arr,arr+n);
        int cumlSm=0;
        for(int j=0;j<n;j++){
            cumlSm=cumlSm+arr[j];
            totSm.push_back(cumlSm);
        }
        cout<<maxGoods(arr,n,p,k)<<"\n";
    }
    return 0;
}
