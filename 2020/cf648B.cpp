#include<bits/stdc++.h>

using namespace std;

bool isSort(pair<int,int>* p, int n){

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].first>p[j].first){
                if(p[i].second==p[j].second)
                    return false;

                pair<int,int> temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;

            }
        }
    }

    return true;
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
