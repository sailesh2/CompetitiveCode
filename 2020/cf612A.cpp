#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,k;
    cin>>t;
    string s;
    for(int i=0;i<t;i++){
        cin>>k;
        cin>>s;
        int maxi=0,ctr=0,cnt=0;
        for(int j=0;j<k;j++){
            if(s[j]=='A'){
                cnt=1;
                maxi=max(maxi,ctr);
                ctr=0;
            }else{
                if(cnt==1){
                    ctr++;
                }
            }
        }
        maxi=max(maxi,ctr);
        cout<<maxi<<"\n";
    }
    return 0;
}
