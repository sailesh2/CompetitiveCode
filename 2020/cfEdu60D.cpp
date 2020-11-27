#include<bits/stdc++.h>

using namespace std;
long long int n,m;
long long int mod=1000000007;
long long int dp[100005];

void clearDP(){
    for(int i=0;i<n+1;i++)
        dp[i]=-1;
}

long long int countMarblesDP(int remaining){
    if(remaining<=0)
        return 0;

    return countMarblesDP(remaining-1) + countMarblesDP(remaining-m);
}

int main(){
    cin>>n>>m;
    clearDP();
    cout<<countMarblesDP(n);
    return 0;
}
