#include<bits/stdc++.h>

using namespace std;

int getGreatestPower(int n){

    int ctr=0;
    while(n>0){
        n=n/2;
        ctr++;
    }
    return ctr;
}

int main(){
    int x;
    cin>>x;

    set<int> ps;
    int p=1;
    ps.insert(p-1);
    int dp[32];
    dp[0]=p-1;
    for(int i=1;i<=30;i++){
        p=p*2;
        dp[i]=p-1;
        ps.insert(p-1);
    }

    int ctr=0;
    int y;
    vector<int> ans;
    while(1){
        if(ps.count(x)>0){
            break;
        }
        y=getGreatestPower(x);
        x=x^dp[y];
        ans.push_back(y);
        ctr++;

        if(ps.count(x)>0){
            break;
        }
        x++;
        ctr++;
    }

    cout<<ctr<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
