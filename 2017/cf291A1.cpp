#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    int a,ctr=1;
    cin>>n;
    vector<int> digs;
    while(n>0){
        a=n%10;
        a=min(a,9-a);
        if(a==0 && n/10<=0){
            a=n%10;
        }
        n=n/10;
        digs.push_back(a);
    }
    long long int ans=0,p=1;
    for(int i=0;i<digs.size();i++){
        ans=ans+digs[i]*p;
        p=p*10;
    }
    cout<<ans;
    return 0;
}
