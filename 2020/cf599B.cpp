#include<bits/stdc++.h>

using namespace std;

int main(){
    int q,n;
    string s,t;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n;
        cin>>s>>t;
        int ctr=0,cnt=0;
        int save[2];
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                if(ctr==2){
                    cnt=1;
                    break;
                }
                save[ctr++]=i;

            }
        }
        if(ctr==1)
            cnt=1;
        if(cnt==1){
            cout<<"NO\n";
        }else{
            if(ctr==0 || (ctr==2 && s[save[0]]==s[save[1]] && t[save[0]]==t[save[1]])){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}
