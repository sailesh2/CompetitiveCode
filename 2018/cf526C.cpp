#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    long long int sm=0,prev=0;
    int cnt=0;
    long long int mod=1000000007;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='a'){
            if(cnt==0){
                sm=prev;
                cnt=1;
            }
            sm=(sm+prev+1)%mod;
        }
        if(s[i]=='b'){
            if(cnt==1){
                cnt=0;
                prev=sm;
            }
        }
    }
    cout<<sm;
    return 0;
}
