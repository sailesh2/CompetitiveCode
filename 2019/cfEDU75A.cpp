#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string s;
    cin>>t;
    for(int j=0;j<t;j++){
        cin>>s;
        string ans="";
        int c=1;
        int has[300]={0};
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                c++;
            }else{
                if(c%2!=0){
                    if(has[(int)s[i]]==0){
                        has[(int)s[i]]=1;
                        ans.push_back(s[i]);
                    }
                }
                c=1;
            }
        }

        if(c%2!=0){
            if(has[(int)s[s.length()-1]]==0)
            ans.push_back(s[s.length()-1]);
        }
        sort(ans.begin(),ans.end());
        cout<<ans<<"\n";
    }
    return 0;
}
