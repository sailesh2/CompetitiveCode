#include<bits/stdc++.h>

using namespace std;

long long int mod = 1000000007;

long long int hashed(string s){
    long long int hasV=0;
    for(int i=0;i<s.length();i++){
        hasV = (293*hasV + s[i])%mod;
    }
    return hasV;
}

long long int prr[600005];
void storeP(){
    prr[0]=1;
    for(int i=1;i<600005;i++){
        prr[i]=(prr[i-1]*293)%mod;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    char ch;
    int ans;
    long long int hasV;
    set<long long int> has;
    set<long long int>::iterator hasIt;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        hasV=hashed(s);
        has.insert(hasV);
    }
    long long int check;
    storeP();
    long long int len;

    for(int i=0;i<m;i++){
        cin>>s;
        ans=0;
        hasV=hashed(s);
        len=s.length()-1;
        for(int j=0;j<s.length();j++){
            if(ans==1)
                break;
            ch=s[j];
            if(ch!='a'){
                check = ((hasV+('a'-ch)*prr[len-j])%mod+mod)%mod;
                ans=has.count(check);
                if(ans==1)
                    break;
            }
            if(ch!='b'){
                check = ((hasV+('b'-ch)*prr[len-j])%mod+mod)%mod;
                ans=has.count(check);
                if(ans==1)
                    break;
            }
            if(ch!='c'){
                check = ((hasV+('c'-ch)*prr[len-j])%mod+mod)%mod;
                ans=has.count(check);
                if(ans==1)
                    break;
            }
        }
        if(ans==0){
            cout<<"NO\n";
        } else{
            cout<<"YES\n";
        }
    }
}
