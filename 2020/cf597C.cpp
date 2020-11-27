#include<bits/stdc++.h>

using namespace std;

long long int mod=1000000007;

long long int dp[100005];

string s;

void clearDP(){
    int n=s.length();
    for(int i=0;i<=n;i++)
        dp[i]=-1;
}

bool isPossible(){
    for(int i=0;i<s.length();i++){
        if(s[i]=='w' || s[i]=='m')
            return false;
    }
    return true;
}

bool isCorrupt(int index){
    bool w =s[index]=='u' && index+1<s.length() && s[index+1]=='u';
    bool m =s[index]=='n' && index+1<s.length() && s[index+1]=='n';

    return w || m;
}

long long int noOfInscribe(int index){
    if(index>=s.length())
        return 1;

    long long int v=0;
    if(isCorrupt(index)){
        if(dp[index+1]==-1)
            v=noOfInscribe(index+1);
        else
            v=dp[index+1];

        if(dp[index+2]==-1)
            v=(v+noOfInscribe(index+2))%mod;
        else
            v=(v+dp[index+2])%mod;
    }else{
        if(dp[index+1]==-1)
            v=noOfInscribe(index+1);
        else
            v=dp[index+1];
    }

    dp[index]=v;
    return v;
}

int main(){
    cin>>s;
    if(isPossible()){
        clearDP();
        cout<<noOfInscribe(0);
    }else{
        cout<<"0";
    }
    return 0;
}
