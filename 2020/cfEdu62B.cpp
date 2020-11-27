#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int n;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cin>>s;
        int ctrL=0,ctrR=0;
        for(int j=0;j<n-1;j++){
            if(s[j]=='<'){
                ctrL++;
            }else{
                break;
            }
        }

        for(int j=n-1;j>0;j--){
            if(s[j]=='>'){
                ctrR++;
            }else{
                break;
            }
        }

        cout<<min(ctrL,ctrR)<<"\n";
    }
    return 0;
}
