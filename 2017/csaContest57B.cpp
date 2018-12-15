#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int maxi=0,cnt=0,ctr=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            ctr++;
        }else{
            maxi=max(maxi,ctr);
            cnt=1;
            ctr=0;
        }
    }
    maxi=max(maxi,ctr);
    if(cnt==0){
        long long int p=((long long int)n)*((long long int)k);
        cout<<p;
    }else{
        if(k>1){
            ctr=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='0'){
                    ctr++;
                }else{
                    break;
                }
            }
            for(int i=s.length()-1;i>=0;i--){
                if(s[i]=='0'){
                    ctr++;
                }else{
                    break;
                }
            }
            maxi=max(maxi,ctr);
        }
        cout<<maxi;
    }
    return 0;
}
