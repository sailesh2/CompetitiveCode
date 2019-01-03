#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    long long int p;
    string s;
    cin>>n;
    cin>>s;
    int save=-1,save2=-1;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            if(save==-1){
                save=i;
                save2=save+1;
            }
            else
            save2=i+1;
        }
    }
    long long int mod = 998244353 ;
    if(s[0]!=s[n-1]){
        p=(save+1+n-save2+1+mod)%mod;
    }else{
        p=((save+2)*(n-save2+1))%mod;
    }
    cout<<p;
    return 0;
}
