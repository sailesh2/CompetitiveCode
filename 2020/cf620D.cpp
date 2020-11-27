#include<bits/stdc++.h>

using namespace std;

vector<int> minLIS(int n, string s){

    for(int i=0;i<n-1;i++){
        if(s[i]=='<'){
            if(cnt==1){
                cnt=0;
                save=i;
            }
        }else{
            if(cnt==0){
                for(int j=save;j<i;j++){
                    ans.push_back(ctr-(i-save)+(j-save));
                }

                cnt=1;
            }
        }
    }
}

int main(){
    int t,n;
    string s;
    cin>>t;
    vector<int> v1;
    for(int i=0;i<t;i++){
        cin>>n>>s;
        v1=minLIS(n,s);
        for(int j=0;j<n;j++){
            cout<<v1[j]<<" ";
        }
        cout<<"\n";
        v1=maxLIS(n,s);
        for(int j=0;j<n;j++){
            cout<<v1[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
