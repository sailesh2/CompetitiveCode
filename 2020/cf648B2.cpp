#include<bits/stdc++.h>

using namespace std;

bool isSort(pair<int,int>* p, int n){
    pair<int,int> p2[n];
    for(int i=0;i<n;i++)
        p2[i]=p[i];
    sort(p,p+n);

    int z=0,o=0;
    for(int i=0;i<n;i++){
        if(p2[i].first!=p[i].first){
            if(p2[i].second==0)
                z++;
            else
                o++;
        }
    }

    return abs(z-o)<=1;
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
