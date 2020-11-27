#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        int cnt=0;
        sort(s.begin(),s.end());
        for(int j=0;j<s.length()-1;j++){
            if(s[j+1]!=s[j]+1){
                cnt=1;
                break;
            }
        }
        if(cnt==1)
        {
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
    return 0;
}
