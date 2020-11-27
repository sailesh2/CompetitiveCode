#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        int cnt=0,ctr=0,c=0;
        for(int j=0;j<s.length();j++){
            if(s[j]=='1'){
                if(cnt==1)
                c=c+ctr;
                cnt=1;
                ctr=0;
            }else{
                ctr++;
            }
        }
        cout<<c<<"\n";
    }
    return 0;
}
