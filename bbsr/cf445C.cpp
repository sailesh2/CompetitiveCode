#include<bits/stdc++.h>

using namespace std;
vector<char> commands;
int mod=1000000007;
int dp[5005][5005][2];
void clearDP(){
    for(int i=0;i<5005;i++){
        for(int j=0;j<5005;j++){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
}
int noOfSyntax(int pos,int indent,int type){
    long long int c=0;
    if(pos==commands.size())
        return 1;
    if(type==0){
        if(commands[pos]=='s'){
            if(dp[pos+1][indent][0]==-1)
                c=noOfSyntax(pos+1,indent,0)%mod;
            else
                c=dp[pos+1][indent][0]%mod;
            c=c%mod;
            if(indent-1>=0){
                for(int i=indent-1;i>=0;i--){
                    if(dp[pos+1][i][0]==-1)
                        c=(c+noOfSyntax(pos+1,i,0))%mod;
                    else
                        c=(c+dp[pos+1][i][0])%mod;
                }
            }
        }else{
            if(dp[pos+1][indent+1][1]==-1)
                c=noOfSyntax(pos+1,indent+1,1)%mod;
            else
                c=dp[pos+1][indent+1][1]%mod;
            c=c%mod;
            if(indent-1>=0){
                for(int i=indent-1;i>=0;i--){
                    if(dp[pos+1][i+1][1]==-1)
                        c=(c+noOfSyntax(pos+1,i+1,1))%mod;
                    else
                        c=(c+dp[pos+1][i+1][1])%mod;
                }
            }
        }
    }else {
        if(commands[pos]=='s'){
            if(dp[pos+1][indent][0]==-1)
                c=noOfSyntax(pos+1,indent,0)%mod;
            else
                c=dp[pos+1][indent][0]%mod;
        }else{
            if(dp[pos+1][indent+1][1]==-1)
                c=noOfSyntax(pos+1,indent+1,1)%mod;
            else
                c=dp[pos+1][indent+1][1]%mod;
        }
        c=c%mod;
    }
    dp[pos][indent][type]=c;
    return c;
}
int main(){
    int n;
    cin>>n;
    char ch;
    for(int i=0;i<n;i++){
        cin>>ch;
        commands.push_back(ch);
    }
    clearDP();
    cout<<noOfSyntax(0,0,0);
    return 0;
}
