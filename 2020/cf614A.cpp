#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,s,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>s>>k;
        int a;
        set<int> stairs;
        for(int j=0;j<k;j++){
            cin>>a;
            stairs.insert(a);
        }
        int mini=1000000009;
        for(int i=s;i<=n;i++){
            if(stairs.count(i)==0){
                mini=min(mini,i-s);
                break;
            }
        }
        for(int i=s;i>=1;i--){
            if(stairs.count(i)==0){
                mini=min(mini,s-i);
                break;
            }
        }
        cout<<mini<<"\n";
    }
    return 0;
}
