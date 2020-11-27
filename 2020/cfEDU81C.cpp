#include<bits/stdc++.h>

using namespace std;

int close(string s, string t){
    int dp[1+s.length()][26];
    for(char j='a';j<='z';j++){
        dp[s.length()][j-'a']=-1;
    }
    for(int i=s.length()-1;i>=0;i--){
        for(char j='a';j<='z';j++){
            dp[i][j-'a']=dp[i+1][j-'a'];

        }
        dp[i][s[i]-'a']=i;
    }
    int f=0;
    int ctr=0;
    for(int i=0;i<t.length();i++){
        if(dp[f][t[i]-'a']==-1)
        return -1;
        while(i<t.length()){
            f=dp[f][t[i]-'a'];
            if(f==-1){
                f=0;
                ctr++;
                i--;
                break;
            }
            f++;
            i++;
        }
    }

    return ctr+1;
}

int main(){
    int n;
    string s,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>t;
        cout<<close(s,t)<<"\n";
    }
    return 0;
}
