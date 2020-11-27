#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int n,mini,maxi,l,r;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>l>>r;
            if(j==0){
                mini=r;
                maxi=l;
            }else{
                mini=min(mini,r);
                maxi=max(maxi,l);
            }
        }
        cout<<max(0,maxi-mini)<<"\n";
    }
    return 0;
}
