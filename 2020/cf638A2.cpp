#include<bits/stdc++.h>

using namespace std;

int power[31];

long long int dp[32];
void setup(){
    power[0]=1;
    for(int i=1;i<=30;i++){
        power[i]=power[i-1]*2;
    }


    for(long long int i=0;i<=31;i++){
        dp[i]=-1;
    }

}
int mini;
void minimize(int index, int n, int ctr, int sum){
    //if(index==n+1){
        if(ctr==n/2){
                //cout<<sum;
            mini=min(mini,abs(2*(power[n]-1-sum)));
            return;
        }

    //}

    if(index>n)
        return;

    if(ctr>n/2)
        return;

    minimize(index+1,n,ctr+1,sum+power[index]);
    minimize(index+1,n,ctr,sum);
}

int main(){
    int t;
    cin>>t;
    setup();
    int n;
    for(int i=0;i<t;i++){
        cin>>n;
        mini=1000000000;
        if(dp[n]==-1){
            minimize(1,n,0,0);
            dp[n]=mini;
            cout<<mini<<"\n";
        }else{
            cout<<dp[n]<<"\n";
        }
    }
    return 0;
}
