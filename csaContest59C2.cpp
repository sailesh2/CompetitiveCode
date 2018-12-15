#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    char arr[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }
    vector<int> v,v1;
    char miniC;
    string ans="";
    v.push_back(0);
    for(int i=0;i<n;i++){
        if(v.size()==0)
            break;
        for(int j=0;j<v.size();j++){
            if(j==0)
                miniC=arr[i][v[j]];
            else
                miniC=min(miniC,arr[i][v[j]]);
        }
        ans=ans+miniC;
        if(i!=n-1){
            v1.clear();
            int has[3005]={0};
            for(int j=0;j<v.size();j++){
                if(arr[i][v[j]]==miniC){
                    if(has[v[j]]==0){
                        v1.push_back(v[j]);
                        has[v[j]]=1;
                    }
                    if(has[v[j]+1]==0){
                        if(v[j]+1<=i+1){
                            v1.push_back(v[j]+1);
                            has[v[j]+1]=1;
                        }
                    }
                }
            }
            v=v1;
        }
    }
    cout<<ans;
    return 0;
}
