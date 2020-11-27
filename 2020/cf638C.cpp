#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int n,k;
    cin>>t;
    string s;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        cin>>s;
        sort(s.begin(),s.end());
        if(s[k-1]>s[0]){
            cout<<s[k-1]<<"\n";
        }else{
            int cnt=0;
            for(int j=k;j<n;j++){
                if(s[j]!=s[k]){
                    cnt=1;
                    break;
                }
            }
            string ans="";
            ans.push_back(s[k-1]);

            if(cnt==0){


                for(int j=0;j<((n-k)/k);j++){
                    ans.push_back(s[n-1]);
                }
                if((n-k)%k!=0)
                    ans.push_back(s[n-1]);
                cout<<ans<<"\n";
            }else{
                for(int j=k;j<n;j++){
                    ans.push_back(s[j]);
                }
                cout<<ans<<"\n";

            }
        }
    }
    return 0;
}
